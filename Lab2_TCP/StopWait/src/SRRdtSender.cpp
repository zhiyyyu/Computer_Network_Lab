//
// Created by narrow on 2021/10/25.
//

#include "SRRdtSender.h"

using namespace dzh;

SRRdtSender::SRRdtSender() {
    this->waiting_state = false;
    this->next_seqnum_to_send = 1;
    this->window_idx = 0;
    this->window_base = 1;

}

SRRdtSender::~SRRdtSender() {

}

bool SRRdtSender::getWaitingState() {
    return waiting_state;
}

Packet SRRdtSender::make_pkt(int nextseqnum, const Message &message) {
    Packet packet;
    packet.acknum = -1;
    packet.seqnum = nextseqnum;
    packet.checksum = 0;
    memcpy(packet.payload, message.data, sizeof(message.data));
    packet.checksum = pUtils->calculateCheckSum(packet);
    return packet;
}

bool SRRdtSender::send(const Message &message) {
    if(getWaitingState()){
        return false;
    }
    if(next_seqnum_to_send < window_base + WIN_LENGTH){
        // make packet
        window[window_idx] = make_pkt(next_seqnum_to_send, message);
        // send packet
        pUtils->printPacket("发送方发送报文", window[window_idx]);
        pns->sendToNetworkLayer(RECEIVER, window[window_idx]);
        pns->startTimer(SENDER, Configuration::TIME_OUT, window[window_idx].seqnum);

        window_idx++;
        if(window_idx == WIN_LENGTH){
            waiting_state = true;
            return true;
        }
        next_seqnum_to_send++;
        waiting_state = false;
        return true;
    } else{
        waiting_state = true;
        return false;
    }
}

void SRRdtSender::receive(const Packet &ackPkt) {
    checksum = pUtils->calculateCheckSum(ackPkt);
    if(checksum == ackPkt.checksum){
        if(ackPkt.acknum >= window_base && ackPkt.acknum < window_base + WIN_LENGTH){
            is_ack[ackPkt.acknum-window_base] = true;
            pns->stopTimer(SENDER, ackPkt.acknum);
            // base has acked
            if(ackPkt.acknum == window_base){
                pUtils->printPacket("收到base的ACK", ackPkt);
//            pns->stopTimer(SENDER, ackPkt.acknum);
                int idx = 0;
                while(is_ack[idx]) idx++;
                for(int i=0;i<WIN_LENGTH-idx && i<window_idx;i++){
                    window[i] = window[i+idx];
                    is_ack[i] = is_ack[i + idx];
                }
                for(int i=WIN_LENGTH-idx;i<window_idx;i++){
                    is_ack[i] = false;
                }
                window_idx -= idx;
                window_base += idx;
                waiting_state = false;
            } else{
//                pns->stopTimer(SENDER, ackPkt.acknum);//收到不是BASE的ACK，只停止时钟
            pUtils->printPacket("收到窗口内非base的ACK",ackPkt);
            }
        } else{
//            pns->stopTimer(SENDER,ackPkt.acknum);
            pUtils->printPacket("收到窗口之前报文的ACK",ackPkt);
        }
    } else{
        pUtils->printPacket("收到ACK包校验和出错",ackPkt);
    }
}

void SRRdtSender::timeoutHandler(int seqNum) {
    int idx = 0;
    while(window[idx].seqnum != seqNum) idx++;
    pns->stopTimer(SENDER, seqNum);
    pns->startTimer(SENDER, Configuration::TIME_OUT, seqNum);
    pns->sendToNetworkLayer(RECEIVER, window[idx]);
}

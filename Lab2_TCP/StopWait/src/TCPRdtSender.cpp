//
// Created by narrow on 2021/11/10.
//

#include "TCPRdtSender.h"

using namespace dzh;

TCPRdtSender::TCPRdtSender() {
    window_base = 1;
    next_seqnum_to_send = 1;
    waiting_state = false;
    window_idx = 0;
    resend_cnt = 0;
//    last_ack = -1;
}

TCPRdtSender::~TCPRdtSender() noexcept {

}

bool TCPRdtSender::getWaitingState() {
    return this->waiting_state;
}

Packet TCPRdtSender::make_pkt(int nextseqnum, const Message &message) {
    Packet packet;
    packet.acknum = -1;
    packet.seqnum = nextseqnum;
    packet.checksum = 0;
    memcpy(packet.payload, message.data, sizeof(message.data));
    packet.checksum = pUtils->calculateCheckSum(packet);
    return packet;
}

/**
 * get data from app layer, send to net layer
 * @param message
 * @return
 */
bool TCPRdtSender::send(const Message &message) {
    // window is not full
    if(next_seqnum_to_send < window_base + WIN_LENGTH){
        // make packet
        window[window_idx] = make_pkt(next_seqnum_to_send, message);
        // send packet
        pUtils->printPacket("发送方发送报文", window[window_idx]);
        pns->sendToNetworkLayer(RECEIVER, window[window_idx]);
        if(window_base == next_seqnum_to_send){
            pns->startTimer(SENDER, Configuration::TIME_OUT, window[window_idx].seqnum);
        }
        window_idx++;
        if(window_idx >= WIN_LENGTH){
            waiting_state = true;
        }
        next_seqnum_to_send++;
        return true;
    } else{ // failed to send, window is full , waiting for the ack
        waiting_state = true;
        return false;
    }
}

/**
 * get ack from net layer
 * @param ackPkt
 */
void TCPRdtSender::receive(const Packet &ackPkt) {
    // seqnum > base
//    if(window_idx > 0){
    // do rdt check
    checksum = pUtils->calculateCheckSum(ackPkt);
    if(checksum == ackPkt.checksum && ackPkt.acknum >= window_base){    // >= !!!
        int forward_num = ackPkt.acknum - window_base + 1;
        // reset base
        window_base = ackPkt.acknum + 1;
        if(window[0].seqnum == ackPkt.acknum){
            resend_cnt++;
            if(resend_cnt == 3){
                pns->stopTimer(SENDER,this->window[0].seqnum);
                pns->sendToNetworkLayer(RECEIVER,this->window[0]);//将第一个报文发送给接收方
                pUtils->printPacket("\n冗余ACK*4，快速重传当前窗口第一个报文",window[0]);
                pns->startTimer(SENDER,Configuration::TIME_OUT,this->window[0].seqnum);
                printf("\n冗余ACK%d *4 \n",ackPkt.acknum);
                resend_cnt = 0;
                return;
            }
        } else{
            resend_cnt = 0;
        }
//        last_ack = ackPkt.acknum;
        // all pkt are acked
        if(window_base == next_seqnum_to_send){
            pUtils->printPacket("发送方正确收到确认", this->window[0]);
            pns->stopTimer(SENDER, this->window[0].seqnum);
        } else{ // cumulative confirm.
            pUtils->printPacket("发送方没有正确收到确认，重发上次发送的报文", this->window[0]);
            pns->stopTimer(SENDER, this->window[0].seqnum);
            pns->startTimer(SENDER, Configuration::TIME_OUT, this->window[forward_num].seqnum);
        }
        // sliding
        for(int i=forward_num;i<=window_idx;i++){
            window[i-forward_num] = window[i];
        }
        // reset idx
        window_idx -= forward_num;
        waiting_state = false;
    }
//    }
}

void TCPRdtSender::timeoutHandler(int seqNum) {
    pUtils->printPacket("发送方定时器时间到，重发上次发送的报文", this->window[0]);
    // restart timer
    pns->stopTimer(SENDER, window[0].seqnum);
    pns->startTimer(SENDER, Configuration::TIME_OUT, window[0].seqnum);
    // resend
    for(int i=0;i<window_idx;i++){
        pns->sendToNetworkLayer(RECEIVER, window[i]);
    }
}

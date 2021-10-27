//
// Created by narrow on 2021/10/22.
//

#include "GBNRdtSender.h"

using namespace dzh;

GBNRdtSender::GBNRdtSender() {
    window_base = 0;
    next_seqnum_to_send = 0;
    waiting_state = false;
    window_idx = 0;
}

GBNRdtSender::~GBNRdtSender() noexcept {

}

bool GBNRdtSender::getWaitingState() {
    return this->waiting_state;
}

/**
 * get data from app layer, send to net layer
 * @param message
 * @return
 */
bool GBNRdtSender::send(const Message &message) {
    // window is not full
    if(next_seqnum_to_send < window_base + WIN_LENGTH){
        // make packet
        window[window_idx].acknum = -1;
        window[window_idx].seqnum = next_seqnum_to_send;
        memcpy(window[window_idx].payload, message.data, sizeof(message.data));
        window[window_idx].checksum = pUtils->calculateCheckSum(window[window_idx]);
        // send packet
        pUtils->printPacket("发送方发送报文", window[window_idx]);
        if(window_base == next_seqnum_to_send){
            pns->startTimer(SENDER, Configuration::TIME_OUT, window[window_idx].seqnum);
        }
        pns->sendToNetworkLayer(RECEIVER, window[window_idx]);

        if(++window_idx >= WIN_LENGTH){
            waiting_state = true;
        }
//        window_idx++;
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
void GBNRdtSender::receive(const Packet &ackPkt) {
    // seqnum > base
    if(window_idx > 0){
        // do rdt check
        int checksum = pUtils->calculateCheckSum(ackPkt);
//        cout << ackPkt.checksum << " " << checksum << endl;
//        cout << ackPkt.acknum << " " << window_base << endl;
        if(checksum == ackPkt.checksum && ackPkt.acknum >= window_base){    // >= !!!
            int forward_num = ackPkt.acknum - window_base + 1;
            // reset base
            window_base = ackPkt.acknum + 1;
            // all pkt are acked
            if(window_base == next_seqnum_to_send){
                pUtils->printPacket("发送方正确收到确认", ackPkt);
                pns->stopTimer(SENDER, ackPkt.acknum);
            } else{
                pUtils->printPacket("发送方没有正确收到确认，重发上次发送的报文", this->window[window_idx]);
                pns->stopTimer(SENDER, ackPkt.acknum);
                pns->startTimer(SENDER, Configuration::TIME_OUT, this->window[window_idx].seqnum);
                pns->sendToNetworkLayer(RECEIVER, this->window[window_idx]);							//重新发送数据包
            }

            for(int i=forward_num;i<=window_idx;i++){
                window[i-forward_num] = window[i];
            }
            window_idx -= forward_num;
            waiting_state = false;
        }
    }
}

void GBNRdtSender::timeoutHandler(int seqNum) {
    // restart timer
    pns->startTimer(SENDER, Configuration::TIME_OUT, seqNum);
    // resend
    for(int i=window_base;i<next_seqnum_to_send;i++){
        pns->sendToNetworkLayer(RECEIVER, window[i]);
    }
}
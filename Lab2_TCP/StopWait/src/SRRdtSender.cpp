//
// Created by narrow on 2021/10/25.
//

#include "SRRdtSender.h"

dzh::SRRdtSender::SRRdtSender() {

}

dzh::SRRdtSender::~SRRdtSender() {

}

bool dzh::SRRdtSender::getWaitingState() {
    return false;
}

bool dzh::SRRdtSender::send(const Message &message) {
    return false;
}

void dzh::SRRdtSender::receive(const Packet &ackPkt) {

}

void dzh::SRRdtSender::timeoutHandler(int seqNum) {

}

//
// Created by narrow on 2021/10/25.
//

#include "SRRdtReceiver.h"

using namespace dzh;

SRRdtReceiver::SRRdtReceiver() {
    recv_base = 1;
    expected_seqnum = 1;
    window_idx = 0;
}

SRRdtReceiver::~SRRdtReceiver() {

}

void SRRdtReceiver::receive(const Packet &packet) {
    checksum = pUtils->calculateCheckSum(packet);
    if(checksum == packet.checksum){
        if(packet.seqnum >= recv_base && packet.seqnum < recv_base + WIN_LENGTH){

        } else if(packet.seqnum >= recv_base - WIN_LENGTH && packet.seqnum < recv_base){

        }
    } else{

    }
}


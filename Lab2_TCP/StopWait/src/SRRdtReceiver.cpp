//
// Created by narrow on 2021/10/25.
//

#include "SRRdtReceiver.h"

using namespace dzh;

SRRdtReceiver::SRRdtReceiver() {
    recv_base = 1;
//    expected_seqnum = 1;
//    window_idx = 0;
    for(auto & i: ack_pkt.payload) i = '.';
    is_cached = vector<int>(WIN_LENGTH, 0);
}

SRRdtReceiver::~SRRdtReceiver() {

}

void SRRdtReceiver::receive(const Packet &packet) {
    checksum = pUtils->calculateCheckSum(packet);
    if(checksum == packet.checksum){
        if(packet.seqnum >= recv_base && packet.seqnum < recv_base + WIN_LENGTH){
            const int& idx = packet.seqnum - recv_base;
            if(!is_cached[idx]){
                window[idx] = packet;
                is_cached[idx] = 1;
            }
            if(is_cached[0]){
                pUtils->printPacket("接收方正确收到BASE的报文",this->window[0]);
                int valid = 0;
                for(int i = 0; is_cached[i]; i++) valid++;

                for(int i = 0;i < valid; i++)//将从发送方窗口数据上交，并且发送ACK
                {
                    Message msg;
                    memcpy(msg.data, this->window[i].payload, sizeof(this->window[i].payload));
                    pns->delivertoAppLayer(RECEIVER,msg);
                }
                for(int i = 0; i < WIN_LENGTH-valid; i++){
                    window[i] = window[i + valid];
                    is_cached[i] = is_cached[i+valid];
                }
                for(int i=WIN_LENGTH-valid;i<WIN_LENGTH;i++){
                    is_cached[i] = 0;
                }
                recv_base += valid;
            }
        } else if(packet.seqnum >= recv_base - WIN_LENGTH && packet.seqnum < recv_base){
            ack_pkt.acknum = packet.seqnum; //确认序号等于收到的报文序号
            ack_pkt.checksum = pUtils->calculateCheckSum(ack_pkt);
            pUtils->printPacket("接收方发送确认报文", ack_pkt);
            pns->sendToNetworkLayer(SENDER, ack_pkt);	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送确认报文到对方
        }
    } else{
        ack_pkt.acknum = packet.seqnum; //确认序号等于收到的报文序号
        ack_pkt.checksum = pUtils->calculateCheckSum(ack_pkt);
        pUtils->printPacket("接收方没有正确收到发送方的报文,数据校验错误", ack_pkt);
//        pUtils->printPacket("接收方重新发送上次的确认报文", ack_pkt);
//        pns->sendToNetworkLayer(SENDER, ack_pkt);	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送上次的确认报文
    }
}


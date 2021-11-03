//
// Created by narrow on 2021/10/22.
//

#include "GBNRdtReciever.h"

GBNRdtReceiver::GBNRdtReceiver() {
    expected_seqnum = 1;
    last_ack_pkt.acknum = 0;
    last_ack_pkt.seqnum = 0;
    for(auto & i: last_ack_pkt.payload) i = '.';
    last_ack_pkt.checksum = pUtils->calculateCheckSum(last_ack_pkt);
}

GBNRdtReceiver::~GBNRdtReceiver() noexcept {
    
}

void GBNRdtReceiver::receive(const Packet &packet) {
    int checksum = pUtils->calculateCheckSum(packet);
    
    if(checksum == packet.checksum && expected_seqnum == packet.seqnum){
        pUtils->printPacket("接收方正确收到发送方的报文", packet);

        // extract data and send to app
        Message msg;
        memcpy(msg.data, packet.payload, sizeof(packet.payload));
        pns->delivertoAppLayer(RECEIVER, msg);

        // send back an ack to net layer
        last_ack_pkt.acknum = packet.seqnum; //确认序号等于收到的报文序号
        last_ack_pkt.checksum = pUtils->calculateCheckSum(last_ack_pkt);
        pUtils->printPacket("接收方发送确认报文", last_ack_pkt);
        pns->sendToNetworkLayer(SENDER, last_ack_pkt);	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送确认报文到对方

        expected_seqnum++;
    } else{ // checksum error, resend ack
        if (checksum != packet.checksum) {
            pUtils->printPacket("接收方没有正确收到发送方的报文,数据校验错误", packet);
        }
        else {
            pUtils->printPacket("接收方没有正确收到发送方的报文,报文序号不对", packet);
        }
        pUtils->printPacket("接收方重新发送上次的确认报文", last_ack_pkt);
        pns->sendToNetworkLayer(SENDER, last_ack_pkt);	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送上次的确认报文
    }
}
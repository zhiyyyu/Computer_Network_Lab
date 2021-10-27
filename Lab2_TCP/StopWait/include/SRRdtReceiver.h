//
// Created by narrow on 2021/10/25.
//

#ifndef STOPWAIT_SRRDTRECEIVER_H
#define STOPWAIT_SRRDTRECEIVER_H

#include "RdtReceiver.h"

namespace dzh{
    class SRRdtReceiver:public RdtReceiver{
    private:
        int expected_seqnum;	// 期待收到的下一个报文序号
        Packet last_ack_pkt;	//上次发送的确认报文

    public:
        SRRdtReceiver();
        virtual ~SRRdtReceiver();

    public:

        void receive(const Packet &packet);	//接收报文，将被NetworkService调用
    };
}

#endif //STOPWAIT_SRRDTRECEIVER_H

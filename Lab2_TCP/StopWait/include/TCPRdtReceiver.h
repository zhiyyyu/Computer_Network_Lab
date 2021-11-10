//
// Created by narrow on 2021/11/10.
//

#ifndef STOPWAIT_TCPRDTRECEIVER_H
#define STOPWAIT_TCPRDTRECEIVER_H

#include "RdtReceiver.h"
#include "Global.h"

namespace dzh{
    class TCPRdtReceiver: public RdtReceiver{
    private:
        int expected_seqnum;	// 期待收到的下一个报文序号
        Packet last_ack_pkt;	//上次发送的确认报文

    public:
        TCPRdtReceiver();
        virtual ~TCPRdtReceiver();

    public:

        void receive(const Packet &packet);	//接收报文，将被NetworkService调用
    };
}


#endif //STOPWAIT_TCPRDTRECEIVER_H

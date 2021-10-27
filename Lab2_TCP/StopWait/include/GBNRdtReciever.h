//
// Created by narrow on 2021/10/22.
//

#ifndef STOPWAIT_GBNRDTRECIEVER_H
#define STOPWAIT_GBNRDTRECIEVER_H

#include "RdtReceiver.h"
#include "Global.h"

class GBNRdtReceiver: public RdtReceiver{
private:
    int expected_seqnum;	// 期待收到的下一个报文序号
    Packet last_ack_pkt;	//上次发送的确认报文

public:
    GBNRdtReceiver();
    virtual ~GBNRdtReceiver();

public:

    void receive(const Packet &packet);	//接收报文，将被NetworkService调用
};


#endif //STOPWAIT_GBNRDTRECIEVER_H

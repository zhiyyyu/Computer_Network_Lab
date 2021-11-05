//
// Created by narrow on 2021/10/25.
//

#ifndef STOPWAIT_SRRDTRECEIVER_H
#define STOPWAIT_SRRDTRECEIVER_H

#include "RdtReceiver.h"
#include "Global.h"

namespace dzh{
    class SRRdtReceiver:public RdtReceiver{
    private:
        static constexpr int WIN_LENGTH = 8;
        int expected_seqnum;	// 期待收到的下一个报文序号
        bool is_cached[WIN_LENGTH];
        Packet window[WIN_LENGTH];
        int recv_base;
        int window_idx;
        int checksum;

    public:
        SRRdtReceiver();
        virtual ~SRRdtReceiver();

    public:

        void receive(const Packet &packet);	//接收报文，将被NetworkService调用
    };
}

#endif //STOPWAIT_SRRDTRECEIVER_H

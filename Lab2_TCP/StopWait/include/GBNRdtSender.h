//
// Created by narrow on 2021/10/22.
//

#ifndef STOPWAIT_GBNRDTSENDER_H
#define STOPWAIT_GBNRDTSENDER_H

#include "string.h"

#include "RdtSender.h"
#include "Global.h"

namespace dzh{
    class GBNRdtSender:public RdtSender{
    private:
        static constexpr int WIN_LENGTH = 4;    // window size
        int window_base;                // idx of first package in cur window
        int window_idx;                 // idx of cur package in window
        int next_seqnum_to_send;	        // idx of next package to send
        int checksum;
        bool waiting_state;				// send window full ?
        Packet window[WIN_LENGTH];

        static inline Packet make_pkt(int nextseqnum, const Message &message);

    public:

        bool getWaitingState();
        bool send(const Message &message);						//发送应用层下来的Message，由NetworkServiceSimulator调用,如果发送方成功地将Message发送到网络层，返回true;如果因为发送方处于等待正确确认状态而拒绝发送Message，则返回false
        void receive(const Packet &ackPkt);						//接受确认Ack，将被NetworkServiceSimulator调用
        void timeoutHandler(int seqNum);					//Timeout handler，将被NetworkServiceSimulator调用

    public:
        GBNRdtSender();
        virtual ~GBNRdtSender();
    };
}

#endif //STOPWAIT_GBNRDTSENDER_H

//
// Created by narrow on 2021/10/25.
//

#ifndef STOPWAIT_SRRDTSENDER_H
#define STOPWAIT_SRRDTSENDER_H

#include "RdtSender.h"
#include "Global.h"

namespace dzh{
    class SRRdtSender:public RdtSender{
    private:
        static constexpr int WIN_LENGTH = 8;    // window size
        int window_base;                // idx of first package in cur window
        int window_idx;                 // idx of cur package in window
        int checksum;
        bool is_ack[WIN_LENGTH];
        int next_seqnum_to_send;	        // idx of next package to send
        bool waiting_state;				// send window full ?
        Packet window[WIN_LENGTH];

        static inline Packet make_pkt(int nextseqnum, const Message &message);

    public:

        bool getWaitingState();
        bool send(const Message &message);						//发送应用层下来的Message，由NetworkServiceSimulator调用,如果发送方成功地将Message发送到网络层，返回true;如果因为发送方处于等待正确确认状态而拒绝发送Message，则返回false
        void receive(const Packet &ackPkt);						//接受确认Ack，将被NetworkServiceSimulator调用
        void timeoutHandler(int seqNum);					//Timeout handler，将被NetworkServiceSimulator调用

    public:
        SRRdtSender();
        virtual ~SRRdtSender();
    };
}

#endif //STOPWAIT_SRRDTSENDER_H

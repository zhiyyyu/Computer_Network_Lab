//
// Created by narrow on 2021/10/25.
//

#include "Global.h"
#include "RdtSender.h"
#include "RdtReceiver.h"
#include "GBNRdtSender.h"
#include "GBNRdtReciever.h"

using namespace dzh;

int main(int argc, char* argv[])
{
    RdtSender *ps = new GBNRdtSender();
    RdtReceiver * pr = new GBNRdtReceiver();
    pns->setRunMode(0);  //VERBOS模式
//	pns->setRunMode(1);  //安静模式
    pns->init();
    pns->setRtdSender(ps);
    pns->setRtdReceiver(pr);
    pns->setInputFile("./input.txt");
    pns->setOutputFile("./output.txt");
    pns->start();

    delete ps;
    delete pr;
    delete pUtils;									//指向唯一的工具类实例，只在main函数结束前delete
    delete pns;										//指向唯一的模拟网络环境类实例，只在main函数结束前delete

    return 0;
}


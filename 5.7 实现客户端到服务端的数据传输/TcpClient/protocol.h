


//这是一个通讯协议设计文件
//规定了客户端和服务器端收发数据的格式
//采用了c风格的结构体编程，目的是为了实现弹性结构体
//以便适应长度大小不同的信息

//包含一个信息初始化函数，采集客户端控件的信息

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef  unsigned int uint;//重命名无符号的整型

struct PDU{
    uint uiPDULen;//消息总长度（协议数据长度）
    uint uiMsgType;//消息类型
    char caData[64];//消息的名称
    uint uiMsgLen;//消息的实际长度
    int caMsge[];//消息的实际内容，后期会动态申请具体的大小
    //必须写成一个数组，后面可以放很多种类型的数据
    //其他类型的数据会被当做整型指针存储，但可以在输出时当做字符指针输出
};

PDU *mkPDU(uint uiMsgLen);//提供信息长度，建立一条信息，信息具体内容未填
//也可以使用alt加回车来添加定义


#endif // PROTOCOL_H

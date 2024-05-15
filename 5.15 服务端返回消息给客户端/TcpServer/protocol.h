


//这是一个通讯协议设计文件，与客户端完全相同
//直接将TcpClient客户端的协议设计文件拷贝到服务器
//需要在工程文件里 添加现有文件

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef  unsigned int uint;//重命名无符号的整型

enum enum_message_type{//枚举,定义多个常数，值递增

    message_type_min=0,
    message_regist_request,//注册请求
    message_regist_respond,//注册回复
    message_type_max=0x00ffffff,

};

//两条关于注册返回消息的宏定义
#define regist_OK "regist OK!"
#define regist_false "regist failed: name existed!"

struct PDU{
    uint uiPDULen;//消息总长度（协议数据长度）
    uint uiMsgType;//消息类型
    char caData[64];//消息的名称
    uint uiMsgLen;//消息的实际长度
    int caMsge[];//消息的实际内容，后期会动态申请具体的大小
};

PDU *mkPDU(uint uiMsgLen);//提供信息长度，建立一条信息，信息具体内容未填
//也可以使用alt加回车来添加定义

#endif // PROTOCOL_H

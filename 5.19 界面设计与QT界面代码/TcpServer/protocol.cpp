
#include<protocol.h>//添加协议头文件

PDU *mkPDU(uint uiMsgLen)
{
    uint uiPDULen = sizeof(PDU)+uiMsgLen;
    //消息总长度=PDU字段+消息实际长度

    PDU *pdu=(PDU*)malloc(uiPDULen);
    //为pdu申请一个总长度的空间，前面放解释知识，
    //后面是基于消息实际长度决定的可变长度，放消息内容

    if(pdu == NULL){
        //如果没有足够的空间申请，pdu就不会有地址
        exit(EXIT_FAILURE);//退出程序
    }

    memset(pdu,0,uiPDULen);
    //在一段内存块中填充某个给定的值，例如0
    //它是对较大的结构体或数组进行清零操作的一种最快方法
    //避免早期的数据污染

   pdu->uiPDULen=uiPDULen;
   pdu->uiMsgLen=uiMsgLen;

   return pdu;

}

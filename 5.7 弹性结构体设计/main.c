#include<stdio.h>
#include<string.h>//字符串
#include<stdlib.h>//memcpy内存拷贝头文件
#include<unistd.h>//空间申请相关头文件

typedef struct PDU
{
    int a;
    int b;
    int c;
    int d[];//没有定义d数组的大小，默认就是0
}PDU;

int main()
{
    printf("Hello World!\n");

    printf("sizeof(PDU)=%d\n",sizeof(PDU));

    PDU *pp=(PDU*)malloc(sizeof(PDU)+100*sizeof (int));
    //申请一个自定大小的空间放到结构体未定义的后面部分

    pp->a=90;
    pp->b=80;
    pp->c=70;
    memcpy(pp->d,"you jump i jump!",17);
    //内存拷贝函数

    printf("a=%d,\nb=%d,\nc=%d,\nd=%s\n",pp->a,pp->b,pp->c,(char*)pp->d);
    //pp->d是整型指针，需要转成char*

    printf("sizeof(PDU)=%d\n",sizeof(PDU));
    //PDU结构体本身的长度依然不会改变

    free(pp);//释放结构体pp申请的空间,释放PDU是不行的，PDU是结构体定义，本身是不占用空间

    return 0;
}

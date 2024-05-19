

#include <QApplication>

#include "tcpclient.h"

#include "operatewidget.h"//用于测试窗口设计
#include "online.h"
#include "friend.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TcpClient w;
    w.show();


    //用来调试设计的窗口能否正常显示
    //Online w;
    //w.show();
    //Friend w;
    //w.show();
    //OperateWidget w;
    //w.show();


    return a.exec();
}

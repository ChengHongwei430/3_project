#include "tcpclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //被执行的程序是一个QApplication类对象
    QApplication a(argc, argv);//建立一个程序对象

    //主界面窗口是一个TCPClient类对象
    TCPClient w;

    w.show();//展示窗口

    return a.exec();//使程序一直执行
}

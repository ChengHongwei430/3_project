#include "tcpserver.h"
#include "operatedb.h"
#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    OperateDB::getInstance().init();//数据库初始化


    TcpServer w;
    w.show();

    return a.exec();
}

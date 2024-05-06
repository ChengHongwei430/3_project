
#include "tcpclient.h"
#include "ui_tcpclient.h"

TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    loadConfig();

    connect(&m_tcpSocket,SIGNAL(connected()),this,SLOT(showConnect()));
    //将信号的发出者m_tcpSocket与槽函数连接
    //当m_tcpSocket发出connected()的信号后，会触发槽函数

    //连接服务器，（IP地址，port端口号）
    m_tcpSocket.connectToHost(QHostAddress(m_strIP),m_usPort);//默认采用读写方式连接

}

TcpClient::~TcpClient()
{
    delete ui;
}


///端口和IP地址的配置文件加载函数///
void TcpClient::loadConfig()//使用Alt加回车来自动添加loadConfig函数的定义
{
    QFile file(":/client.config");
    if(file.open(QIODevice::ReadOnly))
    //使用读的方式打开文件，ReadOnly表示读，QIODevice是打开方式的作用域
    {
        QByteArray bydata=file.readAll();
        //将文件的内容全部都读出来，使用字节数组QByteArray的方式返回

        QString strdata = QString::fromStdString(bydata.toStdString());
        //qDebug()<<strdata;//打印检查结果
        file.close();//用完文件后关闭

        //ctrl加点击，跳转到帮助文件
        strdata.replace("\r\n"," ");//将无用字符替换
        //qDebug()<<strdata;//打印检查结果

        QStringList strList = strdata.split(" ");
        //基于空格键将字符串切分
//        for(int i=0;i<strList.size();++i){
//           qDebug()<<"--->"<<strList[i];//打印检查结果
//        }
        //使用ctrl加/可以实现多行注释

        m_strIP=strList.at(0);//IP地址，使用本地环回地址
        m_usPort=strList.at(1).toUShort();//端口号，使用无符号的16位整数
        //qDebug()<<"ip:"<<m_strIP<<"port:"<<m_usPort;;//打印检查结果


    }else{
        QMessageBox::critical(this,"open config","配置文件打开失败！");
    }
}

///显示与服务器的连接状态的槽函数
void TcpClient::showConnect()
{
    QMessageBox::information(this,"与服务器的连接状态","连接服务器成功！");
}


















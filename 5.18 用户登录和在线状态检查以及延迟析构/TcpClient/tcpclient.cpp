
#include "tcpclient.h"
#include "ui_tcpclient.h"

///构造函数
//1、TcpClient构造是有默认值的，就是建立一个默认的空白窗口文件，然后为指针ui申请一个新空间
//2、ui->setupUi(this);创建用户界面的控件
//3、加载IP地址和端口号
//4、将 客户端发出的信号 成功连接 这个事件与 展示连接状态槽函数showConnect() 连接
//5、基于得到的IP地址和端口号，采取读写方式与服务器建立连接
TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);

    //resize(300,200);//修改窗口大小

    loadConfig();

    connect(&m_tcpSocket,SIGNAL(connected()),this,SLOT(showConnect()));
    //将信号的发出者m_tcpSocket与槽函数连接
    //当m_tcpSocket发出connected()的信号后，会触发槽函数

    connect(&m_tcpSocket,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    //当读取到一个信号后，触发recvMsg槽函数

    //连接服务器，（IP地址，port端口号）
    m_tcpSocket.connectToHost(QHostAddress(m_strIP),m_usPort);//默认采用读写方式连接
}


///析构函数
TcpClient::~TcpClient()
{
    delete ui;
}


///端口和IP地址的配置文件加载函数
//1、建立一个文件用来读取配置文件
//2、尝试打开这个文件，这里需要考虑权限，如果打不开就报错
//3、将文件内容适应字节数组保存
//4、删掉多余的信息
//5、将IP地址和端口号保存到对应的成员变量里
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


///接收信息的槽函数
void TcpClient::recvMsg()
{
    qDebug()<<m_tcpSocket.bytesAvailable();//打印当前数据的大小

    uint uiPDULen = 0;
    m_tcpSocket.read((char*)&uiPDULen,sizeof(uint));
    uint uiMsgLen=uiPDULen-sizeof(PDU);

    PDU *pdu=mkPDU(uiMsgLen);
    m_tcpSocket.read((char*)pdu+sizeof(uint),uiPDULen-sizeof(uint));

    qDebug()<<"信息类型："<<pdu->uiMsgType<<" Message:"<<pdu->caData;

    switch(pdu->uiMsgType){
        case message_regist_respond://注册回复消息
        {
            if(strcmp(pdu->caData,regist_OK)==0){//字符串匹配函数，如果返回值等于 0，则表示 str1 等于 str2
                QMessageBox::information(this,"注册信息","注册成功！");
            }else{
                QMessageBox::warning(this,"注册信息","注册失败，该用户名已存在！");
            }
            break;
        }
        case message_login_respond://注册回复消息
        {
            if(strcmp(pdu->caData,login_OK)==0){//字符串匹配函数
                QMessageBox::information(this,"登录信息","登录成功！");
            }else{
                QMessageBox::warning(this,"登录信息","登录失败！");
            }
            break;
        }
        default: break;

    }
    free(pdu);
    pdu=NULL;//将放送过的pdu空间释放


    //qDebug()<<"信息类型："<<pdu->uiMsgType;//打印
    //qDebug()<<"信息实际长度："<<pdu->uiMsgLen;
    //qDebug()<<"信息名称："<<CaName<<" "<<CaPwd;
    //qDebug()<<"信息内容："<<(char*)(pdu->caMsge);
    //其他类型的数据会被当做整型指针存储，但可以在输出时当做字符指针输出
}


//一种很特别的注释方式，注释掉之前用来测试发送消息的函数
#if 0
///将输入框的内容作为信息发送的函数，发送控件对应的槽函数
//0、简化函数逻辑：将输入框的内容同时作为信息标题和信息内容，发一个信息
//1、获取输入框字符
//2、字符不能是空的，否则无意义
//3、调用mkPDU生成初始化的信息
//4、把输入框的信息写进信息里
//5、最后将一个整个信息写入连接信号m_tcpSocket
//6、将用完的信息结构体释放
void TcpClient::on_pushButton_clicked()
{
    QString strMsg = ui->lineEdit->text();//获得输入框的字符
    //当找不到组件时，可以先构建或者执行一次

    if(!strMsg.isEmpty()){//如果字符不是空的

        PDU *pdu=mkPDU(strMsg.size());
        //根据输入的信息长度，生成通讯协议

        memcpy(pdu->caData,strMsg.toStdString().c_str(),strMsg.size());
        memcpy(pdu->caMsge,strMsg.toStdString().c_str(),strMsg.size());//其他类型的数据会被当做整型指针存储，但可以在输出时当做字符指针输出
        //将输入框名称写入协议信息名称和内容部分
        //memcpy的前两个参数必须是指针，
        //pdu->caData是字符数组，自然是数组首位指针
        //strMsg是QT类型的字符串，不能直接使用String类的取首地址函数c_str()
        //所以先转成String，再取首地址

        pdu->uiMsgType=8888;//信息数据类型

        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);//将pdu作为协议信息写入发送信号

        free(pdu);
        pdu=NULL;//将放送过的pdu空间释放

    }else{
        QMessageBox::warning(this,"信息发送","发送的信息不能为空！");
    }

}
#endif


///登录函数
void TcpClient::on_login_pb_clicked()
//登录,与注册相同，都是给服务器发一条信息，只有消息类型不同
{

    QString strName = ui->name_le->text();
    QString strPwd = ui->pwd_le->text();
    if(!strName.isEmpty()&&!strPwd.isEmpty()){

        PDU *pdu=mkPDU(0);//创建一条信息，输入的是实际消息长度
        //这里直接使用消息标题PDU部分来存储了

        pdu->uiMsgType=message_login_request;//消息类型为申请注册

        strncpy(pdu->caData,strName.toStdString().c_str(),32);
        strncpy(pdu->caData+32,strPwd.toStdString().c_str(),32);
        //指针地址，字符串首地址c_str()，长度
        //将用户名和密码存入信息的名称字段caData

        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);//将pdu作为协议信息写入发送信号

        free(pdu);
        pdu=NULL;//将放送过的pdu空间释放

    }
    else{
        QMessageBox::critical(this,"提示信息","用户名或者密码不能为空！");
    }

}


///注册函数
void TcpClient::on_regist_pb_clicked()
{
    QString strName = ui->name_le->text();
    QString strPwd = ui->pwd_le->text();
    if(!strName.isEmpty()&&!strPwd.isEmpty()){

        PDU *pdu=mkPDU(0);//创建一条信息，输入的是实际消息长度
        //这里直接使用消息标题PDU部分来存储了

        pdu->uiMsgType=message_regist_request;//消息类型为申请注册

        strncpy(pdu->caData,strName.toStdString().c_str(),32);
        strncpy(pdu->caData+32,strPwd.toStdString().c_str(),32);
        //指针地址，字符串首地址c_str()，长度
        //将用户名和密码存入信息的名称字段caData

        m_tcpSocket.write((char*)pdu,pdu->uiPDULen);//将pdu作为协议信息写入发送信号

        free(pdu);
        pdu=NULL;//将放送过的pdu空间释放

    }
    else{
        QMessageBox::critical(this,"提示信息","用户名或者密码不能为空！");
    }
}


///注销函数
void TcpClient::on_cancel_pb_clicked()
{
    QString strName = ui->name_le->text();
    QString strPwd = ui->pwd_le->text();
    if(!strName.isEmpty()&&!strPwd.isEmpty()){

    }
    else{
        QMessageBox::critical(this,"提示信息","用户名或者密码不能为空！");
    }
}

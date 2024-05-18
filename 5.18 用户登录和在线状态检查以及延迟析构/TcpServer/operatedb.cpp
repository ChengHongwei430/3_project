#include "operatedb.h"

OperateDB::OperateDB(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");//初始化数据库类型sqlite3的名称：QSQLITE
}

OperateDB &OperateDB::getInstance()
{
    static OperateDB instance;//取代构造函数
    //静态的变量，只会创建一次，所以每次返回的都是同一个类变量
    //就实现了单例模式
    return instance;
}


///打印数据库状态
void OperateDB::init()
{
    m_db.setHostName("localhost");//连接的数据库属于本地数据库
    m_db.setDatabaseName("C:\\Users\\chw\\Desktop\\Network_disk\\test56\\TcpServer\\cloud.db");//数据库地址
    if(m_db.open()){

        //数据库信息调整,将所有用户初始在线状态置为0
        //userInfo(id,name,pwd,online)
        QString data =QString ("update userInfo set online=0");
        qDebug()<<data;
        QSqlQuery query;//一个数据库操作，可以识别你输入的字符串
        query.exec(data);

        query.exec("select * from userInfo");//我的表名和老师写的不一样

        while(query.next()){
            //QString data =QString("%1,%2").arg(query.value(0).toString()).arg(query.value(1).toString());
            //读取前两列数据
            QString data = QString("%1,%2,%3,%4").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString());
            qDebug()<<data;
        }

    }else{
        QMessageBox::critical(NULL,"打开数据库","数据库打开失败！");
    }
}


OperateDB::~OperateDB()
{
    m_db.close();//关闭数据库
}


///注册
bool OperateDB::handleRegist(const char *name, const char *pwd)
{
    if(name==NULL||pwd==NULL) {
        return false;
        qDebug()<<"name==NULL||pwd==NULL!";
    }
    QString data =QString ("insert into userInfo(name,pwd) values(\'%1\',\'%2\')").arg(name).arg(pwd);
    //C++的一种字符串拼接方法
    qDebug()<<data;

    QSqlQuery query;//一个数据库操作，可以识别你输入的字符串
    return query.exec(data);
    //用户名字在数据表中要求唯一，如果出现重复，则query.exec(data)执行会失败，自然会返回falise
    //不需要再额外判断，交给数据库就行

}


///登录
bool OperateDB::handleLogin(const char *name, const char *pwd)
{
    if(name==NULL||pwd==NULL) {
        return false;
        qDebug()<<"name==NULL||pwd==NULL!";
    }
    QString data =QString ("select * from userInfo where name=\'%1\' and pwd =\'%2\' and online=0").arg(name).arg(pwd);
    qDebug()<<data;
    QSqlQuery query;//一个数据库操作，可以识别你输入的字符串
    query.exec(data);//执行对应的语句，插入语句可以返回是否插入成功，但查询语句不会反应是否查到

    //qDebug()<<"是否查询到该用户："<<query.next();//语句是否返回了结果，query.next()会将结果的第一条放入query中
    //query.next()不仅会查看下一条记录，还会，使query查看的位置后移

    if(query.next()){//如果登录成功，则修改数据库

        QString datashow = QString("编号：%1,用户名：%2,密码：%3,在线状态：%4").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString());
        qDebug()<<datashow;

        QString data =QString ("update userInfo set online=1 where name=\'%1\' and pwd =\'%2\'").arg(name).arg(pwd);
        qDebug()<<data;
        QSqlQuery query;
        query.exec(data);
        return true;
    }
    return false;
}

void OperateDB::handleOffline(const char *name)
{
    if(name==NULL){
        qDebug()<<"name is NULL!";
    }
    QString data =QString ("update userInfo set online=0 where name=\'%1\'").arg(name);
    qDebug()<<data;
    QSqlQuery query;
    query.exec(data);
}




















#ifndef OPERATEWIDGET_H
#define OPERATEWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <friend.h>
#include <book.h>
#include <QStackedWidget>

class OperateWidget : public QWidget
{
    Q_OBJECT

public:

    explicit OperateWidget(QWidget *parent = nullptr);
    static OperateWidget &getInstance();//把控制界面变成单例模式

signals:

private:

    QListWidget *m_pListW;//左边的列表
    Friend *m_pFriend;//好友和图书放到堆栈里
    Book *m_pBook;

    QStackedWidget *m_psw;

};

#endif // OPERATEWIDGET_H

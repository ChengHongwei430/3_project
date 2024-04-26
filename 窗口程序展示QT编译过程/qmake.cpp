
#include<QApplication>//程序
#include<QLabel>//标签
#include<QLineEdit>//文本框
#include<QPushButton>//控件
#include<QHBoxLayout>//水平布局
#include<QVBoxLayout>//垂直布局
#include<QWidget>//窗口

int main(int argc, char* argv[]) {

	//被执行的程序是一个对象
	QApplication app(argc, argv);//建立一个程序对象

	//每一个控件都是一个对象
	QLabel* infoLabel = new QLabel;//建标签对象
	QLabel* openLabel = new QLabel;
	QLineEdit* cmdLineEdit = new QLineEdit;//文本框
	QPushButton* commitButton= new QPushButton;//按钮
	QPushButton* cancelButton = new QPushButton;

	infoLabel->setText("input cmd:");//设置控件的文本值
	openLabel->setText("open");
	commitButton->setText("commit");
	cancelButton->setText("cancel");

	//布局也是一个对象
	QHBoxLayout* cmdLayout = new QHBoxLayout;//水平布局对象
	cmdLayout->addWidget(openLabel);//将两个控件放到一个水平对象上
	cmdLayout->addWidget(cmdLineEdit);

	QHBoxLayout* buttonLayout = new QHBoxLayout;//水平布局对象2
	buttonLayout->addWidget(commitButton);
	buttonLayout->addWidget(cancelButton);

	QVBoxLayout* mainLayout = new QVBoxLayout;//垂直布局对象
	mainLayout->addWidget(infoLabel);
	mainLayout->addLayout(cmdLayout);//添加布局的函数与添加控件的不同
	mainLayout->addLayout(buttonLayout);

	//窗口也是一个对象
	QWidget w;
	w.setLayout(mainLayout);//把主布局放进窗口
	w.show();//展示窗口
	w.setWindowTitle("running...");//修改窗口名字

	return app.exec();//使程序一直执行
}
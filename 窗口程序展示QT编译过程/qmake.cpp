
#include<QApplication>//����
#include<QLabel>//��ǩ
#include<QLineEdit>//�ı���
#include<QPushButton>//�ؼ�
#include<QHBoxLayout>//ˮƽ����
#include<QVBoxLayout>//��ֱ����
#include<QWidget>//����

int main(int argc, char* argv[]) {

	//��ִ�еĳ�����һ������
	QApplication app(argc, argv);//����һ���������

	//ÿһ���ؼ�����һ������
	QLabel* infoLabel = new QLabel;//����ǩ����
	QLabel* openLabel = new QLabel;
	QLineEdit* cmdLineEdit = new QLineEdit;//�ı���
	QPushButton* commitButton= new QPushButton;//��ť
	QPushButton* cancelButton = new QPushButton;

	infoLabel->setText("input cmd:");//���ÿؼ����ı�ֵ
	openLabel->setText("open");
	commitButton->setText("commit");
	cancelButton->setText("cancel");

	//����Ҳ��һ������
	QHBoxLayout* cmdLayout = new QHBoxLayout;//ˮƽ���ֶ���
	cmdLayout->addWidget(openLabel);//�������ؼ��ŵ�һ��ˮƽ������
	cmdLayout->addWidget(cmdLineEdit);

	QHBoxLayout* buttonLayout = new QHBoxLayout;//ˮƽ���ֶ���2
	buttonLayout->addWidget(commitButton);
	buttonLayout->addWidget(cancelButton);

	QVBoxLayout* mainLayout = new QVBoxLayout;//��ֱ���ֶ���
	mainLayout->addWidget(infoLabel);
	mainLayout->addLayout(cmdLayout);//��Ӳ��ֵĺ�������ӿؼ��Ĳ�ͬ
	mainLayout->addLayout(buttonLayout);

	//����Ҳ��һ������
	QWidget w;
	w.setLayout(mainLayout);//�������ַŽ�����
	w.show();//չʾ����
	w.setWindowTitle("running...");//�޸Ĵ�������

	return app.exec();//ʹ����һֱִ��
}
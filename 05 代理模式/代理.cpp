//�ṹ��-01 ����ģʽ
//����ֱ�ӷ���ĳ����ķ���
//�ṩһ�ַ�ʽ�����������ƶ���������ķ���
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//���������mysysӵ�й����Ľӿڣ����д����ͨ�ýӿ��ࣨ�ڶ�������Ҫ���������ƶԶ�����ʵĹ����ӿڣ�
class abstractCommonInterface {
public:
	virtual void run() = 0;//���û������ķ���
};

//����һ���Ѿ�д���ϵͳ�ࣨ����ɵĵ�һ����
class mysys: public abstractCommonInterface {
public:
	virtual void run() {
		cout << "ϵͳ������" << endl;
	}
};

//����Ҫ��Ȩ����֤���û������룩�����������˶�������ϵͳ�����������û�ֱ�Ӵ�mysys���е�run()������ͨ�����������
//�̳��ڹ����ӿڳ�����Ĵ�����
//��ģ����һ��������mysys
class mysysproxy : public abstractCommonInterface {
public:
	//�û�������
	mysysproxy(string username, string password) {
		m_sUsername = username;
		m_sPassword = password;
		win10 = new mysys;//��ʼ��
	}
	~mysysproxy() {
		if (win10 != NULL) {
			delete win10;
		}
	}

	//�������ӷ�����
	//�Աȴ�����û���������
	bool check() {
		if (m_sUsername == "wym" && m_sPassword == "123") {
			return true;
		}
		return false;
	}

	virtual void run() {
		if (check()) {
			cout << "��֤ͨ������¼�ɹ�..." << endl;
			win10->run();
		}
		else {
			cout << "��������޷���¼..." << endl;
		}
	}

public:
	mysys* win10;//ֱ�ӷ�װһ��ϵͳ����������
	string m_sUsername;
	string m_sPassword;
};

//�ͻ��ˣ�ͨ�������¼
void test(string name,string password) {
	mysysproxy* proxy = new mysysproxy(name,password);
	proxy->run();
}

int main(void) {
	string name;
	string password;

	cout << "�û�����" ;
	cin >> name;
	cout << "���룺" ;
	cin >> password;
	test(name,password);

	system("pause");
	return 0;
}
//��Ϊ��-03 ����ģʽ
//������Ϸ������Ҫ֪���ͻ��˸�ʲô����ҪԼ��һ��Э�飨�ַ��������ͻ���Ҫ����һ������������������������Ҫ�����ˡ����裺ͨ��socket�������ӣ����ַ���������������������һֱ�ڼ���������������Э�飬�ٽ���һЩ��֤���Ϸ���ȼ���1����ͨ��socket���ظ��ͻ��ˡ�
//���Է�������Ӧ���ȶ���ø���Э�飬�Դ����������
#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;

//�������Э��
class  handleClientProtocol
{
public:
	//���ӽ�� Э��
	void addmoney() {
		cout << "��������ӽ�ң�" << endl;
	}
	//���ӵ�ȯ Э��
	void adddiamond() {
		cout << "��������ӵ�ȯ��" << endl;
	}
	//����װ�� Э��
	void addequipment() {
		cout << "����Ҵ�װ����" << endl;
	}
	//���� Э��
	void addlevel() {
		cout << "�����������" << endl;
	}
};

//����ӿ�
class abstractcommand {
public:
	virtual void handle() = 0;//����ͻ��˸�������Ľӿڡ�������װ�ɶ��󣬾Ϳ��Է����������
};

//�������ӽ�ҵ�����
class addmoneycommand :public abstractcommand {
public:
	addmoneycommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//��������ӿ�
	virtual void handle() {
		pProtocol->addmoney();//����ط��Ͱ����ӽ�������װ��һ�������ˣ�ֱ��newһ��addmoneycommand
	}
public:
	handleClientProtocol* pProtocol;
};

//�������ӵ�ȯ������
class adddiamondcommand :public abstractcommand {
public:
	adddiamondcommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//��������ӿ�
	virtual void handle() {
		pProtocol->adddiamond();
	}
public:
	handleClientProtocol* pProtocol;
};

//��װ��������
class addequipmentcommand :public abstractcommand {
public:
	addequipmentcommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//��������ӿ�
	virtual void handle() {
		pProtocol->addequipment();
	}
public:
	handleClientProtocol* pProtocol;
};

//����������
class addlevelcommand :public abstractcommand {
public:
	addlevelcommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//��������ӿ�
	virtual void handle() {
		pProtocol->addlevel();
	}
public:
	handleClientProtocol* pProtocol;
};

//������  ע�⣺��Դ���ޣ����дӿͻ�����������Э��Ҫ��װ�ɵ������������װ������Ŷ�
class server {
public:
	void addrequest(abstractcommand* commend) {
		mCommends.push(commend);
	}

	void startHandle() {//0.5���Ӵ���һ��Э��
		while (!mCommends.empty()) {
			Sleep(500);
			abstractcommand* commend = mCommends.front();
			commend->handle();
			mCommends.pop();
		}
	}
public:
	queue<abstractcommand*> mCommends;//mCommends�����������Э�����
};

int main(void) {
	handleClientProtocol *pro = new handleClientProtocol;

	//�ͻ��˷������ӽ�ҵ�����
	abstractcommand* misson1 = new addmoneycommand(pro);
	//�ͻ��˷������ӵ�ȯ������
	abstractcommand* misson2 = new adddiamondcommand(pro);
	//�ͻ��˷�������������
	abstractcommand* misson3 = new addlevelcommand(pro);
	//�ͻ��˷��ʹ�װ��������
	abstractcommand* misson4 = new addequipmentcommand(pro);

	//����������
	server* pserver = new server;

	//������������м����������
	pserver->addrequest(misson1);
	pserver->addrequest(misson2);
	pserver->addrequest(misson3);
	pserver->addrequest(misson4);

	//��ʼ����
	pserver->startHandle();

	system("pause");
	return 0;
}
//������-03 ���󹤳�ģʽ
//����ԭ���£�����ģʽ��������ĳ����Ʒ�ȼ��ṹ��
//***���󹤳���Ե��ǲ�Ʒ�壨�й��������㽶�����ӡ�ƻ���������������㽶�����ӡ�ƻ�����������ǲ�Ʒ�ȼ��ṹ���㽶�����ӡ�ƻ��������仰������ǣ��ڿ���ԭ���£����󹤳��������������Ʒ�壨���ӷ��ɱ������ģ����޸ĳ��󹤳�Դ���룩��
//���������Ʒ�ȼ��ṹ���������ϣ����޸ĳ��󹤳����룬�Ͳ����Ͽ���ԭ���ˡ�
//������뷢�֡���Ϊˮ��δ�������ͳһ�ġ�
#include<iostream>
#include<string>
using namespace std;

//����ƻ��
class abstractApple
{
public:
	virtual void getApple() = 0;
};
//�й�ƻ��
class ChinaApple :public abstractApple {
	virtual void getApple() {
		cout << "�й�ƻ��" << endl;
	}
};
//����ƻ��
class USAApple :public abstractApple {
	virtual void getApple() {
		cout << "����ƻ��" << endl;
	}
};
//�ձ�ƻ��
class JPApple :public abstractApple {
	virtual void getApple() {
		cout << "�й�ƻ��" << endl;
	}
};

//�����㽶
class abstractBanana
{
public:
	virtual void getBanana() = 0;
};
//�й��㽶
class ChinaBanana :public abstractBanana {
	virtual void getBanana() {
		cout << "�й��㽶" << endl;
	}
};
//�����㽶
class USABanana :public abstractBanana {
	virtual void getBanana() {
		cout << "�����㽶" << endl;
	}
};
//�ձ��㽶
class JPBanana :public abstractBanana {
	virtual void getBanana() {
		cout << "�й��㽶" << endl;
	}
};

//��������
class abstractPear
{
public:
	virtual void getPear() = 0;
};
//�й�����
class ChinaPear :public abstractPear {
	virtual void getPear() {
		cout << "�й�����" << endl;
	}
};
//��������
class USAPear :public abstractPear {
	virtual void getPear() {
		cout << "��������" << endl;
	}
};
//�ձ�����
class JPPear :public abstractPear {
	virtual void getPear() {
		cout << "�й�����" << endl;
	}
};


//���󹤳�  ���һ�����ŵĲ�Ʒ��
class abstractFactory {
public:
	//���ܣ�����������һ����Ʒ���е��κβ�Ʒ
	virtual abstractApple* createObjectApple() = 0;
	virtual abstractBanana* createObjectBanana() = 0;
	virtual abstractPear* createObjectPear() = 0;
};

//�й�����
class ChinaFactory : public abstractFactory {
public:
	virtual abstractApple* createObjectApple() {
		abstractApple* tmp = new ChinaApple();
		return tmp;
	}
	virtual abstractBanana* createObjectBanana() {
		abstractBanana* tmp = new ChinaBanana();
		return tmp;
	}
	virtual abstractPear* createObjectPear() {
		abstractPear* tmp = new ChinaPear();
		return tmp;
	}
};

//��������
class USAFactory : public abstractFactory {
public:
	virtual abstractApple* createObjectApple() {
		abstractApple* tmp = new USAApple();
		return tmp;
	}
	virtual abstractBanana* createObjectBanana() {
		abstractBanana* tmp = new USABanana();
		return tmp;
	}
	virtual abstractPear* createObjectPear() {
		abstractPear* tmp = new USAPear();
		return tmp;
	}
};

//�ձ�����
class JPFactory : public abstractFactory {
public:
	virtual abstractApple* createObjectApple() {
		abstractApple* tmp = new JPApple();
		return tmp;
	}
	virtual abstractBanana* createObjectBanana() {
		abstractBanana* tmp = new JPBanana();
		return tmp;
	}
	virtual abstractPear* createObjectPear() {
		abstractPear* tmp = new JPPear();
		return tmp;
	}
};

void test(){
	abstractFactory* factory = NULL;
	abstractApple* apple = NULL;
	abstractBanana* banana = NULL;
	abstractPear* pear = NULL;

	//����Ĺ���ˮ�����������������������
	//Ҫ�������ɱ����㽶ƻ�����Ӿ����Ӹ����ɱ����������࣬���Ͽ���ԭ��
	//���ǲ�Ʒ�������һ�����ϲ��У����޸Ĺ����������ܣ����룩

	//������Ҫ���������㽶��ƻ������Ʒ�壩
	//��������������
	factory = new USAFactory;
	//����ƻ�����㽶
	apple = factory->createObjectApple();
	banana = factory->createObjectBanana();
	//����
	apple->getApple();
	banana->getBanana();

	delete factory;
	delete apple;
	delete banana;
	delete pear;
}

int main(void) {
	test();

	system("pause");
	return 0;
}
//��Ϊ��-02 ����ģʽ
//����һϵ�е��㷨���Է�װ��Ϊ�����㷨����һ��������㷨�ӿڣ���ͨ���̳иó����㷨�ӿڶ����е��㷨���Է�װ��ʵ�֣�������㷨ѡ���ɿͻ��˾��������ԣ���
//ÿһ�������㷨��װ�ã������ǵ�ִ��˳��������û��Զ��壬��ģ�巽��ģʽ���÷�����
#include<iostream>
using namespace std;

//����ʹ�������Ĳ���
class weaponStrategy {
public:
	virtual void useWeapon() = 0;
};

//ذ��
class knife :public weaponStrategy {
public:
	virtual void useWeapon() {
		cout << "����ذ�ף�" << endl;
	}
};

//AK47
class gun :public weaponStrategy {
public:
	virtual void useWeapon() {
		cout << "����ǹ��" << endl;
	}
};

//����
class person {
public:
	//***��̬���ò���
	void setWeapon(weaponStrategy* pweapon) {
		pW = pweapon;
	}

	void play() {
		pW->useWeapon();
	}
public:
	weaponStrategy* pW;//�������ָ��
};

void test() {
	//������ɫ������
	person *p = new person;
	weaponStrategy* hudie = new knife;//���ϳ���һ�Ѻ�����
	weaponStrategy* AK47 = new gun;//���ϳ���һ��AK47
	
	//��������
	p->setWeapon(hudie);//���������
	p->play();

	p->setWeapon(AK47);//����AK47
	p->play();

	delete p;
	delete hudie;
	delete AK47;
}

int main(void) {
	test();

	system("pause");
	return 0;
}
//������-02 ��������ģʽ
//Ϊ�˽���򵥹��������Ͽ���ԭ���ȱ�㣬�����������ȥ
//��һ��ˮ����Ӧһ���������������й����̳���һ�����󹤳�
//�ŵ㣺�򵥹���ģʽ + ���Ͽ���ԭ�� = ��������ģʽ
//ȱ�㣺1.��ĸ����ɱ����ӣ���Ϊ����һ��ˮ�������ζ������һ�����������࣬����ά���ɱ���2.�򵥹���ģʽ���жϷ��ڴ����ĸ�������ڹ������Ҫ���Ρ�����������û���ж��߼������Ҫ�жϣ���Ҫ�ͻ��Լ�ȥ�жϣ������ǹ�����
#include<iostream>
#include<string>
using namespace std;

//����ˮ��
class abstractFruit
{
public:
	virtual void getFruit() = 0;
};

//����ˮ��1�����㽶
class Banana : public abstractFruit
{
public:
	virtual void getFruit()
	{
		cout << "�����㽶" << endl;
	}
};

//����ˮ��2��������
class Pear : public abstractFruit
{
public:
	virtual void getFruit()
	{
		cout << "��������" << endl;
	}
};

//����ˮ��3����ƻ��
class Apple : public abstractFruit
{
public:
	virtual void getFruit()
	{
		cout << "����ƻ��" << endl;
	}
};

//���󹤳�
class abstractFactory {
public:
	//����ֵ����д����
	virtual abstractFruit* createFruit() = 0;
};

//ƻ����������
class createAppleFactory : public abstractFactory {
	virtual abstractFruit* createFruit() {
		abstractFruit* tmp = new Apple();
		return tmp;
	}
};

//�㽶��������
class createBananaFactory : public abstractFactory {
	virtual abstractFruit* createFruit() {
		abstractFruit* tmp = new Banana();
		return tmp;
	}
};

//������������
class createPearFactory : public abstractFactory {
	virtual abstractFruit* createFruit() {
		abstractFruit* tmp = new Pear();
		return tmp;
	}
};

void test() {
	abstractFactory* factory = NULL;
	abstractFruit* fruit = NULL;

	//����һ��ƻ����������
	factory = new createAppleFactory;
	//��ƻ��������������һ������ƻ������
	fruit = factory->createFruit();
	fruit->getFruit();

	delete fruit;
	delete factory;

	//����һ���㽶��������
	factory = new createBananaFactory;
	//���㽶������������һ�������㽶����
	fruit = factory->createFruit();
	fruit->getFruit();

	delete fruit;
	delete factory;
}

int main(void) {
	test();

	system("pause");
	return 0;
}
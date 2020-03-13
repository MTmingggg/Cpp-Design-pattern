//������-01 �򵥹���ģʽ��23��֮�⣩
//ԭ�����Լ����Լ�д��ҵ����������new��������
//��ʵ���󣺲���ܴ�������ֻ��Ѷ��������ã�
//***�����ù�����ȥ��������createobject()�����;�����򽻵������͹����򽻵���
//����������������ù���֪��Ӧ�ô���ʲô���͵Ķ���
//�ô���1.�ͻ��˺;���ʵ�����������ⶼ�ǹ��������⡣2.����ĳЩ���󴴽����ӵ���������ڲ���ȥ������Щ�ˡ�
//ȱ�㣺1.�����¹�����ͨ���޸Ĺ�������ʵ�֣�Υ������ԭ��2.���ְ����أ�����������⣬��Ӱ��ܶ�ʹ�ù�����ģ�顣

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

//ˮ���������������������Ͽ���ԭ��
class FruitFactory
{
public:
	//��̬����
	static abstractFruit* CreateObject(string flag)
	{
		if (flag == "apple")
		{
			//�����������ʼ��apple���������Զ��ļ�ʲô�ģ���main�оͲ��ù��Ĵ���ʱ������Щ����������ܶ�
			abstractFruit* tmp = new Apple();
			return tmp;
		}
		else if (flag == "banana")
		{
			abstractFruit* tmp = new Banana();
			return tmp;
		}
		else if (flag == "pear")
		{
			abstractFruit* tmp = new Pear();
			return tmp;
		}
		else {
			return NULL;
		}
	}
};

void test() {
	//����һ��ˮ������
	FruitFactory* factory = new FruitFactory;
	//�ù���ȥ����һ��ƻ��������ָ����Ϊapple
	abstractFruit* apple = factory->CreateObject("apple");
	//apple���Ե���ʵ��������Է���
	apple->getFruit();

	abstractFruit* pear = factory->CreateObject("pear");
	pear->getFruit();

	abstractFruit* banana = factory->CreateObject("banana");
	banana->getFruit();

	delete apple;
	delete pear;
	delete banana;
	delete factory;
}

int main(void) {
	test();

	system("pause");
	return 0;
}
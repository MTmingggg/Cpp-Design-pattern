//������-04 ����
//ȫ��ϵͳ�и���ֻ����һ�����󣬲������û����ù��캯������ֹ�Լ���������ͬʱҲ�������û��ṩ�����ͷŵ�������
//static��̬������Ψһ���� ͨ������::���� ����

//���ھ�һ�����󣬲������ڴ�������������������ϲ��ؿ����ͷš�
//��Ҫ�ͷŵĻ���������ȫ�ֱ����ڳ������ʱ���������������������һ��Ƕ����

//ʵ�ֵ���ģʽ�Ĳ��裺
//1.���캯��˽�л�private
//2.���Ӿ�̬˽�еĵ�ǰ���ָ�����
//3.�ṩ��̬����ӿڣ��������û���õ�������
#include<iostream>
using namespace std;
//������Ϊ����ʽ�Ͷ���ʽ

//����ʽ����һ�ε���getInstance()ʱ�����Ż�ȥ������ʼ�����ö���
class singleton_lazy {
//1.���캯��˽�л�private
private:
	singleton_lazy(){
		cout << "������������" << endl;
	}

public:
	//3.�ṩ��̬����ӿڣ��������û���õ�������
	static singleton_lazy* getInstance() {
		if (psingleton == NULL) {
			psingleton = new singleton_lazy;
		}
		return psingleton;
	}

private:
	static singleton_lazy* psingleton;
};
//�����ʼ��
//2.���Ӿ�̬˽�еĵ�ǰ��singleton_lazy��ָ�����psingleton
singleton_lazy* singleton_lazy::psingleton = NULL;

//����ʽ����ʼ��ʱ�ʹ����ˣ�ֱ��return
class singleton_hungry {
private:
	singleton_hungry() {
		cout << "���Ƕ�������" << endl;
	}

public:
	static singleton_hungry* getInstance() {
		return psingleton;
	}

	//�������ˣ�����������������
	class garbo {
		~garbo()
		{
			if (psingleton != NULL) {
				delete psingleton;
			}
		}
	};

private:
	static singleton_hungry* psingleton;//���������ָ�루��̬˽�У�
	static garbo g;//���һ�ٵ�д����ʵ���ϲ���д
};
//�����ʼ��ֱ��new
singleton_hungry* singleton_hungry::psingleton = new singleton_hungry;



void test() {
	singleton_lazy* p1 = singleton_lazy::getInstance();
	singleton_lazy* p2 = singleton_lazy::getInstance();
	if (p1 == p2)
	{
		cout << "����������ָ��ָ��ͬһ�ڴ棬�ǵ���" << endl;
	}
	else {
		cout << "���������ǵ���" << endl;
	}

	singleton_hungry* p3 = singleton_hungry::getInstance();
	singleton_hungry* p4 = singleton_hungry::getInstance();
	if (p3 == p4)
	{
		cout << "����������ָ��ָ��ͬһ�ڴ棬�ǵ���" << endl;
	}
	else {
		cout << "���������ǵ���" << endl;
	}
}


//***�������ڣ������Ƚ��ż�����main��ʼִ��֮ǰ������������ѱ�new�����������������ڵ���ʱ�Ż��ʼ��������
int main(void) {
	cout << "main��ʼִ��" << endl;
	test();

	system("pause");
	return 0;
}
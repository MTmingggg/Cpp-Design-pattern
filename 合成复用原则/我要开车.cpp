//�ϳɸ���ԭ��
//�̳к���ϣ�����ʹ�����
#include<iostream>
using namespace std;

//����
class abstractcar{
public:
	virtual void run() = 0;
};

//����
class dazhong :public abstractcar {
public:
	virtual void run() {
		cout << "��������" << endl;
	}
};

//������
class tuolaji :public abstractcar {
public:
	virtual void run() {
		cout << "����������" << endl;
	}
};

//��Ҫ�������������˼̳о��峵������ͬ�����س���
//�����
class person {
public:
	void setCar(abstractcar* incar) {
		car = incar;
	}
	void doufeng() {
		car->run();
		if (car != NULL) {
			delete car;//ֱ������������car
			car = NULL;
		}
	}

	//~person() {
	//	if (car != NULL) {
	//		delete car;
	//	}
	//}
public:
	abstractcar* car;
};

void test0(){
	person *p = new person;
	p->setCar(new dazhong);
	p->doufeng();
	
	p->setCar(new tuolaji);
	p->doufeng();
	delete p;
}


int main(void) {
	test0();
	system("pause");
	return 0;
}
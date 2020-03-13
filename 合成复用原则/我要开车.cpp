//合成复用原则
//继承和组合，优先使用组合
#include<iostream>
using namespace std;

//抽象车
class abstractcar{
public:
	virtual void run() = 0;
};

//大众
class dazhong :public abstractcar {
public:
	virtual void run() {
		cout << "大众启动" << endl;
	}
};

//拖拉机
class tuolaji :public abstractcar {
public:
	virtual void run() {
		cout << "拖拉机启动" << endl;
	}
};

//人要开车，不能用人继承具体车，出现同名重载出错
//用组合
class person {
public:
	void setCar(abstractcar* incar) {
		car = incar;
	}
	void doufeng() {
		car->run();
		if (car != NULL) {
			delete car;//直接在这里销毁car
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
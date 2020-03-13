//依赖倒转原则
//原本一层一层向底层依赖
//如果底层函数变化，那上层全部受影响，不利于维护
//现在业务层和实现层全部依赖于抽象层，实现和业务无关
#include<iostream>
using namespace std;

////反面教材
////底层模块
//class bankworker {
//public:
//	void dosave(){
//		cout << "办理存储业务" << endl;
//	}
//	void dopay(){
//		cout << "办理支付业务" << endl;
//	}
//	void dotransfer(){
//		cout << "办理转账业务" << endl;
//	}
//};
//
////中层模块  依赖于底层
//void dosave(bankworker* w1) {
//	w1->dosave();
//}
//void dopay(bankworker* w1) {
//	w1->dopay();
//}
//void dotransfer(bankworker* w1) {
//	w1->dotransfer();
//}
//
////业务模块  依赖于中层
//void test() {
//	bankworker* w = new bankworker;
//	dosave(w);
//}

//银行工作人员 用到单一职责原则，三个职责分开
class abstractwoker {
public:
	virtual void dowork() = 0;
};

//专门办理存款业务的工作人员
class dosavewoker: public abstractwoker {
public:
	virtual void dowork() {
		cout << "办理存款业务" << endl;
	}
};

//专门办理支付业务的工作人员
class dopaywoker : public abstractwoker {
public:
	virtual void dowork() {
		cout << "办理支付业务" << endl;
	}
};

//专门办理转账业务的工作人员
class dotransferwoker : public abstractwoker {
public:
	virtual void dowork() {
		cout << "办理转账业务" << endl;
	}
};

//业务依赖于抽象层（更高一层，不是具体办哪个业务的，要想增加一个新业务就很方便（可扩展性强）） abstractwoker* worker
void donework(abstractwoker* worker) {//传进来是抽象层的
	worker->dowork();//灵活，不会写成具体办哪个业务的工作人员，因此不会写死
}

//客户端 父类指针实例化子类对象，从堆上分配内存
void test() {
	abstractwoker* sw = new dosavewoker;
	donework(sw);
	delete sw;

	abstractwoker* sp = new dopaywoker;
	donework(sp);
	delete sp;

	abstractwoker* st = new dotransferwoker;
	donework(st);
	delete st;
}

int main(void) {
	test();

	system("pause");
	return 0;
}
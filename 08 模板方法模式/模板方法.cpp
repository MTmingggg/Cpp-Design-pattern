//行为型-01 模板方法模式
//定义一个算法框架，将一些步骤（具备一定特征）的实现延迟到子类
//特征：实现步骤一样，但每部步现细节不同。例如冲咖啡和冲茶叶。
//冲茶叶：1.煮开水 2.茶叶加入开水 3.茶水倒入杯中 4.加入柠檬
//冲咖啡：1.煮开水 2.咖啡粉加入开水 3.咖啡倒入杯中 4.加入糖和牛奶
//***可以先定抽象步骤（抽象模板），模板方法make()（算法框架）每次都有这四步。子类继承于它，再把每步实现

//***这个make()被定义在抽象步骤中，定好了调用顺序，只是没实现，实现细节在子类里，到时直接调make()即可

//增加符合抽象步骤的子类仍符合开闭原则。
#include<iostream>
using namespace std;

//定好的抽象步骤
class abstractdrinktemplate {
public:
	//煮开水
	virtual void boildwater() = 0;
	//冲泡
	virtual void brew() = 0;
	//倒入杯中
	virtual void pourincup() = 0;
	//加辅料
	virtual void addsth() = 0;

	//模板方法
	void make() {
		boildwater();
		brew();
		pourincup();
		addsth();
	}
};

//冲泡咖啡
class coffee : public abstractdrinktemplate {
public:
	//煮开水
	virtual void boildwater() {
		cout << "煮开水" << endl;
	}
	//冲泡
	virtual void brew() {
		cout << "冲泡咖啡粉" << endl;
	}
	//倒入杯中
	virtual void pourincup() {
		cout << "倒入杯中" << endl;
	}
	//加辅料
	virtual void addsth() {
		cout << "加入牛奶" << endl;
	}
};

//冲泡茶水
class tea : public abstractdrinktemplate {
public:
	//煮开水
	virtual void boildwater() {
		cout << "煮开水" << endl;
	}
	//冲泡
	virtual void brew() {
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void pourincup() {
		cout << "倒入杯中" << endl;
	}
	//加辅料
	virtual void addsth() {
		cout << "加入柠檬" << endl;
	}
};

int main(void) {
	tea* ptea = new tea;
	ptea->make();

	coffee* pcoffee = new coffee;
	pcoffee->make();

	delete ptea;
	delete pcoffee;
	system("pause");
	return 0;
}
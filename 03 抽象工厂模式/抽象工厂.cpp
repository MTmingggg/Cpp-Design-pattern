//创建型-03 抽象工厂模式
//开闭原则下，工厂模式仅能生产某个产品等级结构。
//***抽象工厂针对的是产品族（中国生产的香蕉、梨子、苹果，美国生产的香蕉、梨子、苹果），而不是产品等级结构（香蕉、梨子、苹果）。这句话的理解是：在开闭原则下，抽象工厂可以生产多个产品族（增加菲律宾生产的，不修改抽象工厂源代码）。
//但是如果产品等级结构中增加西瓜，会修改抽象工厂代码，就不符合开闭原则了。
//敲完代码发现。因为水果未被抽象成统一的。
#include<iostream>
#include<string>
using namespace std;

//抽象苹果
class abstractApple
{
public:
	virtual void getApple() = 0;
};
//中国苹果
class ChinaApple :public abstractApple {
	virtual void getApple() {
		cout << "中国苹果" << endl;
	}
};
//美国苹果
class USAApple :public abstractApple {
	virtual void getApple() {
		cout << "美国苹果" << endl;
	}
};
//日本苹果
class JPApple :public abstractApple {
	virtual void getApple() {
		cout << "中国苹果" << endl;
	}
};

//抽象香蕉
class abstractBanana
{
public:
	virtual void getBanana() = 0;
};
//中国香蕉
class ChinaBanana :public abstractBanana {
	virtual void getBanana() {
		cout << "中国香蕉" << endl;
	}
};
//美国香蕉
class USABanana :public abstractBanana {
	virtual void getBanana() {
		cout << "美国香蕉" << endl;
	}
};
//日本香蕉
class JPBanana :public abstractBanana {
	virtual void getBanana() {
		cout << "中国香蕉" << endl;
	}
};

//抽象梨子
class abstractPear
{
public:
	virtual void getPear() = 0;
};
//中国梨子
class ChinaPear :public abstractPear {
	virtual void getPear() {
		cout << "中国梨子" << endl;
	}
};
//美国梨子
class USAPear :public abstractPear {
	virtual void getPear() {
		cout << "美国梨子" << endl;
	}
};
//日本梨子
class JPPear :public abstractPear {
	virtual void getPear() {
		cout << "中国梨子" << endl;
	}
};


//抽象工厂  针对一个横着的产品族
class abstractFactory {
public:
	//功能：均可以生产一个产品族中的任何产品
	virtual abstractApple* createObjectApple() = 0;
	virtual abstractBanana* createObjectBanana() = 0;
	virtual abstractPear* createObjectPear() = 0;
};

//中国工厂
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

//美国工厂
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

//日本工厂
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

	//想吃哪国的水果在这里改生产工厂就行了
	//要引进菲律宾的香蕉苹果梨子就增加个菲律宾生产工厂类，符合开闭原则
	//但是产品族里，增加一个西瓜不行，会修改工厂生产功能（代码）

	//现在我要吃美国的香蕉和苹果（产品族）
	//创建个美国厂子
	factory = new USAFactory;
	//生产苹果和香蕉
	apple = factory->createObjectApple();
	banana = factory->createObjectBanana();
	//来吃
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
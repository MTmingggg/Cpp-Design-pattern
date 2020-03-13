//创建型-02 工厂方法模式
//为了解决简单工厂不符合开闭原则的缺点，将工厂抽象出去
//让一类水果对应一类生产工厂，所有工厂继承于一个抽象工厂
//优点：简单工厂模式 + 符合开闭原则 = 工厂方法模式
//缺点：1.类的个数成倍增加，因为增加一个水果类就意味着增加一类生产工厂类，增加维护成本。2.简单工厂模式把判断放在创建哪个对象放在工厂里，需要传参。但工厂方法没有判断逻辑，如果要判断，需要客户自己去判断，而不是工厂。
#include<iostream>
#include<string>
using namespace std;

//抽象水果
class abstractFruit
{
public:
	virtual void getFruit() = 0;
};

//具体水果1——香蕉
class Banana : public abstractFruit
{
public:
	virtual void getFruit()
	{
		cout << "我是香蕉" << endl;
	}
};

//具体水果2——梨子
class Pear : public abstractFruit
{
public:
	virtual void getFruit()
	{
		cout << "我是梨子" << endl;
	}
};

//具体水果3——苹果
class Apple : public abstractFruit
{
public:
	virtual void getFruit()
	{
		cout << "我是苹果" << endl;
	}
};

//抽象工厂
class abstractFactory {
public:
	//返回值尽量写抽象！
	virtual abstractFruit* createFruit() = 0;
};

//苹果生产工厂
class createAppleFactory : public abstractFactory {
	virtual abstractFruit* createFruit() {
		abstractFruit* tmp = new Apple();
		return tmp;
	}
};

//香蕉生产工厂
class createBananaFactory : public abstractFactory {
	virtual abstractFruit* createFruit() {
		abstractFruit* tmp = new Banana();
		return tmp;
	}
};

//梨子生产工厂
class createPearFactory : public abstractFactory {
	virtual abstractFruit* createFruit() {
		abstractFruit* tmp = new Pear();
		return tmp;
	}
};

void test() {
	abstractFactory* factory = NULL;
	abstractFruit* fruit = NULL;

	//创建一个苹果生产工厂
	factory = new createAppleFactory;
	//用苹果生产工厂创建一个具体苹果对象
	fruit = factory->createFruit();
	fruit->getFruit();

	delete fruit;
	delete factory;

	//创建一个香蕉生产工厂
	factory = new createBananaFactory;
	//用香蕉生产工厂创建一个具体香蕉对象
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
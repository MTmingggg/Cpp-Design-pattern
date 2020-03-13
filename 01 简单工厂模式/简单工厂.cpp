//创建型-01 简单工厂模式（23种之外）
//原本：自己在自己写的业务函数或类中new创建对象。
//现实需求：不想管创建对象，只想把对象拿来用！
//***现在让工厂类去创建对象createobject()。不和具体类打交道，而和工厂打交道。
//传入参数给工厂，让工厂知道应该创建什么类型的对象
//好处：1.客户端和具体实现类解耦。出问题都是工厂的问题。2.对于某些对象创建复杂的情况，现在不用去考虑这些了。
//缺点：1.增加新功能是通过修改工厂代码实现，违背开闭原则。2.类的职责过重，如果发生问题，会影响很多使用工厂的模块。

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

//水果生产工厂（工厂不符合开闭原则）
class FruitFactory
{
public:
	//静态方法
	static abstractFruit* CreateObject(string flag)
	{
		if (flag == "apple")
		{
			//可以在这里初始化apple，设置属性读文件什么的，在main中就不用关心创建时做了哪些工作，方便很多
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
	//创建一个水果工厂
	FruitFactory* factory = new FruitFactory;
	//让工厂去创建一个苹果，对象指针名为apple
	abstractFruit* apple = factory->CreateObject("apple");
	//apple可以调用实现类的属性方法
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
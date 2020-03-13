//行为型-02 策略模式
//它对一系列的算法加以封装，为所有算法定义一个抽象的算法接口，并通过继承该抽象算法接口对所有的算法加以封装和实现，具体的算法选择交由客户端决定（策略）。
//每一步具体算法封装好，但它们的执行顺序可以由用户自定义，和模板方法模式正好反过来
#include<iostream>
using namespace std;

//抽象使用武器的策略
class weaponStrategy {
public:
	virtual void useWeapon() = 0;
};

//匕首
class knife :public weaponStrategy {
public:
	virtual void useWeapon() {
		cout << "捡起匕首！" << endl;
	}
};

//AK47
class gun :public weaponStrategy {
public:
	virtual void useWeapon() {
		cout << "捡起枪！" << endl;
	}
};

//人物
class person {
public:
	//***动态设置策略
	void setWeapon(weaponStrategy* pweapon) {
		pW = pweapon;
	}

	void play() {
		pW->useWeapon();
	}
public:
	weaponStrategy* pW;//基类抽象指针
};

void test() {
	//创建角色、武器
	person *p = new person;
	weaponStrategy* hudie = new knife;//地上出现一把蝴蝶刀
	weaponStrategy* AK47 = new gun;//地上出现一把AK47
	
	//武器策略
	p->setWeapon(hudie);//拿起蝴蝶刀
	p->play();

	p->setWeapon(AK47);//拿起AK47
	p->play();

	delete p;
	delete hudie;
	delete AK47;
}

int main(void) {
	test();

	system("pause");
	return 0;
}
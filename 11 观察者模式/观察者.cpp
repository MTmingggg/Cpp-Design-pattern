//行为型-04 观察者模式
//例：随着信号灯的变化，汽车的行为也将发生变化。一盏交通信号灯可以控制很多车的行为。
//一个类的行为将引起很多类发生变化。
//发生改变的对象叫观察目标，而被自动通知的对象们称为观察者。
//观察目标可以不止一个，被通知对象也不止一个，因此都要抽象出来
//观察目标可以增加、删除观察者的指针、调用观察者update（boss死了通知每个英雄从进攻状态变为待机状态）
#include<iostream>
#include<list>
using namespace std;

//抽象英雄（观察者）
class abstractHero {
public:
	virtual void update() = 0;
};

//具体的五个观察者们
class HeroA :public abstractHero {
public:
	HeroA() {
		cout << "英雄A在撸boss" << endl;
	}

	virtual void update() {
		cout << "英雄A停止撸boss，待机" << endl;
	}
};

class HeroB :public abstractHero {
public:
	HeroB() {
		cout << "英雄B在撸boss" << endl;
	}

	virtual void update() {
		cout << "英雄B停止撸boss，待机" << endl;
	}
};

class HeroC:public abstractHero {
public:
	HeroC() {
		cout << "英雄C在撸boss" << endl;
	}

	virtual void update() {
		cout << "英雄C停止撸boss，待机" << endl;
	}
};

class HeroD :public abstractHero {
public:
	HeroD() {
		cout << "英雄D在撸boss" << endl;
	}

	virtual void update() {
		cout << "英雄D停止撸boss，待机" << endl;
	}
};

class HeroE :public abstractHero {
public:
	HeroE() {
		cout << "英雄E在撸boss" << endl;
	}

	virtual void update() {
		cout << "英雄E停止撸boss，待机" << endl;
	}
};

//抽象boss（观察目标）
class abstractBoss {
public:
	virtual void addHero(abstractHero* hero) = 0;//增加观察者
	virtual void deleteHero(abstractHero* hero) = 0;//删除观察者
	virtual void notify() = 0;//通知观察者
};

//具体的一个BossA 观察目标
class BossA: public abstractBoss{
public:
	//增加观察者
	virtual void addHero(abstractHero* hero) {
		pHeroList.push_back(hero);
	}

	//删除观察者
	virtual void deleteHero(abstractHero* hero) {
		pHeroList.remove(hero);//根据值删除
	}

	//通知观察者
	virtual void notify() {
		for (list<abstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); it ++) {//遍历list中每个观察者
			(*it)->update();
		}
	}

public:
	list<abstractHero*> pHeroList;
};

void test() {
	//创建五个观察者
	abstractHero* gailun = new HeroA;
	abstractHero* yasuo = new HeroB;
	abstractHero* juhua = new HeroC;
	abstractHero* huangzi = new HeroD;
	abstractHero* timo = new HeroE;

	//创建观察目标
	abstractBoss* dalong = new BossA;
	dalong->addHero(gailun);
	dalong->addHero(yasuo);
	dalong->addHero(juhua);
	dalong->addHero(huangzi);
	dalong->addHero(timo);

	cout << "yasuo阵亡！" << endl;
	dalong->deleteHero(yasuo);//删除观察者

	cout << "boss被击杀..." << endl;
	dalong->notify();//通知还在list中的观察者更改状态
}

int main(void) {
	test();

	system("pause");
	return 0;
}
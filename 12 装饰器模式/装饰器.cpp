//结构型-04 装饰器模式
//对继承的一种替代。给一个类动态增加功能
//英雄----穿上裤衩----》还是个英雄
#include<iostream>
using namespace std;

//抽象英雄
class abstractHero {
public:
	virtual void showStatus() = 0;//共有行为
public:
	int mHp;//血量
	int mMp;//法力值
	int mAt;//攻击
	int mDf;//防御
};

//具体英雄
class HeroA :public abstractHero {
public:
	HeroA() {
		mHp = 1000;//血量
		mMp = 200;//法力值
		mAt = 50;// 攻击
		mDf = 0;//防御
	}
	virtual void showStatus() {
		cout << "血量：" << mHp << endl;
		cout << "法力值：" << mMp << endl;
		cout << "攻击：" << mAt << endl;
		cout << "防御：" << mDf << endl;
	}
};

//装备（装饰物） 英雄穿上装饰物应当还是个英雄
class abstractequipment : public abstractHero {//要保存英雄原来的状态
public:
	abstractequipment(abstractHero* hero) {
		pHero = hero;
	}

	virtual void showStatus() = 0;
public:
	abstractHero* pHero;
};

//狂徒
class kuangtu :public abstractequipment {
public:
	kuangtu(abstractHero* hero):abstractequipment(hero){

	}

	//增加的额外功能
	void addKuangtu() {
		cout << "装备了狂徒之后..." << endl;
		mHp = pHero->mHp + 800;
		mMp = pHero->mMp;
		mAt = pHero->mAt;
		mDf = pHero->mDf + 40;
	}

	virtual void showStatus() {
		addKuangtu();
		cout << "血量：" << mHp << endl;
		cout << "法力值：" << mMp << endl;
		cout << "攻击：" << mAt << endl;
		cout << "防御：" << mDf << endl;
	}
};

//无尽
class wujin :public abstractequipment {
public:
	wujin(abstractHero* hero):abstractequipment(hero){

	}

	//增加的额外功能
	void addWujin() {
		cout << "装备了无尽之后..." << endl;
		mHp = pHero->mHp;
		mMp = pHero->mMp;
		mAt = pHero->mAt +20;
		mDf = pHero->mDf;
	}

	virtual void showStatus() {
		addWujin();
		cout << "血量：" << mHp << endl;
		cout << "法力值：" << mMp << endl;
		cout << "攻击：" << mAt << endl;
		cout << "防御：" << mDf << endl;
	}
};

int main(void) {
	abstractHero* gailun = new HeroA;
	gailun->showStatus();
	cout << "------" << endl;
	//买了狂徒
	gailun = new kuangtu(gailun);
	gailun->showStatus();
	cout << "------" << endl;
	//买了无尽
	gailun = new wujin(gailun);
	gailun->showStatus();

	system("pause");
	return 0;
}
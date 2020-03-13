//结构型-02 外观模式
//根据迪米特法则，当类之间具有相似的功能，就不需要挨个new创建再调用方法，用户不必关心具体类。
//外观模式就是将复杂的子类系统抽想到同一个的接口进行管理。外界指需要通过这个接口和子类进行交互即可，不必直接和子类交互，避免关心子类细节。
//例如有四个子系统要启动run()，我不用new四次再分别调用run()。外观模式下，创建一个接口（外观类）提供runall()方法给我，我只需new接口，调用runall()即可启动四个子系统。
//客户端界面一致，仅需和外观类打交道。

//智能设备模式
//KTV模式：音响开，灯关，游戏机关，电视开，话筒开
//游戏模式：音响开，灯开，游戏机开，电视开，话筒关
//工作模式：音响关，灯开，游戏机关，电视关，话筒关
#include<iostream>
using namespace std;

//抽象设备
class abstractshebei {
public:
	virtual void on() = 0;
	virtual void off() = 0;
};

//具体设备1 音响
class yinxiang:public abstractshebei {
public:
	virtual void on() {
		cout << "音响打开！" << endl;
	}
	virtual void off()  {
		cout << "音响关闭！" << endl;
	}
};

//具体设备2 灯
class deng :public abstractshebei {
public:
	virtual void on() {
		cout << "灯打开！" << endl;
	}
	virtual void off() {
		cout << "灯关闭！" << endl;
	}
};

//具体设备3 游戏机
class youxiji :public abstractshebei {
public:
	virtual void on() {
		cout << "游戏机打开！" << endl;
	}
	virtual void off() {
		cout << "游戏机关闭！" << endl;
	}
};

//具体设备4 电视
class dianshi :public abstractshebei {
public:
	virtual void on() {
		cout << "电视打开！" << endl;
	}
	virtual void off() {
		cout << "电视关闭！" << endl;
	}
};

//具体设备5 话筒
class huatong :public abstractshebei {
public:
	virtual void on() {
		cout << "话筒打开！" << endl;
	}
	virtual void off() {
		cout << "话筒关闭！" << endl;
	}
};

//抽象接口（抽象外观类）  负责控制不同模式中所有设备的开关
class abstractmodecontrol{
public:
	virtual void modecontrol() = 0;
};

//KTV模式
class KTVmode :public abstractmodecontrol {
public:
	KTVmode() {
		cout << "KTV模式" << endl;
		pyx = new yinxiang;
		pd = new deng;
		pyxj = new youxiji;
		pdsh = new dianshi;
		pht = new huatong;
	}

	~KTVmode()
	{ 
		delete pyx;
		delete pd;
		delete pyxj;
		delete pdsh;
		delete pht;
	}

	virtual void modecontrol() {
		pyx->on();
		pd->off();
		pyxj->off();
		pdsh->on();
		pht->on();
	}

private:
	abstractshebei* pyx;
	abstractshebei* pd;
	abstractshebei* pyxj;
	abstractshebei* pdsh;
	abstractshebei* pht;
};

//游戏模式
class gamemode :public abstractmodecontrol {
public:
	gamemode() {
		cout << "游戏模式" << endl;
		pyx = new yinxiang;
		pd = new deng;
		pyxj = new youxiji;
		pdsh = new dianshi;
		pht = new huatong;
	}

	~gamemode()
	{
		delete pyx;
		delete pd;
		delete pyxj;
		delete pdsh;
		delete pht;
	}

	virtual void modecontrol() {
		pyx->on();
		pd->on();
		pyxj->on();
		pdsh->on();
		pht->off();
	}

private:
	abstractshebei* pyx;
	abstractshebei* pd;
	abstractshebei* pyxj;
	abstractshebei* pdsh;
	abstractshebei* pht;
};

//工作模式
class workmode :public abstractmodecontrol {
public:
	workmode() {
		cout << "工作模式" << endl;
		pyx = new yinxiang;
		pd = new deng;
		pyxj = new youxiji;
		pdsh = new dianshi;
		pht = new huatong;
	}

	~workmode()
	{
		delete pyx;
		delete pd;
		delete pyxj;
		delete pdsh;
		delete pht;
	}

	virtual void modecontrol() {
		pyx->off();
		pd->on();
		pyxj->off();
		pdsh->off();
		pht->off();
	}

private:
	abstractshebei* pyx;
	abstractshebei* pd;
	abstractshebei* pyxj;
	abstractshebei* pdsh;
	abstractshebei* pht;
};

void test(int n) {
	abstractmodecontrol* pmode;
	switch (n)
	{
	case(1):
		pmode = new KTVmode;
		pmode->modecontrol();
		break;
	case(2):
		pmode = new gamemode;
		pmode->modecontrol();
		break;
	case(3):
		pmode = new workmode;
		pmode->modecontrol();
		break;
	default:
		cout << "输入错误..." << endl;
		break;
	}
}

int main(void) {
	int num = 0;
	cout << "选择模式：1.KTV模式 2.游戏模式 3.工作模式" << endl;
	cin >> num;

	test(num);

	system("pause");
	return 0;
}
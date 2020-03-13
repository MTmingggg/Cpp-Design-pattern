//行为型-03 命令模式
//例：游戏服务器要知道客户端干什么，就要约定一个协议（字符串）。客户端要发送一个东西给服务器，内容是我要升级了。步骤：通过socket建立连接，把字符串发给服务器，服务器一直在监听，服务器解析协议，再进行一些验证，合法后等级加1，再通过socket返回给客户端。
//所以服务器端应该先定义好各种协议，以处理各种请求
#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;

//处理各种协议
class  handleClientProtocol
{
public:
	//增加金币 协议
	void addmoney() {
		cout << "给玩家增加金币！" << endl;
	}
	//增加点券 协议
	void adddiamond() {
		cout << "给玩家增加点券！" << endl;
	}
	//处理装备 协议
	void addequipment() {
		cout << "给玩家穿装备！" << endl;
	}
	//升级 协议
	void addlevel() {
		cout << "给玩家升级！" << endl;
	}
};

//命令接口
class abstractcommand {
public:
	virtual void handle() = 0;//处理客户端各类请求的接口。这样封装成对象，就可以放入服务器了
};

//处理增加金币的请求
class addmoneycommand :public abstractcommand {
public:
	addmoneycommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//来自命令接口
	virtual void handle() {
		pProtocol->addmoney();//这个地方就把增加金币请求封装成一个对象了，直接new一个addmoneycommand
	}
public:
	handleClientProtocol* pProtocol;
};

//处理增加点券的请求
class adddiamondcommand :public abstractcommand {
public:
	adddiamondcommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//来自命令接口
	virtual void handle() {
		pProtocol->adddiamond();
	}
public:
	handleClientProtocol* pProtocol;
};

//穿装备的请求
class addequipmentcommand :public abstractcommand {
public:
	addequipmentcommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//来自命令接口
	virtual void handle() {
		pProtocol->addequipment();
	}
public:
	handleClientProtocol* pProtocol;
};

//升级的请求
class addlevelcommand :public abstractcommand {
public:
	addlevelcommand(handleClientProtocol* protocol) {
		pProtocol = protocol;
	}

	//来自命令接口
	virtual void handle() {
		pProtocol->addlevel();
	}
public:
	handleClientProtocol* pProtocol;
};

//服务器  注意：资源有限，所有从客户端来的请求协议要封装成单个对象（命令），装入队列排队
class server {
public:
	void addrequest(abstractcommand* commend) {
		mCommends.push(commend);
	}

	void startHandle() {//0.5秒钟处理一个协议
		while (!mCommends.empty()) {
			Sleep(500);
			abstractcommand* commend = mCommends.front();
			commend->handle();
			mCommends.pop();
		}
	}
public:
	queue<abstractcommand*> mCommends;//mCommends待处理的命令协议对象
};

int main(void) {
	handleClientProtocol *pro = new handleClientProtocol;

	//客户端发送增加金币的请求
	abstractcommand* misson1 = new addmoneycommand(pro);
	//客户端发送增加点券的请求
	abstractcommand* misson2 = new adddiamondcommand(pro);
	//客户端发送升级的请求
	abstractcommand* misson3 = new addlevelcommand(pro);
	//客户端发送穿装备的请求
	abstractcommand* misson4 = new addequipmentcommand(pro);

	//创建服务器
	server* pserver = new server;

	//向请求处理队列中加入命令对象
	pserver->addrequest(misson1);
	pserver->addrequest(misson2);
	pserver->addrequest(misson3);
	pserver->addrequest(misson4);

	//开始处理
	pserver->startHandle();

	system("pause");
	return 0;
}
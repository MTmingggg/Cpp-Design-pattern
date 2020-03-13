//结构型-01 代理模式
//不能直接访问某对象的方法
//提供一种方式（代理）来控制对其他对象的访问
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

//代理类需和mysys拥有公共的接口，因此写抽象通用接口类（第二步：需要代理类限制对对象访问的公共接口）
class abstractCommonInterface {
public:
	virtual void run() = 0;//给用户启动的方法
};

//这是一个已经写完的系统类（已完成的第一步）
class mysys: public abstractCommonInterface {
public:
	virtual void run() {
		cout << "系统启动！" << endl;
	}
};

//必须要有权限验证（用户名密码），不是所有人都能启动系统。（不允许用户直接从mysys类中调run()，必须通过代理类调）
//继承于公共接口抽象类的代理类
//它模拟了一个真正的mysys
class mysysproxy : public abstractCommonInterface {
public:
	//用户名密码
	mysysproxy(string username, string password) {
		m_sUsername = username;
		m_sPassword = password;
		win10 = new mysys;//初始化
	}
	~mysysproxy() {
		if (win10 != NULL) {
			delete win10;
		}
	}

	//可以增加方法了
	//对比传入的用户名和密码
	bool check() {
		if (m_sUsername == "wym" && m_sPassword == "123") {
			return true;
		}
		return false;
	}

	virtual void run() {
		if (check()) {
			cout << "验证通过，登录成功..." << endl;
			win10->run();
		}
		else {
			cout << "输入错误，无法登录..." << endl;
		}
	}

public:
	mysys* win10;//直接封装一个系统到代理类里
	string m_sUsername;
	string m_sPassword;
};

//客户端，通过代理登录
void test(string name,string password) {
	mysysproxy* proxy = new mysysproxy(name,password);
	proxy->run();
}

int main(void) {
	string name;
	string password;

	cout << "用户名：" ;
	cin >> name;
	cout << "密码：" ;
	cin >> password;
	test(name,password);

	system("pause");
	return 0;
}
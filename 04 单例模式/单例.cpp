//创建型-04 单例
//全局系统中该类只能有一个对象，不允许用户调用构造函数（禁止自己创建），同时也不能向用户提供用于释放的析构。
//static静态函数拿唯一对象 通过类名::方法 调用

//由于就一个对象，不会在内存中造成溢出，因此理论上不必考虑释放。
//非要释放的话，方法：全局变量在程序结束时会调对象析构函数。增加一个嵌套类

//实现单例模式的步骤：
//1.构造函数私有化private
//2.增加静态私有的当前类的指针变量
//3.提供静态对外接口，可以让用户获得单例对象
#include<iostream>
using namespace std;
//单例分为懒汉式和饿汉式

//懒汉式，第一次调用getInstance()时，它才回去创建初始化调用对象
class singleton_lazy {
//1.构造函数私有化private
private:
	singleton_lazy(){
		cout << "我是懒汉构造" << endl;
	}

public:
	//3.提供静态对外接口，可以让用户获得单例对象
	static singleton_lazy* getInstance() {
		if (psingleton == NULL) {
			psingleton = new singleton_lazy;
		}
		return psingleton;
	}

private:
	static singleton_lazy* psingleton;
};
//类外初始化
//2.增加静态私有的当前类singleton_lazy的指针变量psingleton
singleton_lazy* singleton_lazy::psingleton = NULL;

//饿汉式，初始化时就创建了，直接return
class singleton_hungry {
private:
	singleton_hungry() {
		cout << "我是饿汉构造" << endl;
	}

public:
	static singleton_hungry* getInstance() {
		return psingleton;
	}

	//垃圾工人，负责析构单例对象
	class garbo {
		~garbo()
		{
			if (psingleton != NULL) {
				delete psingleton;
			}
		}
	};

private:
	static singleton_hungry* psingleton;//单例对象的指针（静态私有）
	static garbo g;//多此一举的写法，实际上不必写
};
//类外初始化直接new
singleton_hungry* singleton_hungry::psingleton = new singleton_hungry;



void test() {
	singleton_lazy* p1 = singleton_lazy::getInstance();
	singleton_lazy* p2 = singleton_lazy::getInstance();
	if (p1 == p2)
	{
		cout << "懒汉：两个指针指向同一内存，是单例" << endl;
	}
	else {
		cout << "懒汉：不是单例" << endl;
	}

	singleton_hungry* p3 = singleton_hungry::getInstance();
	singleton_hungry* p4 = singleton_hungry::getInstance();
	if (p3 == p4)
	{
		cout << "饿汉：两个指针指向同一内存，是单例" << endl;
	}
	else {
		cout << "饿汉：不是单例" << endl;
	}
}


//***区别在于，饿汉比较着急，在main开始执行之前，单例对象就已被new创建出来。而懒汉在调用时才会初始化出对象。
int main(void) {
	cout << "main开始执行" << endl;
	test();

	system("pause");
	return 0;
}
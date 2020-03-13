//开闭原则
//对扩展开放，对修改关闭
//增加功能是通过增加代码实现，而不是修改！
#include<iostream>
using namespace std;

//第一步：写个抽象类
class abstractjisuanqi{
public:
	virtual int getResult() = 0;
	virtual void setoperatornum(int a, int b) = 0;
};

//第二步：加法类
class plusc :public abstractjisuanqi{
public:
	virtual void setoperatornum(int a, int b){
		m_iA = a;
		m_iB = b;
	}
	virtual int getResult(){
		return m_iA + m_iB;
	}
public:
	int m_iA;
	int m_iB;
};

//减法类
//***实现新功能靠往下增加代码
//减法出错不可能去找加法类
class minutec :public abstractjisuanqi{
public:
	virtual void setoperatornum(int a, int b){
		m_iA = a;
		m_iB = b;
	}
	virtual int getResult(){
		return m_iA - m_iB;
	}
public:
	int m_iA;
	int m_iB;
};

//客户端（业务函数）
void test0(){
	abstractjisuanqi* c1 = new plusc;
	c1->setoperatornum(10, 20);
	c1->getResult();
	cout << "res:"<< c1->getResult() << endl;
	delete c1;

	abstractjisuanqi* c2 = new minutec;
	c2->setoperatornum(100, 30);
	c2->getResult();
	cout << "res:" << c2->getResult() << endl;
	delete c2;
}

int main(void){
	test0();

	system("pause");
	return 0;
}
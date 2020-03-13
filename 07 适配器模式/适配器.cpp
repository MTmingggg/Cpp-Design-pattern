//结构型-03 适配器模式
//将一个类的接口转换成客户希望的另一个接口，使原本由于接口不兼容而不能一起工作的那些类可以一起工作。
//参考  “5V手机--------充电适配器--------220V电源”
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//函数对象，这个函数已经写好了，但是它不符合调用的要求（参数数量不一样），要写一个适配器
struct MyPrint
{
	void operator()(int v1, int v2) {//这样不可被foreach使用，因为绑了两个参数
		cout << v1 + v2 << endl;
	}
};

//定义目标接口 我要适配，适配成什么样的
class target {
public:
	virtual void operator()(int v) = 0;//希望进foreach的是这个
};

//写适配器
class adapter :public target {//继承目标，表示要适配成它这样的
public:
	adapter(int param) {
		this->param = param;
	}

	virtual void operator()(int v) {
		print(v, param);
	}
public:
	MyPrint print;
	int param;
};

//MyBind2nd
adapter MyBind2nd(int v) {
	return adapter(v);
}

//int main(void) {
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//for_each(v.begin(), v.end(), MyPrint());//第三个参数为绑一个参数的函数对象
//	for_each(v.begin(), v.end(), MyBind2nd(100));
//
//	system("pause");
//	return 0;
//}
//�ṹ��-03 ������ģʽ
//��һ����Ľӿ�ת���ɿͻ�ϣ������һ���ӿڣ�ʹԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������
//�ο�  ��5V�ֻ�--------���������--------220V��Դ��
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//����������������Ѿ�д���ˣ������������ϵ��õ�Ҫ�󣨲���������һ������Ҫдһ��������
struct MyPrint
{
	void operator()(int v1, int v2) {//�������ɱ�foreachʹ�ã���Ϊ������������
		cout << v1 + v2 << endl;
	}
};

//����Ŀ��ӿ� ��Ҫ���䣬�����ʲô����
class target {
public:
	virtual void operator()(int v) = 0;//ϣ����foreach�������
};

//д������
class adapter :public target {//�̳�Ŀ�꣬��ʾҪ�������������
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
//	//for_each(v.begin(), v.end(), MyPrint());//����������Ϊ��һ�������ĺ�������
//	for_each(v.begin(), v.end(), MyBind2nd(100));
//
//	system("pause");
//	return 0;
//}
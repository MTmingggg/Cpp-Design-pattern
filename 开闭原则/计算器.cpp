//����ԭ��
//����չ���ţ����޸Ĺر�
//���ӹ�����ͨ�����Ӵ���ʵ�֣��������޸ģ�
#include<iostream>
using namespace std;

//��һ����д��������
class abstractjisuanqi{
public:
	virtual int getResult() = 0;
	virtual void setoperatornum(int a, int b) = 0;
};

//�ڶ������ӷ���
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

//������
//***ʵ���¹��ܿ��������Ӵ���
//������������ȥ�Ҽӷ���
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

//�ͻ��ˣ�ҵ������
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
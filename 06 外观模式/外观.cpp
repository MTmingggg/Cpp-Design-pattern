//�ṹ��-02 ���ģʽ
//���ݵ����ط��򣬵���֮��������ƵĹ��ܣ��Ͳ���Ҫ����new�����ٵ��÷������û����ع��ľ����ࡣ
//���ģʽ���ǽ����ӵ�����ϵͳ���뵽ͬһ���Ľӿڽ��й������ָ��Ҫͨ������ӿں�������н������ɣ�����ֱ�Ӻ����ཻ���������������ϸ�ڡ�
//�������ĸ���ϵͳҪ����run()���Ҳ���new�Ĵ��ٷֱ����run()�����ģʽ�£�����һ���ӿڣ�����ࣩ�ṩrunall()�������ң���ֻ��new�ӿڣ�����runall()���������ĸ���ϵͳ��
//�ͻ��˽���һ�£�����������򽻵���

//�����豸ģʽ
//KTVģʽ�����쿪���ƹأ���Ϸ���أ����ӿ�����Ͳ��
//��Ϸģʽ�����쿪���ƿ�����Ϸ���������ӿ�����Ͳ��
//����ģʽ������أ��ƿ�����Ϸ���أ����ӹأ���Ͳ��
#include<iostream>
using namespace std;

//�����豸
class abstractshebei {
public:
	virtual void on() = 0;
	virtual void off() = 0;
};

//�����豸1 ����
class yinxiang:public abstractshebei {
public:
	virtual void on() {
		cout << "����򿪣�" << endl;
	}
	virtual void off()  {
		cout << "����رգ�" << endl;
	}
};

//�����豸2 ��
class deng :public abstractshebei {
public:
	virtual void on() {
		cout << "�ƴ򿪣�" << endl;
	}
	virtual void off() {
		cout << "�ƹرգ�" << endl;
	}
};

//�����豸3 ��Ϸ��
class youxiji :public abstractshebei {
public:
	virtual void on() {
		cout << "��Ϸ���򿪣�" << endl;
	}
	virtual void off() {
		cout << "��Ϸ���رգ�" << endl;
	}
};

//�����豸4 ����
class dianshi :public abstractshebei {
public:
	virtual void on() {
		cout << "���Ӵ򿪣�" << endl;
	}
	virtual void off() {
		cout << "���ӹرգ�" << endl;
	}
};

//�����豸5 ��Ͳ
class huatong :public abstractshebei {
public:
	virtual void on() {
		cout << "��Ͳ�򿪣�" << endl;
	}
	virtual void off() {
		cout << "��Ͳ�رգ�" << endl;
	}
};

//����ӿڣ���������ࣩ  ������Ʋ�ͬģʽ�������豸�Ŀ���
class abstractmodecontrol{
public:
	virtual void modecontrol() = 0;
};

//KTVģʽ
class KTVmode :public abstractmodecontrol {
public:
	KTVmode() {
		cout << "KTVģʽ" << endl;
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

//��Ϸģʽ
class gamemode :public abstractmodecontrol {
public:
	gamemode() {
		cout << "��Ϸģʽ" << endl;
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

//����ģʽ
class workmode :public abstractmodecontrol {
public:
	workmode() {
		cout << "����ģʽ" << endl;
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
		cout << "�������..." << endl;
		break;
	}
}

int main(void) {
	int num = 0;
	cout << "ѡ��ģʽ��1.KTVģʽ 2.��Ϸģʽ 3.����ģʽ" << endl;
	cin >> num;

	test(num);

	system("pause");
	return 0;
}
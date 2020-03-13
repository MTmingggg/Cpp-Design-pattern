//��Ϊ��-01 ģ�巽��ģʽ
//����һ���㷨��ܣ���һЩ���裨�߱�һ����������ʵ���ӳٵ�����
//������ʵ�ֲ���һ������ÿ������ϸ�ڲ�ͬ������忧�Ⱥͳ��Ҷ��
//���Ҷ��1.��ˮ 2.��Ҷ���뿪ˮ 3.��ˮ���뱭�� 4.��������
//�忧�ȣ�1.��ˮ 2.���ȷۼ��뿪ˮ 3.���ȵ��뱭�� 4.�����Ǻ�ţ��
//***�����ȶ������裨����ģ�壩��ģ�巽��make()���㷨��ܣ�ÿ�ζ������Ĳ�������̳��������ٰ�ÿ��ʵ��

//***���make()�������ڳ������У������˵���˳��ֻ��ûʵ�֣�ʵ��ϸ�����������ʱֱ�ӵ�make()����

//���ӷ��ϳ�����������Է��Ͽ���ԭ��
#include<iostream>
using namespace std;

//���õĳ�����
class abstractdrinktemplate {
public:
	//��ˮ
	virtual void boildwater() = 0;
	//����
	virtual void brew() = 0;
	//���뱭��
	virtual void pourincup() = 0;
	//�Ӹ���
	virtual void addsth() = 0;

	//ģ�巽��
	void make() {
		boildwater();
		brew();
		pourincup();
		addsth();
	}
};

//���ݿ���
class coffee : public abstractdrinktemplate {
public:
	//��ˮ
	virtual void boildwater() {
		cout << "��ˮ" << endl;
	}
	//����
	virtual void brew() {
		cout << "���ݿ��ȷ�" << endl;
	}
	//���뱭��
	virtual void pourincup() {
		cout << "���뱭��" << endl;
	}
	//�Ӹ���
	virtual void addsth() {
		cout << "����ţ��" << endl;
	}
};

//���ݲ�ˮ
class tea : public abstractdrinktemplate {
public:
	//��ˮ
	virtual void boildwater() {
		cout << "��ˮ" << endl;
	}
	//����
	virtual void brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void pourincup() {
		cout << "���뱭��" << endl;
	}
	//�Ӹ���
	virtual void addsth() {
		cout << "��������" << endl;
	}
};

int main(void) {
	tea* ptea = new tea;
	ptea->make();

	coffee* pcoffee = new coffee;
	pcoffee->make();

	delete ptea;
	delete pcoffee;
	system("pause");
	return 0;
}
//������תԭ��
//ԭ��һ��һ����ײ�����
//����ײ㺯���仯�����ϲ�ȫ����Ӱ�죬������ά��
//����ҵ����ʵ�ֲ�ȫ�������ڳ���㣬ʵ�ֺ�ҵ���޹�
#include<iostream>
using namespace std;

////����̲�
////�ײ�ģ��
//class bankworker {
//public:
//	void dosave(){
//		cout << "����洢ҵ��" << endl;
//	}
//	void dopay(){
//		cout << "����֧��ҵ��" << endl;
//	}
//	void dotransfer(){
//		cout << "����ת��ҵ��" << endl;
//	}
//};
//
////�в�ģ��  �����ڵײ�
//void dosave(bankworker* w1) {
//	w1->dosave();
//}
//void dopay(bankworker* w1) {
//	w1->dopay();
//}
//void dotransfer(bankworker* w1) {
//	w1->dotransfer();
//}
//
////ҵ��ģ��  �������в�
//void test() {
//	bankworker* w = new bankworker;
//	dosave(w);
//}

//���й�����Ա �õ���һְ��ԭ������ְ��ֿ�
class abstractwoker {
public:
	virtual void dowork() = 0;
};

//ר�Ű�����ҵ��Ĺ�����Ա
class dosavewoker: public abstractwoker {
public:
	virtual void dowork() {
		cout << "������ҵ��" << endl;
	}
};

//ר�Ű���֧��ҵ��Ĺ�����Ա
class dopaywoker : public abstractwoker {
public:
	virtual void dowork() {
		cout << "����֧��ҵ��" << endl;
	}
};

//ר�Ű���ת��ҵ��Ĺ�����Ա
class dotransferwoker : public abstractwoker {
public:
	virtual void dowork() {
		cout << "����ת��ҵ��" << endl;
	}
};

//ҵ�������ڳ���㣨����һ�㣬���Ǿ�����ĸ�ҵ��ģ�Ҫ������һ����ҵ��ͺܷ��㣨����չ��ǿ���� abstractwoker* worker
void donework(abstractwoker* worker) {//�������ǳ�����
	worker->dowork();//������д�ɾ�����ĸ�ҵ��Ĺ�����Ա����˲���д��
}

//�ͻ��� ����ָ��ʵ����������󣬴Ӷ��Ϸ����ڴ�
void test() {
	abstractwoker* sw = new dosavewoker;
	donework(sw);
	delete sw;

	abstractwoker* sp = new dopaywoker;
	donework(sp);
	delete sp;

	abstractwoker* st = new dotransferwoker;
	donework(st);
	delete st;
}

int main(void) {
	test();

	system("pause");
	return 0;
}
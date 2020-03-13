//�����ط�������֪ʶԭ��
//����Ҫ�����ϸ�ڣ�����¥����Ϣ��ȫ��¶���ң���¶���ӿ��ࣨ�н飩���Ҿ�����
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class abstractbuilding
{
public:
	virtual void berecommended() = 0;
	virtual string getkind() = 0;
};

//��¥��A
class  buildingA: public abstractbuilding
{
public:
	buildingA() {
		m_sKind = "ѧ����";
	}
	virtual void berecommended() {
		cout << "¥��A�̹�԰" << m_sKind << "���Ƽ�" << endl;
	}
	virtual string getkind() {
		return m_sKind;
	}
public:
	string m_sKind;
};

//��¥��B
class  buildingB : public abstractbuilding
{
public:
	buildingB() {
		m_sKind = "������";
	}
	virtual void berecommended() {
		cout << "¥��B���" << m_sKind << "���Ƽ�" << endl;
	}
	virtual string getkind() {
		return m_sKind;
	}
public:
	string m_sKind;
};

//*****�н��࣬ά������¥�̣����Ⱪ¶�Ľ��
class mediator {
public:
	mediator() {
		abstractbuilding* building = new buildingA;
		vb.push_back(building);
		building = new buildingB;
		vb.push_back(building);
	}

	//�����ṩ�Ľӿ�
	abstractbuilding* findmybuilding(string kind) {
		for (vector<abstractbuilding*>::iterator it = vb.begin(); it != vb.end(); it++) {
			if ((*it)->getkind() == kind) {
				return *it;
			}
		}
		return NULL;
	}

	~mediator() {
		for (vector<abstractbuilding*>::iterator it = vb.begin(); it != vb.end(); it++) {
			if (*it != NULL) {
				delete *it;
			}
		}
	}

public://д���󣬾����д����
	vector<abstractbuilding*> vb;
};

////ֱ�Ӻ�¥�̴򽻵�-������̲�
//void test1() {
//	buildingA* biguiyuan = new buildingA;
//	if (biguiyuan->m_sKind == "ѧ����") {
//		biguiyuan->berecommended();
//	}
//
//	buildingB* wanda = new buildingB;
//	if (wanda->m_sKind == "������") {
//		wanda->berecommended();
//	}
//}

//��ȷ��ʽ ���н�򽻵�������Ҫ֪�������¥����Ϣ
void test2(string info) {
	mediator* m = new mediator;

	abstractbuilding* building = m->findmybuilding(info);
	if (building != NULL) {
		building->berecommended();
	}
	else {
		cout << "û�з���������¥��" << endl;
	}
}


int main(void) {
	string info;
	cout << "��������Ҫ��¥�����ͣ���������/ѧ������" << endl;
	cin >> info;
	test2(info);

	system("pause");
	return 0;
}
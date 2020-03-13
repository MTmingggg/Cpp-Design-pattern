//迪米特法则（最少知识原则）
//不需要把类的细节（所有楼盘信息）全暴露给我，暴露个接口类（中介）给我就行了
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

//新楼盘A
class  buildingA: public abstractbuilding
{
public:
	buildingA() {
		m_sKind = "学区房";
	}
	virtual void berecommended() {
		cout << "楼盘A碧桂园" << m_sKind << "被推荐" << endl;
	}
	virtual string getkind() {
		return m_sKind;
	}
public:
	string m_sKind;
};

//新楼盘B
class  buildingB : public abstractbuilding
{
public:
	buildingB() {
		m_sKind = "海景房";
	}
	virtual void berecommended() {
		cout << "楼盘B万达" << m_sKind << "被推荐" << endl;
	}
	virtual string getkind() {
		return m_sKind;
	}
public:
	string m_sKind;
};

//*****中介类，维护管理楼盘，对外暴露的借口
class mediator {
public:
	mediator() {
		abstractbuilding* building = new buildingA;
		vb.push_back(building);
		building = new buildingB;
		vb.push_back(building);
	}

	//对外提供的接口
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

public://写抽象，具体就写死了
	vector<abstractbuilding*> vb;
};

////直接和楼盘打交道-》反面教材
//void test1() {
//	buildingA* biguiyuan = new buildingA;
//	if (biguiyuan->m_sKind == "学区房") {
//		biguiyuan->berecommended();
//	}
//
//	buildingB* wanda = new buildingB;
//	if (wanda->m_sKind == "海景房") {
//		wanda->berecommended();
//	}
//}

//正确方式 和中介打交道，不需要知道多余的楼盘信息
void test2(string info) {
	mediator* m = new mediator;

	abstractbuilding* building = m->findmybuilding(info);
	if (building != NULL) {
		building->berecommended();
	}
	else {
		cout << "没有符合条件的楼盘" << endl;
	}
}


int main(void) {
	string info;
	cout << "请输入想要的楼盘类型：（海景房/学区房）" << endl;
	cin >> info;
	test2(info);

	system("pause");
	return 0;
}
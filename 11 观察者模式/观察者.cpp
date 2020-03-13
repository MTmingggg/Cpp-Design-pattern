//��Ϊ��-04 �۲���ģʽ
//���������źŵƵı仯����������ΪҲ�������仯��һյ��ͨ�źŵƿ��Կ��ƺܶ೵����Ϊ��
//һ�������Ϊ������ܶ��෢���仯��
//�����ı�Ķ���й۲�Ŀ�꣬�����Զ�֪ͨ�Ķ����ǳ�Ϊ�۲��ߡ�
//�۲�Ŀ����Բ�ֹһ������֪ͨ����Ҳ��ֹһ������˶�Ҫ�������
//�۲�Ŀ��������ӡ�ɾ���۲��ߵ�ָ�롢���ù۲���update��boss����֪ͨÿ��Ӣ�۴ӽ���״̬��Ϊ����״̬��
#include<iostream>
#include<list>
using namespace std;

//����Ӣ�ۣ��۲��ߣ�
class abstractHero {
public:
	virtual void update() = 0;
};

//���������۲�����
class HeroA :public abstractHero {
public:
	HeroA() {
		cout << "Ӣ��A��ߣboss" << endl;
	}

	virtual void update() {
		cout << "Ӣ��Aֹͣߣboss������" << endl;
	}
};

class HeroB :public abstractHero {
public:
	HeroB() {
		cout << "Ӣ��B��ߣboss" << endl;
	}

	virtual void update() {
		cout << "Ӣ��Bֹͣߣboss������" << endl;
	}
};

class HeroC:public abstractHero {
public:
	HeroC() {
		cout << "Ӣ��C��ߣboss" << endl;
	}

	virtual void update() {
		cout << "Ӣ��Cֹͣߣboss������" << endl;
	}
};

class HeroD :public abstractHero {
public:
	HeroD() {
		cout << "Ӣ��D��ߣboss" << endl;
	}

	virtual void update() {
		cout << "Ӣ��Dֹͣߣboss������" << endl;
	}
};

class HeroE :public abstractHero {
public:
	HeroE() {
		cout << "Ӣ��E��ߣboss" << endl;
	}

	virtual void update() {
		cout << "Ӣ��Eֹͣߣboss������" << endl;
	}
};

//����boss���۲�Ŀ�꣩
class abstractBoss {
public:
	virtual void addHero(abstractHero* hero) = 0;//���ӹ۲���
	virtual void deleteHero(abstractHero* hero) = 0;//ɾ���۲���
	virtual void notify() = 0;//֪ͨ�۲���
};

//�����һ��BossA �۲�Ŀ��
class BossA: public abstractBoss{
public:
	//���ӹ۲���
	virtual void addHero(abstractHero* hero) {
		pHeroList.push_back(hero);
	}

	//ɾ���۲���
	virtual void deleteHero(abstractHero* hero) {
		pHeroList.remove(hero);//����ֵɾ��
	}

	//֪ͨ�۲���
	virtual void notify() {
		for (list<abstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); it ++) {//����list��ÿ���۲���
			(*it)->update();
		}
	}

public:
	list<abstractHero*> pHeroList;
};

void test() {
	//��������۲���
	abstractHero* gailun = new HeroA;
	abstractHero* yasuo = new HeroB;
	abstractHero* juhua = new HeroC;
	abstractHero* huangzi = new HeroD;
	abstractHero* timo = new HeroE;

	//�����۲�Ŀ��
	abstractBoss* dalong = new BossA;
	dalong->addHero(gailun);
	dalong->addHero(yasuo);
	dalong->addHero(juhua);
	dalong->addHero(huangzi);
	dalong->addHero(timo);

	cout << "yasuo������" << endl;
	dalong->deleteHero(yasuo);//ɾ���۲���

	cout << "boss����ɱ..." << endl;
	dalong->notify();//֪ͨ����list�еĹ۲��߸���״̬
}

int main(void) {
	test();

	system("pause");
	return 0;
}
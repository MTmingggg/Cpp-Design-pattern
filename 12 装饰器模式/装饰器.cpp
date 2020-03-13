//�ṹ��-04 װ����ģʽ
//�Լ̳е�һ���������һ���ද̬���ӹ���
//Ӣ��----���Ͽ���----�����Ǹ�Ӣ��
#include<iostream>
using namespace std;

//����Ӣ��
class abstractHero {
public:
	virtual void showStatus() = 0;//������Ϊ
public:
	int mHp;//Ѫ��
	int mMp;//����ֵ
	int mAt;//����
	int mDf;//����
};

//����Ӣ��
class HeroA :public abstractHero {
public:
	HeroA() {
		mHp = 1000;//Ѫ��
		mMp = 200;//����ֵ
		mAt = 50;// ����
		mDf = 0;//����
	}
	virtual void showStatus() {
		cout << "Ѫ����" << mHp << endl;
		cout << "����ֵ��" << mMp << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

//װ����װ��� Ӣ�۴���װ����Ӧ�����Ǹ�Ӣ��
class abstractequipment : public abstractHero {//Ҫ����Ӣ��ԭ����״̬
public:
	abstractequipment(abstractHero* hero) {
		pHero = hero;
	}

	virtual void showStatus() = 0;
public:
	abstractHero* pHero;
};

//��ͽ
class kuangtu :public abstractequipment {
public:
	kuangtu(abstractHero* hero):abstractequipment(hero){

	}

	//���ӵĶ��⹦��
	void addKuangtu() {
		cout << "װ���˿�ͽ֮��..." << endl;
		mHp = pHero->mHp + 800;
		mMp = pHero->mMp;
		mAt = pHero->mAt;
		mDf = pHero->mDf + 40;
	}

	virtual void showStatus() {
		addKuangtu();
		cout << "Ѫ����" << mHp << endl;
		cout << "����ֵ��" << mMp << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

//�޾�
class wujin :public abstractequipment {
public:
	wujin(abstractHero* hero):abstractequipment(hero){

	}

	//���ӵĶ��⹦��
	void addWujin() {
		cout << "װ�����޾�֮��..." << endl;
		mHp = pHero->mHp;
		mMp = pHero->mMp;
		mAt = pHero->mAt +20;
		mDf = pHero->mDf;
	}

	virtual void showStatus() {
		addWujin();
		cout << "Ѫ����" << mHp << endl;
		cout << "����ֵ��" << mMp << endl;
		cout << "������" << mAt << endl;
		cout << "������" << mDf << endl;
	}
};

int main(void) {
	abstractHero* gailun = new HeroA;
	gailun->showStatus();
	cout << "------" << endl;
	//���˿�ͽ
	gailun = new kuangtu(gailun);
	gailun->showStatus();
	cout << "------" << endl;
	//�����޾�
	gailun = new wujin(gailun);
	gailun->showStatus();

	system("pause");
	return 0;
}
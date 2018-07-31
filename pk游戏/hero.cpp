#include"hero.h"
#include"filemanager.h"
Hero::Hero(int heroId)
{
	FileManager fm;
	map<string, map<string, string>> mHeroData;
	fm.loadCSVData("Hero.csv", mHeroData);
	//heroId,heroName,heroHp,heroAtk,heroDef,heroInfo
	string id = mHeroData[to_string(heroId)]["heroId"];

	this->heroName = mHeroData[id]["heroName"];
	this->heroInfo = mHeroData[id]["heroInfo"];

	this->heroHp = atoi(mHeroData[id]["heroHp"].c_str());
	this->heroAtk = atoi(mHeroData[id]["heroAtk"].c_str());
	this->heroDef = atoi(mHeroData[id]["heroDef"].c_str());

	this->weapon = NULL;
}

void Hero::equipWeapon(Weapon * weapon)
{
	if (weapon == NULL)
	{
		cout << "���6" << endl;
		return;
	}

	this->weapon = weapon;
}

void Hero::attack(Monster * monster)
{
	int damage = 0;
	int isFronzen = 0;//����
	//�ж�Ӣ����û������
	if (this->weapon==NULL)//û��
	{
		damage = this->heroAtk;
	}
	else
	{
		damage = this->heroAtk + this->weapon->baseDamage;

		//����Ч��
		int crit = 0;//����
		int addHp = 0;//��Ѫ
		

		//�õ������ı���
		crit = this->weapon->getCrit();
		//�õ���Ѫ
		addHp = this->weapon->getSuckBlood();
		//�õ�����
		isFronzen = this->weapon->getFrozen();


		if (crit)
		{
			cout << "Ӣ�۴����˱���Ч��" << endl;
			damage += crit;
		}

		if (addHp)
		{
			cout << "Ӣ�۴�������ѪЧ��������" << addHp << "Ѫ��" << endl;
			this->heroHp += addHp;
		}

		if (isFronzen)
		{
			cout << "Ӣ�۴����˱���Ч��,����<" << monster->monsterName << ">ֹͣһ�غϹ���!" << endl;
			
		}
	}
	monster->isFronzen = isFronzen;
	int trueDamage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;

	monster->monsterHp -= trueDamage;
	cout << "Ӣ��<" << this->heroName << ">�����˹���<" << monster->monsterName << ">���" << trueDamage << "�˺�" << endl;

}

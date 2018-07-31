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
		cout << "你狠6" << endl;
		return;
	}

	this->weapon = weapon;
}

void Hero::attack(Monster * monster)
{
	int damage = 0;
	int isFronzen = 0;//冰冻
	//判断英雄有没有武器
	if (this->weapon==NULL)//没有
	{
		damage = this->heroAtk;
	}
	else
	{
		damage = this->heroAtk + this->weapon->baseDamage;

		//各种效果
		int crit = 0;//暴击
		int addHp = 0;//吸血
		

		//得到武器的暴击
		crit = this->weapon->getCrit();
		//得到吸血
		addHp = this->weapon->getSuckBlood();
		//得到冰冻
		isFronzen = this->weapon->getFrozen();


		if (crit)
		{
			cout << "英雄触发了暴击效果" << endl;
			damage += crit;
		}

		if (addHp)
		{
			cout << "英雄触发了吸血效果，增加" << addHp << "血量" << endl;
			this->heroHp += addHp;
		}

		if (isFronzen)
		{
			cout << "英雄触发了冰冻效果,怪物<" << monster->monsterName << ">停止一回合攻击!" << endl;
			
		}
	}
	monster->isFronzen = isFronzen;
	int trueDamage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;

	monster->monsterHp -= trueDamage;
	cout << "英雄<" << this->heroName << ">攻击了怪物<" << monster->monsterName << ">造成" << trueDamage << "伤害" << endl;

}

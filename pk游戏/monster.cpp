#include"monster.h"
#include"filemanager.h"
#include"hero.h"
Monster::Monster(int monsterId)
{
	FileManager fm;
	map<string, map<string, string>> mMonsterData;
	fm.loadCSVData("Monsters.csv", mMonsterData);
	//monsterId,monsterName,monsterAtk,monsterDef,monsterHp
	string id = mMonsterData[to_string(monsterId)]["monsterId"];
	this->monsterName = mMonsterData[id]["monsterName"];
	this->monsterAtk = atoi(mMonsterData[id]["monsterAtk"].c_str());
	this->monsterDef = atoi(mMonsterData[id]["monsterDef"].c_str());
	this->monsterHp = atoi(mMonsterData[id]["monsterHp"].c_str());
	this->isFronzen = false;

}

void Monster::attack(Hero * hero)
{
	if (this->isFronzen)
	{
		return;
	}
	//ÉËº¦
	int damage = 0;
	damage = (this->monsterAtk - hero->heroDef)>0?(this->monsterAtk - hero->heroDef):1;

	//¹¥»÷Ó¢ĞÛ
	hero->heroHp = hero->heroHp - damage;

	cout << "¹ÖÎï<" << this->monsterName << ">¹¥»÷ÁËÓ¢ĞÛÔì³ÉÁË" << damage << "ÉËº¦£¡" << endl;
}

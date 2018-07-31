#include"DragonSword.h"
#include"filemanager.h"
DragonSword::DragonSword()
{
	//从武器文件中获取小刀的信息
	//weaponId,weaponName,weaponAtk,weaponCritPlus,weaponCritRate,weaponSuckPlus,weaponSuckRate,weaponFrozenRate
	FileManager fm;
	map<string, map<string, string>> mWeaponData;
	fm.loadCSVData("Weapons.csv", mWeaponData);

	string id = mWeaponData["3"]["weaponId"];
	this->weaponName = mWeaponData[id]["weaponName"];
	this->baseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str());
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str());
	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str());
	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());
	this->suckRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str());
	this->frozenRate = atoi(mWeaponData[id]["weaponFrozenRate"].c_str());
}

int DragonSword::getBaseDamage()
{
	return this->baseDamage;
}

int DragonSword::getCrit()
{
	if (isTrigger(this->critRate))
	{
		return this->baseDamage*this->critPlus;
	}
	return 0;
}

int DragonSword::getSuckBlood()
{
	if (isTrigger(this->suckRate))
	{
		return this->baseDamage*this->suckPlus;
	}
	return 0;
}

int DragonSword::getFrozen()
{
	if (isTrigger(this->frozenRate))
	{
		return 1;
	}
	return 0;
}

bool DragonSword::isTrigger(int rate)
{
	int num = rand() % 100 + 1;//1~100
	if (num < rate)
	{
		return true;
	}
	return false;
}

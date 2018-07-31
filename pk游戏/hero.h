#pragma once
#include<iostream>
#include"weapon.h"
#include"monster.h"
using namespace std;
class Hero
{
public:
	//heroId,heroName,heroHp,heroAtk,heroDef,heroInfo
	string heroName;
	string heroInfo;

	int heroHp;
	int heroAtk;
	int heroDef;

	Weapon *weapon;
	//构造
	Hero(int heroId);
	//装备武器
	void equipWeapon(Weapon *weapon);
	//攻击怪物
	void attack(Monster *monster);
};
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
	//����
	Hero(int heroId);
	//װ������
	void equipWeapon(Weapon *weapon);
	//��������
	void attack(Monster *monster);
};
#pragma once
#include<iostream>
using namespace std;
class Hero;
class Monster
{
public:
	//monsterId,monsterName,monsterAtk,monsterDef,monsterHp
	string monsterName;
	int monsterAtk;//¹¥»÷
	int monsterDef;//·ÀÓù
	int monsterHp;//ÑªÁ¿
	int isFronzen;//±ù¶³

	//¹¹Ôìº¯Êý
	Monster(int monsterId);

	//¹¥»÷ Ó¢ÐÛ
	void attack(Hero *hero);

};
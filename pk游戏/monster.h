#pragma once
#include<iostream>
using namespace std;
class Hero;
class Monster
{
public:
	//monsterId,monsterName,monsterAtk,monsterDef,monsterHp
	string monsterName;
	int monsterAtk;//����
	int monsterDef;//����
	int monsterHp;//Ѫ��
	int isFronzen;//����

	//���캯��
	Monster(int monsterId);

	//���� Ӣ��
	void attack(Hero *hero);

};
#pragma once
#pragma once
#include<iostream>
#include"weapon.h"
using namespace std;
class BoardSword :public Weapon
{
public:
	//���캯��
	BoardSword();
	//��ȡ�����˺�
	virtual int getBaseDamage();
	//����Ч�� ����ֵ����0 ��������
	virtual int getCrit();
	//��ȡ��Ѫ ����ֵ����0 ������Ѫ
	virtual int getSuckBlood();
	//����Ч�� ����true �������
	virtual int getFrozen();

	//��������
	virtual bool isTrigger(int rate);
};
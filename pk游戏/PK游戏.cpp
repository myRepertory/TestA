#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"filemanager.h"
#include<string>
#include<map>
#include<algorithm>
#include"hero.h"
#include"knife.h"
#include"boardSword.h"
#include"DragonSword.h"
#include<ctime>

using namespace std;
void fighting();
int main(int *argc, char *argv[])
{
	srand(time(NULL));
	fighting();
	
	system("pause");
	return EXIT_SUCCESS;
}
void fighting()
{
	cout << "欢迎来到召唤师峡谷" << endl;
	cout << "请选择你的英雄:" << endl;
	FileManager fm;

	map<string, map<string, string>> mHeroData;
	fm.loadCSVData("Hero.csv", mHeroData);
	//heroId,heroName,heroHp,heroAtk,heroDef,heroInfo
	for (size_t i = 0; i < mHeroData.size(); i++)
	{
		cout << mHeroData[to_string(i + 1)]["heroId"] << " " << mHeroData[to_string(i + 1)]["heroName"] << " "\
			<< mHeroData[to_string(i + 1)]["heroInfo"] << endl;
	}

	int select = 0;
	cin >> select;
	getchar();//清掉回车

	Hero hero(select);
	cout << "你选的英雄:" << hero.heroName << endl;

	map<string, map<string, string>> mWeaponData;
	fm.loadCSVData("Weapons.csv", mWeaponData);
	cout << "请为你的英雄装备武器:" << endl;
	cout << "1、赤手空拳" << endl;
	for (size_t i = 0; i < mWeaponData.size(); i++)
	{
		cout << i + 2 << "、" << mWeaponData[to_string(i + 1)]["weaponName"] << endl;
	}

	cin >> select;
	getchar();//清掉回车
	Weapon *weapon = NULL;
	switch (select)
	{
	case 1:
		break;
	case 2:
		weapon = new Knife;
		break;
	case 3:
		weapon = new BoardSword;
		break;
	case 4:
		weapon = new DragonSword;
		break;
	}
	//英雄装备武器
	hero.equipWeapon(weapon);
	if(weapon != NULL)
		cout << "英雄<" << hero.heroName << ">装备了武器<" << weapon->weaponName <<">!"<< endl;
	
	//随机创建一个怪物
	map<string, map<string, string>> mMonsterData;
	fm.loadCSVData("Monsters.csv", mMonsterData);
	int id = rand() % mMonsterData.size()+1;//1~5

	Monster monster(id);

	//互殴开始
	int index = 0;
	while (true)
	{
		index++;
		system("cls");
		cout << "-------------第" << index << "回合-------" << endl;
		
		

		//英雄打怪物
		if (hero.heroHp>0)
		{
			hero.attack(&monster);
		}
		else
		{
			cout << "英雄挂了" << endl;
			break;
		}

		//怪物攻击英雄
		if (monster.monsterHp>0)
		{
			monster.attack(&hero);
		}
		else
		{
			cout << "恭喜你过关" << endl;
			break;
		}
		
		
		cout << "英雄<" << hero.heroName << ">的血量为:" << hero.heroHp << endl;
		cout << "怪物<" << monster.monsterName << ">的血量为:" << monster.monsterHp << endl;

		
		
		getchar();

	}

}
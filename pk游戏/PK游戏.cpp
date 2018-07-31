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
	cout << "��ӭ�����ٻ�ʦϿ��" << endl;
	cout << "��ѡ�����Ӣ��:" << endl;
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
	getchar();//����س�

	Hero hero(select);
	cout << "��ѡ��Ӣ��:" << hero.heroName << endl;

	map<string, map<string, string>> mWeaponData;
	fm.loadCSVData("Weapons.csv", mWeaponData);
	cout << "��Ϊ���Ӣ��װ������:" << endl;
	cout << "1�����ֿ�ȭ" << endl;
	for (size_t i = 0; i < mWeaponData.size(); i++)
	{
		cout << i + 2 << "��" << mWeaponData[to_string(i + 1)]["weaponName"] << endl;
	}

	cin >> select;
	getchar();//����س�
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
	//Ӣ��װ������
	hero.equipWeapon(weapon);
	if(weapon != NULL)
		cout << "Ӣ��<" << hero.heroName << ">װ��������<" << weapon->weaponName <<">!"<< endl;
	
	//�������һ������
	map<string, map<string, string>> mMonsterData;
	fm.loadCSVData("Monsters.csv", mMonsterData);
	int id = rand() % mMonsterData.size()+1;//1~5

	Monster monster(id);

	//��Ź��ʼ
	int index = 0;
	while (true)
	{
		index++;
		system("cls");
		cout << "-------------��" << index << "�غ�-------" << endl;
		
		

		//Ӣ�۴����
		if (hero.heroHp>0)
		{
			hero.attack(&monster);
		}
		else
		{
			cout << "Ӣ�۹���" << endl;
			break;
		}

		//���﹥��Ӣ��
		if (monster.monsterHp>0)
		{
			monster.attack(&hero);
		}
		else
		{
			cout << "��ϲ�����" << endl;
			break;
		}
		
		
		cout << "Ӣ��<" << hero.heroName << ">��Ѫ��Ϊ:" << hero.heroHp << endl;
		cout << "����<" << monster.monsterName << ">��Ѫ��Ϊ:" << monster.monsterHp << endl;

		
		
		getchar();

	}

}
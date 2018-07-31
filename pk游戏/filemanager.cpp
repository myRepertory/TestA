#include"filemanager.h"
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
void FileManager::parseLineToVector(string line, vector<string>& v)
{
	int start = 0;
	int ret = 0;

	while (true)
	{
		ret = line.find(",", start);
		if (ret == -1)
		{
			string tmp = line.substr(start, line.size() - start);
			v.push_back(tmp);
			break;
		}
		string tmp = line.substr(start, ret - start);
		v.push_back(tmp);

		start = ret + 1;
	}
}
void FileManager::loadCSVData(string path, map<string, map<string, string>> &m)
{
	ifstream ifs;
	ifs.open(path, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	string firstLine;
	ifs >> firstLine;

	//�洢��һ�е��Ӵ�
	//heroId,heroName,heroHp,heroAtk,heroDef,heroInfo
	vector<string> vFirst;
	parseLineToVector(firstLine, vFirst);

	//����������
	//1,��ɪ,500,10,30,Ѫ�����
	string line;
	while (ifs >>line)
	{
		vector<string> vOther;
		parseLineToVector(line, vOther);

		//mTmp�洢һ��Ӣ����Ϣ
		map<string, string> mTmp;

		for (size_t i = 0; i < vFirst.size(); i++)
		{
			mTmp.insert(make_pair(vFirst[i], vOther[i]));
		}
		m.insert(make_pair(vOther[0], mTmp));

	}
}

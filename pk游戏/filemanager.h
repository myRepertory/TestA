#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class FileManager {
public:
	void parseLineToVector(string line, vector<string> &v);
	void loadCSVData(string path, map<string, map<string, string>> &m);
};
#pragma once

#include <map>
#include <string>

using namespace std;

class Dictionary
{
private:
	static const string delimiter;

private:
	std::map<string, string> map;
	string filename;

public:
	Dictionary(const char* filename);
	~Dictionary();

protected:
	pair<string, string> ParseLine(string line);
	string ComposeLine(string k, string v);

public:
	void PrintAll();
	void ReadFile(string filename = "");
	void SaveFile(string filename="");
	string FindWord(string word);
	void AddWord(string word, string def);
};


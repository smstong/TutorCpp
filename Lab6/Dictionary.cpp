#include "Dictionary.h"
#include "StringHelper.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

const string Dictionary::delimiter = ":";

Dictionary::Dictionary(const char* filename)
{
	this->ReadFile(filename);
}

Dictionary::~Dictionary()
{
	this->SaveFile();
}

void Dictionary::ReadFile(string filename)
{
	if (filename == "") {
		filename = this->filename;
	}
	else
	{
		this->filename = filename;
	}
	ifstream ifs(filename);
	string line;
	while (getline(ifs, line)) {
		this->map.insert(this->ParseLine(line));
	}
	ifs.close();
}

void Dictionary::PrintAll()
{
	cout << "Your dictionary has " << this->map.size() << " words.\n";
	int i = 0;
	cout << endl;
	for (auto it = map.begin(); it != map.end(); it++, i++) {
		cout << setw(3) <<setfill('0') << i + 1 << " ";
		cout << it->first << ": " << it->second << endl;
	}
	cout << endl;
}

pair<string, string> Dictionary::ParseLine(string line)
{
	int mark = line.find(Dictionary::delimiter);

	string key = line.substr(0, mark);
	string value = line.substr(mark + Dictionary::delimiter.length());

	key = StringHelper::ToLower(StringHelper::Trim(key));
	value = StringHelper::Trim(value);

	return make_pair(key, value);
}

string Dictionary::ComposeLine(string k, string v)
{
	return k + Dictionary::delimiter + v;
}

void Dictionary::SaveFile(string filename)
{
	if (filename == "") {
		filename = this->filename;
	}
	ofstream ofs(this->filename);
	for (auto i : this->map) {
		string line = this->ComposeLine(i.first, i.second);
		ofs << line << endl;
	}
	ofs.close();
}

string Dictionary::FindWord(string word)
{
	word = StringHelper::ToLower(StringHelper::Trim(word));
	auto it = this->map.find(word);
	if (it == this->map.end()) {
		return "";
	}
	return it->second;
}
void Dictionary::AddWord(string word, string def)
{
	word = StringHelper::ToLower(StringHelper::Trim(word));
	this->map[word] = def;
}
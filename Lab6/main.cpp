#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "Dictionary.h"
#include "StringHelper.h"
#include "UserInput.h"

using namespace std;

enum MenuItems {
	MenuPrintAll = 1,
	MenuFindWord,
	MenuAddWord,
	MenuExit
};

int menu()
{
	static const map<int, string> menuItems = {
		{MenuItems::MenuPrintAll,  "Print dictionary"},
		{MenuItems::MenuFindWord, "Find word definition"},
		{MenuItems::MenuAddWord, "Enter new word and definition"},
		{MenuItems::MenuExit, "Exit"},
	};
	cout << "=========================================\n";
	for (auto i : menuItems) {
		cout << i.first << " - " + i.second << endl;
	}

	cout << "=========================================\n";
	cout << "Please select a menu item: ";
	return UserInput::GetInt();
}
int main(int argc, char** argv)
{
	Dictionary* dic = new Dictionary("directory.txt");
	if (dic == nullptr) {
		cout << "memoery low" << endl;
		exit(1);
	}

	int slectedItem = 0;
	while ((slectedItem = menu()) != MenuItems::MenuExit) {
		switch (slectedItem) {
		case MenuItems::MenuPrintAll:
			dic->PrintAll();
			break;
		case MenuItems::MenuFindWord:
		{
			cout << "Please enter the word to find: ";
			string word = UserInput::GetWord();
			string def = dic->FindWord(word);
			if (def.empty()) {
				cout << "The word doesn't exit" << endl;
			}
			else {
				cout << def << endl;
			}
			break;
		}
		case MenuItems::MenuAddWord:
		{
			cout << "Please enter the word to add: ";
			string word;
			while (true) {
				word = UserInput::GetWord();
				if (dic->FindWord(word).empty()) {
					break;
				}
				cout << word << "already exists! Enter a new one: ";
			}
			string def;
			cout << "Plase enter the definition: ";
			def = UserInput::GetLine();
			def = StringHelper::Trim(def);
			if (def.empty()) {
				cout << "definition cannot be empty!" << endl;
				break;
			}
			dic->AddWord(word, def);
			dic->SaveFile();
			cout << "Your new word" << word << "has been added." << endl;
			break;
		}
		default:
			break;
		}
	}

	delete dic;
	return 0;
}
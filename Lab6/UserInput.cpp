#include "UserInput.h"
#include <iostream>

string UserInput::GetWord()
{
	string word;
	cin >> word;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return word;
}
string UserInput::GetLine()
{
	string line;
	std::getline(cin, line);
	return line;
}
int UserInput::GetInt()
{
	int n;
	while (true) {
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a integer: ";
			continue;
		}
		break;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return n;
}
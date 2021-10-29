#include "StringHelper.h"

string StringHelper::ToUpper(string str)
{
	string newStr;
	for (string::size_type i = 0; i < str.length(); i++) {
		newStr += toupper(str[i]);
	}
	return newStr;
}
string StringHelper::ToLower(string str)
{
	string newStr;
	for (string::size_type i = 0; i < str.length(); i++) {
		newStr += tolower(str[i]);
	}
	return newStr;
}
string StringHelper::LeftTrim(string str)
{
	string newStr;
	bool ok = false;
	for (auto i : str) {
		if (!std::isspace(i)) {
			ok = true;
		}
		if (ok) {
			newStr += i;
		}
	}
	return newStr;
}
string StringHelper::RightTrim(string str)
{
	string newStr;
	bool ok = false;
	for (auto i = str.rbegin(); i != str.rend(); i++) {
		if (!std::isspace(*i)) {
			ok = true;
		}
		if (ok) {
			newStr.insert(newStr.begin(), *i);
		}
	}
	return newStr;
}
string StringHelper::Trim(string str)
{
	return RightTrim(LeftTrim(str));
}

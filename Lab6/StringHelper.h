#pragma once
#include <string>
using namespace std;

class StringHelper
{
public:
	static string ToUpper(string str);
	static string ToLower(string str);
	static string LeftTrim(string str);
	static string RightTrim(string str);
	static string Trim(string str);
};


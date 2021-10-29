#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include <deque>
#include <string>

using namespace std;

void vector_test()
{
	deque<int> v;
	v.push_back(200);
	v.insert(v.begin(), 100);

	for (auto i = v.begin(); i != v.end(); i++) {
		cout << *i << endl;
	}
}

void map_test()
{
	map<string, string> m;
	m["k1"] = "v1";
	m.insert(make_pair("k2", "v2"));

	//for (auto i = m.begin(); i != m.end(); i++) {
	//	cout << i->first << endl;
	//}

	for (auto i : m) {
		cout << i.first << "=" << i.second << endl;
	}
	cout << m["k1"] << endl;
}

int main(int argc, char** argv)
{
	//vector_test();
	//map_test();
	string str;
	getline(cin, str);
	cout << str;

	return 0;
}
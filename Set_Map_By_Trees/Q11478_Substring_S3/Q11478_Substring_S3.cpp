#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <list>

using namespace std;

int main() {

	string in;
	cin >> in;

	set<string> hset;

	for (int i = 0; i < in.length(); i++) {
		string temp = "";
		for (int j = i; j < in.length(); j++) {
			temp += in[j];
			hset.insert(temp);
		}
	}

	cout << hset.size();

}
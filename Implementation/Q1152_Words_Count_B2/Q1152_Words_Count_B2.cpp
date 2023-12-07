#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main() {

	string str;
	getline(cin, str);

	int out = 1;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			out++;
		}
	}

	if (str[0] == ' ') {
		out--;
		if (str.length() == 1) {
			out = 0;
		}
	}
	if (str.length() != 1 && str[str.length() - 1] == ' ') {
		out--;
	}

	cout << out;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main() {

	string str;
	string out = "";

	while (true) {
		getline(cin, str);
		if (str == "") {
			break;
		}
		out = out + str + "\n";
	}

	cout << out;


}
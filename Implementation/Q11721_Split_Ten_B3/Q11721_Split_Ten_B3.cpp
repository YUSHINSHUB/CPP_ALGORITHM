#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	string s;
	cin >> s;
	int index = 0;

	for (int i = 0; i < (s.length() / 10) + 1; i++) {
		for (int z = 0; z < 10; z++) {
			if (index == s.length()) {
				break;
			}
			cout << s[(i * 10) + z];
			index++;
		}
		cout << endl;
	}

}
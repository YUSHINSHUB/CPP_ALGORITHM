#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string s;
	cin >> s;
	int res = 1;

	for (int i = 0; i <= s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			res = 0;
			break;
		}
	}

	cout << res;
}

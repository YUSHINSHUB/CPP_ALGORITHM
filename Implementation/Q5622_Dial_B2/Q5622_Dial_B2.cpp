#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string s;

	cin >> s;

	int res = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'C') {
			res += 3;
		}
		else if (s[i] >= 'D' && s[i] <= 'F') {
			res += 4;
		}
		else if (s[i] >= 'G' && s[i] <= 'I') {
			res += 5;
		}
		else if (s[i] >= 'J' && s[i] <= 'L') {
			res += 6;
		}
		else if (s[i] >= 'M' && s[i] <= 'O') {
			res += 7;
		}
		else if (s[i] >= 'P' && s[i] <= 'S') {
			res += 8;
		}
		else if (s[i] >= 'T' && s[i] <= 'V') {
			res += 9;
		}
		else if (s[i] >= 'W' && s[i] <= 'Z') {
			res += 10;
		}
	}

	cout << res;

}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	string s;
	int res = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		res = 0;
		cnt = 0;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') {
				cnt++;
				res += cnt;
			}
			else {
				cnt = 0;
			}
		}

		cout << res << "\n";
	}


}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

	int l, c;
	cin >> l >> c;

	vector<char> alp(c);
	vector<int> cnt(l);

	for (int i = 0; i < c; i++) {
		cin >> alp[i];
	}

	for (int i = 0; i < l; i++) {
		cnt[i] = i;
	}

	sort(begin(alp), end(alp));
	bool end = false;

	bool pass = true;

	int c1 = 0, c2 = 0;

	while (true) {
		c1 = 0;
		c2 = 0;
		for (int i = 0; i < l; i++) {
			if (alp[cnt[i]] == 'a' || alp[cnt[i]] == 'e' || alp[cnt[i]] == 'i' || alp[cnt[i]] == 'o' || alp[cnt[i]] == 'u') {
				c1++;
			}
			else {
				c2++;
			}
			if (c1 >= 1 && c2 >= 2) {
				pass = false;
				break;
			}
		}
		if (pass == false) {
			for (int i = 0; i < l; i++) {
				cout << alp[cnt[i]];

			}
			cout << "\n";
		}

		pass = true;
		cnt[l - 1]++;
		if (cnt[l - 1] >= c) {
			cnt[l - 1]--;
			int temp = l - 2;
			while (cnt[temp] == cnt[temp + 1] - 1) {
				temp--;
				if (temp == -1) {
					end = true;
					break;
				}
			}
			if (end == false) {
				cnt[temp]++;
				for (int i = temp + 1; i < l; i++) cnt[i] = cnt[i - 1] + 1;
			}
			else {
				break;
			}
		}
	}

}
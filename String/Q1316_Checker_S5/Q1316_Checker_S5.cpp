#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {

	int n;
	cin >> n;
	int res = 0;
	bool chk[26];

	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 26; i++) {
			chk[i] = true;
		}
		bool boo = true;
		string in;
		cin >> in;
		chk[in[0] - 97] = false;
		for (int z = 1; z < in.length(); z++) {
			if (in[z] != in[z - 1] && chk[in[z] - 97] == false) {
				boo = false;
				break;
			}
			else {
				chk[in[z] - 97] = false;
			}
		}
		if (boo == true) {
			res++;
		}
	}

	cout << res;
}

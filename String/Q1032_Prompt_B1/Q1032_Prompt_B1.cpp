#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string>in(n);

	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}

	string res = "";

	for (int i = 0; i < in[0].length(); i++) {
		res += in[0][i];
		for (int z = 1; z < n; z++) {
			if (in[z][i] != res[i]) {
				res[i] = '?';
				break;
			}
		}
	}

	cout << res;


}
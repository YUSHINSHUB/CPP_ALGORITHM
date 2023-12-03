#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int m, n;
	cin >> m >> n;

	int high = max(m, n);

	vector<bool> pri(high + 1);
	pri[0] = true;
	if (high >= 1) pri[1] = true;
	if (high >= 2) pri[2] = false;

	for (int i = 4; i <= high; i += 2) pri[i] = true;

	for (int i = 3; i <= high; i += 2) {
		if (pri[i] == false) {
			for (int z = i * 2; z <= high; z += i) pri[z] = true;
		}
	}
	int sum = 0;
	int res = 0;

	for (int i = min(m, n); i <= high; i++) {
		if (pri[i] == false) {
			sum += i;
			if (res == 0) {
				res = i;
			}
		}
	}

	if (sum == 0) cout << "-1";
	else cout << sum << "\n" << res;


}
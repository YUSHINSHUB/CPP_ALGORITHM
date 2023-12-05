#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


int main() {

	int t;
	cin >> t;
	long long n = 0, m = 0, r = 0;
	long long res = 1;

	for (int i = 0; i < t; i++) {
		res = 1;
		cin >> n >> m;
		r = m - n;
		if (r == 0) r = 1;

		for (long z = max(r, n) + 1; z <= m; z++) {
			res *= z;
		}

		if (r >= n) {
			for (long z = 2; z <= n; z++) {
				res /= z;
			}
		}
		else {
			for (long z = 2; z <= r; z++) {
				res /= z;
			}
		}

		cout << res << "\n";
	}

}
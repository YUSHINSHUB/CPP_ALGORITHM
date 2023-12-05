#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int idx = 0;
	int res = 0;

	for (int i = 1; i <= n; i++) {

		if (n % i == 0) idx++;
		if (idx == k) {
			res = i;
			break;
		}

	}

	cout << res;

}
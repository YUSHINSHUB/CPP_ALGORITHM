#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	long long res[91];
	res[0] = 0;
	res[1] = 1;

	for (int i = 2; i <= n; i++) {
		res[i] = res[i - 1] + res[i - 2];
	}

	cout << res[n];

}

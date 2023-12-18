#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int k;
	cin >> n >> k;
	vector<int> coin(n);

	int out = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}


	for (int i = n - 1; i >= 0; i--) {
		out += k / coin[i];
		k %= coin[i];
	}

	cout << out;

}
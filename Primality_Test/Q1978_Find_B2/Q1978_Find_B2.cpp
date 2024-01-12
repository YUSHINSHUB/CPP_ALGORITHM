#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	int res = 0;

	bool pri[1001] = {};
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	pri[0] = true;
	pri[1] = true;

	for (int i = 2; i < 1001; i++) {
		if (pri[i] != true) {
			int z = i * 2;
			while (z <= 1000) {
				pri[z] = true;
				z += i;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (pri[nums[i]] != true) {
			res++;
		}
	}

	cout << res;

}
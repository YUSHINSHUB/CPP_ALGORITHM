#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;


int main() {


	int n;
	cin >> n;
	vector<int> nums(n);
	int m = 0;


	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		m = max(m, nums[i]);

	}

	vector<int> dp(m + 1);
	int cnt = 0;
	int res = 0;

	for (int i = n - 1; i >= 0; i--) {
		cnt = 0;
		for (int z = nums[i] + 1; z <= m; z++) {
			cnt = max(cnt, dp[z]);
		}
		dp[nums[i]] = cnt + 1;
		res = max(res, dp[nums[i]]);
	}


	cout << res;
}
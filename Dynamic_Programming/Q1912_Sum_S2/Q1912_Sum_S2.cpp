﻿#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int res = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (dp[i] > res)
			res = dp[i];
	}

	cout << res;

}

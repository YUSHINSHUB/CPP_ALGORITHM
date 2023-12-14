#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int dp[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		cout << dp[temp] << "\n";
	}


}
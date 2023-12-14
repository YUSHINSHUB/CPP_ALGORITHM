#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

static int dp[1001];

static int recur(int n) {

	if (dp[n] == 0) {
		dp[n] = recur(n - 1) + recur(n - 2);
	}

	return dp[n] % 10007;
}

int main() {

	dp[1] = 1;
	dp[2] = 2;

	int n;
	cin >> n;
	n = recur(n);

	cout << n;
}
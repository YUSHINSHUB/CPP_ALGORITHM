#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

static long dp[201][201];
static bool chk[201][201];

static long recur(int a, int b) {
	if (chk[a][b] != true) {
		dp[a][b] = 0;
		for (int i = 0; i <= b; i++) {
			if (chk[a - 1][i] == true) {
				dp[a][b] += dp[a - 1][i];
			}
			else {
				dp[a][b] += recur(a - 1, i);
			}
			if (dp[a][b] >= 1000000000)
				dp[a][b] %= 1000000000;
		}
		chk[a][b] = true;
	}
	else {
		return dp[a][b];
	}

	return dp[a][b];
}



int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
		chk[1][i] = true;
	}

	long res = recur(k, n);

	cout << res;
}
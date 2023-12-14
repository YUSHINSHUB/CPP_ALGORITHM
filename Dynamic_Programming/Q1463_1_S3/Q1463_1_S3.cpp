#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

static int dp[1000001];
static bool chk[1000001];
static int task(int a) {

	if (chk[a] == false) {
		if (a % 6 == 0) {
			dp[a] = min(task(a - 1), min(task(a / 3), task(a / 2))) + 1;
		}
		else if (a % 3 == 0) {
			dp[a] = min(task(a / 3), task(a - 1)) + 1;
		}
		else if (a % 2 == 0) {
			dp[a] = min(task(a / 2), task(a - 1)) + 1;
		}
		else {
			dp[a] = task(a - 1) + 1;
		}
	}

	chk[a] = true;
	return dp[a];
}

int main() {

	int n;
	cin >> n;
	dp[1] = 0;
	chk[1] = true;

	cout << task(n);

}
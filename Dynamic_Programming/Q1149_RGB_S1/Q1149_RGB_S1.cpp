#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int dp[3001];

int recur(vector<int> fee, int cnt) {

	while (cnt >= 0) {
		dp[cnt * 3] = fee[cnt * 3] + min(dp[(cnt + 1) * 3 + 1], dp[(cnt + 1) * 3 + 2]);
		dp[cnt * 3 + 1] = fee[cnt * 3 + 1] + min(dp[(cnt + 1) * 3 + 0], dp[(cnt + 1) * 3 + 2]);
		dp[cnt * 3 + 2] = fee[cnt * 3 + 2] + min(dp[(cnt + 1) * 3 + 0], dp[(cnt + 1) * 3 + 1]);
		cnt--;
	}

	return min(dp[0], min(dp[1], dp[2]));

}

int main() {

	int n;
	cin >> n;
	vector<int> fee(n * 3);

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < 3; z++) {
			cin >> fee[i * 3 + z];
		}
	}

	dp[(n - 1) * 3 + 0] = fee[(n - 1) * 3 + 0];
	dp[(n - 1) * 3 + 1] = fee[(n - 1) * 3 + 1];
	dp[(n - 1) * 3 + 2] = fee[(n - 1) * 3 + 2];

	int cnt = (n - 2);

	int res = recur(fee, cnt);

	cout << res;

}

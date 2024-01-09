#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

	int n;

	cin >> n;

	vector<int> stair(n);
	vector<int> maxv(n);

	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}

	maxv[0] = stair[0];

	if (n > 1) {
		maxv[1] = stair[0] + stair[1];
	}

	if (n > 2) {
		maxv[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	}

	if (n > 3) {
		for (int i = 3; i < n; i++) {
			maxv[i] = max(maxv[i - 3] + stair[i - 1] + stair[i], maxv[i - 2] + stair[i]);
		}
	}

	cout << maxv[n - 1];

}
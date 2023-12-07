#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int m, n;
	cin >> m >> n;

	vector<int> num(m + 1);

	priority_queue<int, vector<int>, less<int>> q;

	for (int i = 0; i < m; i++) {
		cin >> num[i];
	}

	for (int x = 0; x < m; x++) {
		for (int y = x + 1; y < m; y++) {
			for (int z = y + 1; z < m; z++) {
				q.push(num[x] + num[y] + num[z]);
			}
		}
	}

	int res = n + 1;

	while (res > n) {
		res = q.top();
		q.pop();
	}

	cout << res;

}
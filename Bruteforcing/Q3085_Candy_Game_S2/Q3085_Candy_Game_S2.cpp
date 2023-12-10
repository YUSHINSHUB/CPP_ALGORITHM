#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int chk(vector<vector<char>> bo, int n, int res) {
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		for (int z = 1; z < n; z++) {
			if (bo[i][z] == bo[i][z - 1]) {
				cnt++;
				res = max(cnt, res);
			}
			else {
				cnt = 1;
			}
		}
		cnt = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int z = 1; z < n; z++) {
			if (bo[z][i] == bo[z - 1][i]) {
				cnt++;
				res = max(cnt, res);
			}
			else {
				cnt = 1;
			}
		}
		cnt = 1;
	}
	return res;
}

int main() {

	int n;
	cin >> n;
	int res = 1;
	vector<vector<char>> bo(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int z = 0; z < n; z++) {
			bo[i][z] = temp[z];
		}
	}

	res = chk(bo, n, res);

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n - 1; z++) {
			if (bo[i][z] != bo[i][z + 1]) {
				swap(bo[i][z], bo[i][z + 1]);
				res = chk(bo, n, res);
				swap(bo[i][z], bo[i][z + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n - 1; z++) {
			if (bo[z][i] != bo[z + 1][i]) {
				swap(bo[z][i], bo[z + 1][i]);
				res = chk(bo, n, res);
				swap(bo[z][i], bo[z + 1][i]);
			}
		}
	}

	cout << res;


}
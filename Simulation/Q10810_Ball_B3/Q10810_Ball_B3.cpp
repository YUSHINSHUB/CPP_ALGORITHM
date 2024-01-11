#include <iostream>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	vector<int> bas(n, 0);
	int m;
	cin >> m;
	int i, j, k;

	for (int l = 0; l < m; l++) {
		cin >> i >> j >> k;
		for (int o = i - 1; o < j; o++) {
			bas[o] = k;
		}
	}

	for (int l = 0; l < n; l++) {
		cout << bas[l] << " ";
	}

}

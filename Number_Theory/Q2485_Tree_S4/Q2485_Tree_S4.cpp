#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;


int main() {

	int n;
	cin >> n;
	vector<int> tree(n);
	vector<int> gap(n - 1);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	for (int i = 0; i < n - 1; i++) {
		gap[i] = tree[i + 1] - tree[i];
	}

	int g = gap[0];

	for (int i = 0; i < n - 1; i++) {
		if (gap[i] % g != 0) {
			g--;
			i = -1;
		}
	}

	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		res += (gap[i] / g) - 1;
	}

	cout << res;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> cls(n, vector<int>(5));
	vector<vector<bool>> chk(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		fill(chk[i].begin(), chk[i].end(), false);
		for (int j = 0; j < 5; j++) {
			cin >> cls[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (cls[j][i] == cls[k][i]) {
					chk[j][k] = true;
					chk[k][j] = true;
				}
			}
		}
	}

	int max = 0;
	int res = 1;

	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			if (chk[i][j])
				temp++;
		}
		if (max < temp) {
			max = temp;
			res = i + 1;
		}
	}

	cout << res;

}
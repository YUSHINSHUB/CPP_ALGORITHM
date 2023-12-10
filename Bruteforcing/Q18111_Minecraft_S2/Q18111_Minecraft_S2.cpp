#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> pos(n, vector<int>(m));
	int maxf = 0;

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < m; z++) {
			cin >> pos[i][z];
			if (pos[i][z] > maxf) maxf = pos[i][z];
		}
	}

	vector<int> res(maxf + 1);
	int floor = 0;
	int temp = 0;
	int lotime = 2000000000;
	int pfl = 0;

	while (floor <= maxf) {
		temp = b;
		for (int i = 0; i < n; i++) {
			for (int z = 0; z < m; z++) {
				if (pos[i][z] > floor) {
					res[floor] += (pos[i][z] - floor) * 2;
					temp += pos[i][z] - floor;
				}
				else if (pos[i][z] < floor) {
					res[floor] += floor - pos[i][z];
					temp -= floor - pos[i][z];
				}
			}
		}
		if (temp >= 0 && res[floor] <= lotime) {
			lotime = res[floor];
			pfl = floor;
		}
		floor++;
	}

	cout << lotime << " " << pfl;

}
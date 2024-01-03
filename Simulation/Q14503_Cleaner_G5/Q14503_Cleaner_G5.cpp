#include <iostream>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;
	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int>> pos(x, vector<int>(y));

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> pos[i][j];
		}
	}

	int res = 1;
	pos[r][c] = 2;
	bool out = false;

	while (true) {

		if ((pos[r - 1][c] == 2 || pos[r - 1][c] == 1) && (pos[r + 1][c] == 2 || pos[r + 1][c] == 1)
			&& (pos[r][c - 1] == 2 || pos[r][c - 1] == 1) && (pos[r][c + 1] == 2 || pos[r][c + 1] == 1)) {
			switch (d) {
			case 0:
				if (pos[r + 1][c] == 1) out = true;
				else r++;
				break;
			case 1:
				if (pos[r][c - 1] == 1) out = true;
				else c--;
				break;
			case 2:
				if (pos[r - 1][c] == 1) out = true;
				else r--;
				break;
			case 3:
				if (pos[r][c + 1] == 1) out = true;
				else c++;
				break;
			}
			if (!out) {
				continue;
			}
		}

		if (out) break;

		switch (d) {
		case 0:
			if (pos[r][c - 1] == 0) {
				d = 3;
				c--;
				pos[r][c] = 2;
				res++;
			}
			else {
				d = 3;
			}
			break;
		case 1:
			if (pos[r - 1][c] == 0) {
				r--;
				d = 0;
				pos[r][c] = 2;
				res++;
			}
			else {
				d = 0;
			}
			break;
		case 2:
			if (pos[r][c + 1] == 0) {
				c++;
				d = 1;
				pos[r][c] = 2;
				res++;
			}
			else {
				d = 1;
			}
			break;
		case 3:
			if (pos[r + 1][c] == 0) {
				r++;
				d = 2;
				pos[r][c] = 2;
				res++;
			}
			else {
				d = 2;
			}
			break;
		}
	}

	cout << res;

}

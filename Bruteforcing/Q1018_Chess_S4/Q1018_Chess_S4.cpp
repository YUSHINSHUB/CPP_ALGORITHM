#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {

	int x, y;
	cin >> y >> x;
	int xgap = x - 8;
	int ygap = y - 8;

	vector<vector<string>> board(y, vector<string>(x));
	int ra = 0, rb = 0;
	int res = 64;
	string line = "";

	for (int i = 0; i < y; i++) {
		cin >> line;
		for (int z = 0; z < x; z++) {
			board[i][z] = line[z];
		}
	}
	for (int q = 0; q <= ygap; q++) {
		for (int t = 0; t <= xgap; t++) {
			ra = 0;
			rb = 0;
			for (int i = q; i < 8 + q; i++) {
				if (i % 2 == 0) {
					for (int z = t; z < 8 + t; z += 2) {
						if (board[i][z] != "B")
							ra++;
						else
							rb++;
					}
					for (int z = t + 1; z < 8 + t; z += 2) {
						if (board[i][z] != "W")
							ra++;
						else
							rb++;
					}
				}
				else {
					for (int z = t; z < 8 + t; z += 2) {
						if (board[i][z] != "W")
							ra++;
						else
							rb++;
					}
					for (int z = t + 1; z < 8 + t; z += 2) {
						if (board[i][z] != "B")
							ra++;
						else
							rb++;
					}
				}
			}
			res = min(res, min(ra, rb));
		}
	}

	cout << res;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<vector<int>> mem(n, vector<int>(3));

	for (int i = 0; i < n; i++) {
		cin >> mem[i][0] >> mem[i][1];
		mem[i][2] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++) {
			if (mem[i][0] < mem[z][0] && mem[i][1] < mem[z][1]) {
				mem[i][2]++;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << mem[i][2] << " ";

}
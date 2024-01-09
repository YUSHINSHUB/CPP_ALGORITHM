#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>;

using namespace std;


int main() {

	vector<vector<int>> room(15, vector<int>(15));

	for (int i = 1; i < 15; i++) {
		room[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		room[i][1] = 1;
		for (int z = 2; z < 15; z++) {
			room[i][z] = room[i][z - 1] + room[i - 1][z];
		}
	}

	int n;

	cin >> n;

	vector<int> f(n);
	vector<int> r(n);

	for (int i = 0; i < n; i++) {
		cin >> f[i];
		cin >> r[i];
	}

	for (int i = 0; i < n; i++) {
		cout << room[f[i]][r[i]] << endl;
	}

}
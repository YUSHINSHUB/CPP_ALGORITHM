#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> team(n, vector<int>(2));

		for (int j = 0; j < m; j++) {

			int a, b, c, d;
			cin >> a >> b >> c >> d;

			team[a - 1][0] += c;
			team[a - 1][1] += d;
			team[b - 1][0] += d;
			team[b - 1][1] += c;
		}

		vector<double> pe(n);

		for (int j = 0; j < n; j++) {
			if (team[j][0] == 0 && team[j][1] == 0) pe[j] = 0;
			else pe[j] = (pow(team[j][0], 2)) / (pow(team[j][0], 2) + pow(team[j][1], 2));
		}
		sort(pe.begin(), pe.end());

		cout << (int)(pe[n - 1] * 1000) << "\n" << (int)(pe[0] * 1000) << "\n";
	}

}
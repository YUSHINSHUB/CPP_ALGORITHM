#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, m, r;
	cin >> n >> m >> r;
	int cnt = 0;

	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < m; z++) {
			cin >> arr[i][z];
		}
	}

	for (int i = 0; i < r; i++) {
		cnt = 0;
		while (cnt < n / 2 && cnt < m / 2) {
			int temp = arr[cnt][cnt];
			for (int z = cnt + 1; z < m - cnt; z++) {
				arr[cnt][z - 1] = arr[cnt][z];
			} // 力老 困 啊肺临

			for (int z = cnt + 1; z < n - cnt; z++) {
				arr[z - 1][m - 1 - cnt] = arr[z][m - 1 - cnt];
			} // 力老 坷弗率 技肺临

			for (int z = m - 1 - cnt; z > cnt; z--) {
				arr[n - 1 - cnt][z] = arr[n - 1 - cnt][z - 1];
			} // 力老 关 啊肺临

			for (int z = n - 1 - cnt; z > cnt; z--) {
				arr[z][cnt] = arr[z - 1][cnt];
			}
			// 力老 哭率 技肺临

			arr[cnt + 1][cnt] = temp;

			cnt++;

		}
	}

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < m; z++) {
			cout << arr[i][z] << " ";
		}
		cout << "\n";
	}

}

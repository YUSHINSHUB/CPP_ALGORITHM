#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> bas(n);

	for (int i = 0; i < n; i++) {
		bas[i] = i + 1;
	}

	int beg, end, dis;

	for (int i = 0; i < m; i++) {
		cin >> beg >> end;
		dis = end - beg + 1;

		vector<int> temp(dis);

		for (int j = 0; j < dis; j++) {
			temp[j] = bas[beg + j - 1];
		}

		for (int j = dis - 1; j >= 0; j--) {
			bas[end - j - 1] = temp[j];
		}

	}

	for (int i = 0; i < n; i++) {
		cout << bas[i] << " ";
	}
}
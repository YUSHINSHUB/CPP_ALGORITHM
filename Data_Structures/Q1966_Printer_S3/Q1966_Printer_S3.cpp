#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int main() {

	int n, m;
	int max = 0;
	int res = 0;

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		res = 0;
		max = 0;
		queue<int> q;
		cin >> n >> m;
		m++;
		int maxcnt = 0;

		int qo = 0;

		for (int z = 0; z < n; z++) {
			cin >> qo;
			q.push(qo);
			if (max < qo) {
				max = qo;
				maxcnt = 1;
			}
			else if (max == qo) {
				maxcnt++;
			}
		}

		while (true) {
			int temp = q.front();
			q.pop();
			if (temp != max) {
				q.push(temp);
				m--;
				if (m == 0) {
					m = q.size();
				}
			}
			else {
				maxcnt--;
				m--;
				res++;
				if (m == 0) break;
				if (maxcnt == 0) {
					max = 0;
					for (int z = 0; z < q.size(); z++) {
						int y = q.front();
						q.pop();
						q.push(y);
						if (max < y) {
							max = y;
							maxcnt = 1;
						}
						else if (max == y) maxcnt++;
					}
				}
			}
		}
		cout << res << "\n";
	}
}
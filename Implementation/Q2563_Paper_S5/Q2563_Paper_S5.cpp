#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, v, h;
	cin >> n;
	int pap[100][100];
	int res = 0;

	for (int i = 0; i < 100; i++) {
		fill_n(pap[i], 100, 0);
	}

	for (int i = 0; i < n; i++) {
		cin >> v >> h;
		for (int j = v; j < v + 10; j++) {
			for (int k = h; k < h + 10; k++) {
				if (pap[j][k] == 1)
					continue;
				else {
					pap[j][k] = 1;
					res++;
				}
			}
		}
	}

	cout << res;
}
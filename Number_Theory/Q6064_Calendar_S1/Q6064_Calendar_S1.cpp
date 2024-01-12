#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int t;
	cin >> t;
	int m, n, x, y;

	for (int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;
		int hi = max(m, n);
		int end = hi;
		while (end % m != 0 || end % n != 0) {
			end += hi;
		}


		int res = min(x, y);
		int up = 0;

		if (res == x) up = m;
		else up = n;

		if (m == x) x = 0;
		if (n == y) y = 0;

		while (res <= end) {
			if (res % m == x && res % n == y) break;
			else {
				res += up;
				if (res == end) {
					if (x == 0) x += m;
					if (y == 0) y += n;
					if (res % x == 0 && res % y == 0) break;
				}
			}
		}

		if (res > end) res = -1;

		cout << res << "\n";
	}
}
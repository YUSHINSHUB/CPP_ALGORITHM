#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int n;
	int m;

	cin >> n >> m;

	int res1 = 0;
	int res2 = 0;

	for (int i = n; i <= m; i++) {
		if (sqrt(i) == (int)sqrt(i)) {
			if (res2 == 0) {
				res2 = i;
			}
			res1 += i;
		}
	}

	if (res1 == 0) {
		cout << "-1";
	}
	else {
		cout << res1 << "\n" << res2;
	}

}
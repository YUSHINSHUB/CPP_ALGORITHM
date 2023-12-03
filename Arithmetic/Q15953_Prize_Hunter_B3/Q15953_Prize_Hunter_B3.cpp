#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	int res = 0;
	int a, b;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		res = 0;

		if (a != 0) {
			if (a - 1 <= 0)
				res += 5000000;
			else if (a - 3 <= 0)
				res += 3000000;
			else if (a - 6 <= 0)
				res += 2000000;
			else if (a - 10 <= 0)
				res += 500000;
			else if (a - 15 <= 0)
				res += 300000;
			else if (a - 21 <= 0)
				res += 100000;
		}

		if (b != 0) {
			if (b - 1 <= 0)
				res += 5120000;
			else if (b - 3 <= 0)
				res += 2560000;
			else if (b - 7 <= 0)
				res += 1280000;
			else if (b - 15 <= 0)
				res += 640000;
			else if (b - 31 <= 0)
				res += 320000;
		}

		cout << res << "\n";
	}
}
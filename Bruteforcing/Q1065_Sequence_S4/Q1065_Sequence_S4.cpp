#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int res = 0;
	int q[3];
	if (a > 0 && a < 100) {
		res = a;
	}
	else {
		res = 99;
		for (int x = 100; x <= a; x++) {
			if (x == 1000) {
				break;
			}
			int y = x;
			int z = 0;
			while (y != 0) {
				q[z] = y % 10;
				y /= 10;
				z++;
			}
			if (q[0] - q[1] == q[1] - q[2]) {
				res++;
			}
		}
	}
	cout << res;
}
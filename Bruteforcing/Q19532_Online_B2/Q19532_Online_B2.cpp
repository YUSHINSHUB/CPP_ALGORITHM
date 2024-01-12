#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int x = 1000, y = 1000;

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if ((a * i) + (b * j) == c && (d * i) + (e * j) == f) {
				x = i;
				y = j;
				break;
			}
		}
		if (x != 1000 && y != 1000)
			break;
	}

	cout << x << " " << y;

}
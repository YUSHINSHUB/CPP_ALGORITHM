#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int lx = INT_MAX;
	int ly = INT_MAX;
	int hx = INT_MIN;
	int hy = INT_MIN;

	int y, x;

	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		if (y < ly)
			ly = y;
		if (y > hy)
			hy = y;
		if (x < lx)
			lx = x;
		if (x > hx)
			hx = x;
	}

	hy -= ly;
	hx -= lx;

	cout << hy * hx;
}
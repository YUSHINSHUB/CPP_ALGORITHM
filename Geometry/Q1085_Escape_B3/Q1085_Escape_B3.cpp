#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int xr;
	int yr;
	int res;

	if (x >= w && y >= h) {
		xr = x - w;
		yr = y - h;
		res = xr + yr;
	}
	else if (x >= w && y < h) {
		res = x - w;
	}
	else if (x < w && y >= h) {
		res = y - h;
	}
	else {
		xr = min(x, w - x);
		yr = min(y, h - y);
		res = min(xr, yr);
	}

	cout << res;

}
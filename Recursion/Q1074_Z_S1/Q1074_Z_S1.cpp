#include <iostream>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int calc(int n, int r, int c, int low, int hig) {

	n--;
	int res = 0;

	int line = (int)pow(2, n - 1);
	int temp = (hig - low) / 4;

	if (r > line && c > line) {
		low += temp * 3;
		r -= line;
		c -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (r <= line && c <= line) {
		hig = low + temp;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (r > line) {
		low += temp * 2;
		hig = low + temp;
		r -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (c > line) {
		low += temp;
		hig = low + temp;
		c -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	r++;
	c++;

	int hig = (int)pow(4, n);
	int line = (int)pow(2, n - 1);

	n++;
	int res = calc(n, r, c, 0, hig);


	cout << res;
}
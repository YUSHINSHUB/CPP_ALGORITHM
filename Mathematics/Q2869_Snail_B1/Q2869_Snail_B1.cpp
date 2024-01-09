#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int a, b, v, c;
	cin >> a >> b >> v;

	c = a - b;

	int res = ((v - a) / c) + 1;
	if ((v - a) % c != 0) {
		res++;
	}

	cout << res;

}
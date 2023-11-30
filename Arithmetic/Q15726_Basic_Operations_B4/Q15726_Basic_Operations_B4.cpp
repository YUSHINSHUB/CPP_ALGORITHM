#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	double a, b, c;
	cin >> a >> b >> c;

	int res1 = (int)(a * b / c);
	int res2 = (int)(a / b * c);

	cout << max(res1, res2);

}
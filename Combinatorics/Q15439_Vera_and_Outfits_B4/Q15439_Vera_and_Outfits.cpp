#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{

	int n;
	cin >> n;

	int t = n - 1;
	long long res = 1;

	for (int i = t; i <= n; i++) {
		res *= i;
	}

	cout << res;

}

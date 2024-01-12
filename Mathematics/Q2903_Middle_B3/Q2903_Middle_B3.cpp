#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int res = 2;
	int add = 1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		res += add;
		add *= 2;
	}

	res = (int)pow(res, 2);

	cout << res;
}
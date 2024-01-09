#include <iostream>

using namespace std;

int main()
{
	int num[5] = {};
	int res = 0;

	cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];

	for (int i = 0; i < 5; i++) {
		res = res + (num[i] * num[i]);
	}

	res = res % 10;

	cout << res;

}
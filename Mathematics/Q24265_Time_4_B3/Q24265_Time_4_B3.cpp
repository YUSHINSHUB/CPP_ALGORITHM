#include <iostream>
using namespace std;

int main()
{
	long long n;
	long long res = 0;
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		res += i;
	}

	cout << res << "\n2";
}
#include <iostream>
using namespace std;

int main()
{
	long long n;
	long long res = 0;
	long long cur = 0;

	cin >> n;

	for (long i = 1; i <= n - 2; i++) {
		cur += i;
		res += cur;
	}

	cout << res << "\n3";
}
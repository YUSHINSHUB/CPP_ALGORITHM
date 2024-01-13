#include <iostream>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;

	if (a < b) {
		long temp = a;
		a = b;
		b = temp;
	}

	long res = a;

	while (res % b != 0) {
		res += a;
	}

	cout << res;
}

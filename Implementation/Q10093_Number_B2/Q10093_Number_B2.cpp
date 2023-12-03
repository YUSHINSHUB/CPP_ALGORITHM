#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;

	if (a > b) {
		long temp = a;
		a = b;
		b = temp;
	}

	if (b - a < 2)
		cout << "0";
	else {
		cout << (b - a - 1) << "\n";

		for (long i = a + 1; i <= b - 1; i++) {
			cout << i << " ";
		}
	}
}
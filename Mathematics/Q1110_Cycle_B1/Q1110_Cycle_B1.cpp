#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int a = n;
	int b = 0;

	do {
		a = (((a % 10) + (a / 10)) % 10) + ((a % 10) * 10);
		b++;
	} while (a != n);

	cout << b;
}
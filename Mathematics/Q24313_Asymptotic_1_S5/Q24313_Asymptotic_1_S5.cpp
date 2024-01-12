#include <iostream>
using namespace std;

int main()
{
	int a1, a0, c, n;
	cin >> a1 >> a0 >> c >> n;
	if (a1 > c)
		cout << "0";
	else {
		if (((a1 * n) + a0) > (c * n))
			cout << "0";
		else
			cout << "1";
	}
}
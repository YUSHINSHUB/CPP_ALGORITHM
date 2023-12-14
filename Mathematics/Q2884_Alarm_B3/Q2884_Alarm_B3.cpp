#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < 45; i++) {
		b--;
		if (b == -1) {
			b = 59;
			a--;
			if (a == -1) {
				a = 23;
			}
		}
	}
	cout << a << " " << b;
}
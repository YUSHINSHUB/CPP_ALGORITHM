#include <iostream>
using namespace std;

int main()
{
	int i;
	cin >> i;

	for (int a = 0; a < i; a++) {
		int x, y;
		cin >> x >> y;
		cout << "Case #" << (a + 1) << ": " << x << " + " << y << " = " << (x + y) << "\n";
	}
}
#include <iostream>

using namespace std;


int main() {
	int f, n;
	int temp = 0;
	cin >> n;

	int res = 0;
	f = n / 5;
	n %= 5;

	while (n % 3 != 0) {
		n += 5;
		f--;
		if (f == -1) break;
	}

	if (f == -1) cout << "-1";
	else cout << f + (n / 3);

}
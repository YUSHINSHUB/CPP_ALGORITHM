#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;

	cin >> a;
	cin >> b;

	int out[4];

	out[0] = a * (b % 10);
	out[1] = a * (b % 100 / 10);
	out[2] = a * (b / 100);
	out[3] = a * b;

	for (int i = 0; i < 4; i++) {
		cout << out[i] << endl;
	}
}

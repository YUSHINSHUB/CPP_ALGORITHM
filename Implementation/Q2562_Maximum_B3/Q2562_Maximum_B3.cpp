#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int hi = INT_MIN;
	int in, idx;

	for (int i = 1; i <= 9; i++) {
		cin >> in;
		if (in > hi) {
			hi = in;
			idx = i;
		}
	}

	cout << hi << " " << idx;
}
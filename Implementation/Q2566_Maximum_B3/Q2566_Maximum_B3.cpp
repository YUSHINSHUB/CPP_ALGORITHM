#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>

using namespace std;
int main()
{
	int y = 0;
	int x = 0;
	int max = INT_MIN;
	int temp;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> temp;
			if (temp > max) {
				max = temp;
				x = j + 1;
				y = i + 1;
			}
		}
	}

	cout << max << "\n" << y << " " << x;
}
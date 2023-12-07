#include <iostream>

using namespace std;

int main() {

	int burger[3];
	int drink[2];

	int bmin = 2001;
	int dmin = 2001;

	int smin;

	for (int i = 0; i < 3; i++) {
		cin >> burger[i];
		bmin = min(bmin, burger[i]);
	}

	for (int i = 0; i < 2; i++) {
		cin >> drink[i];
		dmin = min(dmin, drink[i]);
	}

	smin = bmin + dmin - 50;

	cout << smin;

}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int z = i; z < n; z++) {
			cout << " ";
		}
		for (int z = 0; z < 1 + 2 * (i - 1); z++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = n - 1; i > 0; i--) {

		for (int z = n; z > i; z--) {
			cout << " ";
		}

		for (int z = 1 + (2 * (i - 1)); z > 0; z--) {
			cout << "*";
		}

		cout << endl;
	}

}
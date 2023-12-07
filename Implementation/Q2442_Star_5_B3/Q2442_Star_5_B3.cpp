#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int z = 0; z < (n - i); z++) {
			cout << " ";
		}
		for (int x = 0; x < (2 * i - 1); x++) {
			cout << "*";
		}
		cout << endl;
	}
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n;

	cin >> n;

	for (int i = n; i > 0; i--) {
		for (int z = n - i; z > 0; z--) {
			cout << " ";
		}
		for (int x = 0; x < i; x++) {
			cout << "*";
		}
		cout << endl;
	}

}
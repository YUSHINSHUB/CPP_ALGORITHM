#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	int inp[9];
	int sum = 0;
	char b[9];

	for (int i = 0; i < 9; i++) {
		cin >> inp[i];
		sum += inp[i];
	}

	sum -= 100;

	for (int i = 0; i < 9; i++) {
		if (inp[i] < sum) {
			for (int z = i + 1; z < 9; z++) {
				if (inp[i] + inp[z] == sum) {
					b[i] = '1';
					b[z] = '1';
					break;
				}
			}
			if (b[i] == '1') {
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (b[i] != '1') {
			cout << inp[i] << "\n";
		}
	}

}
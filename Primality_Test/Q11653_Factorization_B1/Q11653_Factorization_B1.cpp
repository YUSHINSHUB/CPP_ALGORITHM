#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n[10000001];
	n[1] = 1;
	for (int i = 2; i <= 10000000; i++) {
		if (n[i] != 1) {
			n[i] = 0;
			for (int z = i * 2; z <= 10000000; z += i) {
				n[z] = 1;
			}
		}
	}


	int in;
	cin >> in;
	int m = 2;

	while (in != 1) {
		if (in % m == 0) {
			in /= m;
			cout << m << "\n";
		}
		else {
			m++;
			while (n[m] == 1) {
				m++;
			}
		}
	}
}
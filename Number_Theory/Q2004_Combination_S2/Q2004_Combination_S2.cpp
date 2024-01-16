#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n;
	int m;

	cin >> n >> m;

	int nmm = n - m;

	int n2 = n;
	int m2 = m;
	int nmm2 = nmm;

	int fcnt = 0;
	int tcnt = 0;

	while (n >= 5) {
		fcnt += n / 5;
		n /= 5;
	}

	while (m >= 5) {
		fcnt -= m / 5;
		m /= 5;
	}

	while (nmm >= 5) {
		fcnt -= nmm / 5;
		nmm /= 5;
	}

	while (n2 >= 2) {
		tcnt += n2 / 2;
		n2 /= 2;
	}

	while (m2 >= 2) {
		tcnt -= m2 / 2;
		m2 /= 2;
	}

	while (nmm2 >= 2) {
		tcnt -= nmm2 / 2;
		nmm2 /= 2;
	}

	cout << min(fcnt, tcnt);

}

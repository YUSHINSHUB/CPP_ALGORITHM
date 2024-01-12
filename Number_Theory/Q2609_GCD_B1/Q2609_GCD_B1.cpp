#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b;
	int temp = 0;
	int ma, mi;

	cin >> a >> b;

	temp = min(a, b);
	while (true) {
		if (a % temp == 0 && b % temp == 0) {
			ma = temp;
			break;
		}
		temp--;
	}


	temp = max(a, b);
	while (true) {
		if (temp % a == 0 && temp % b == 0) {
			mi = temp;
			break;
		}
		temp += max(a, b);
	}

	cout << ma << " " << mi;
}

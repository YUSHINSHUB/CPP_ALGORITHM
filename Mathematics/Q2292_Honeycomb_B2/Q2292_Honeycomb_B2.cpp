#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int cnt = 1;
	int max = 1;
	int up = 6;

	while (n > max) {
		max += up;
		up += 6;
		cnt++;
	}

	cout << cnt;

}
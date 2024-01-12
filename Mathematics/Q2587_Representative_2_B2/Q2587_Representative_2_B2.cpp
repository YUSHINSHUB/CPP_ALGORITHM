#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

	int p[5];
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		cin >> p[i];
		sum += p[i];
	}
	sum /= 5;
	sort(p, p + 5);
	cout << sum << "\n" << p[2];

}

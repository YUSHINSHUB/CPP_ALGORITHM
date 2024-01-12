#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;


int main() {

	string out;
	int cnt = 0;

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		int maxn = max(c, max(a, b));

		if (maxn == a) {
			if (pow(a, 2) == pow(b, 2) + pow(c, 2)) {
				out = "right";
			}
			else {
				out = "wrong";
			}
		}
		else if (maxn == b) {
			if (pow(b, 2) == pow(a, 2) + pow(c, 2)) {
				out = "right";
			}
			else {
				out = "wrong";
			}
		}
		else {
			if (pow(c, 2) == pow(b, 2) + pow(a, 2)) {
				out = "right";
			}
			else {
				out = "wrong";
			}
		}
		cout << out << endl;
	}

}
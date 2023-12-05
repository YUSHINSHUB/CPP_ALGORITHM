#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	int ca = 0;

	while (true) {

		ca++;
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;

		int out = ((v / p) * l);
		if (v % p > l) {
			out += l;
		}
		else {
			out += v % p;
		}

		cout << "Case " << ca << ": " << out << "\n";
	}
}
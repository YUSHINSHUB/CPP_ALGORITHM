#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

static long recur(long a, long b, long c) {
	if (b == 0) {
		return 1;
	}
	else if (b % 2 == 0) {
		long re = recur(a, b / 2, c) % c;
		return (re * re) % c;
	}
	else {
		long re = recur(a, b / 2, c) % c;
		return (re * (((re) * (a % c)) % c)) % c;
	}
}


int main() {

	long a, b, c;
	cin >> a >> b >> c;

	cout << recur(a, b, c);

}
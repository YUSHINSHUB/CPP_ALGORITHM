#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	int n;
	string in;
	cin >> n >> in;
	long res = 0;
	long temp = 1;

	for (int i = 0; i < n; i++) {
		res += ((int)(in[i] - 96) * temp) % 1234567891;
		temp = temp * 31 % 1234567891;
	}

	cout << res % 1234567891;


}

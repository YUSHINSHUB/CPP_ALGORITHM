#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int a;
	int b;

	cin >> a >> b;

	string res = "";

	while (a != 0) {
		int temp = a % b;
		if (temp >= 10) {
			res += (char)(temp + 55);
		}
		else {
			res += (char)(temp + 48);
		}
		a /= b;
	}

	for (int i = res.length() - 1; i >= 0; i--) {
		cout << res[i];
	}

}
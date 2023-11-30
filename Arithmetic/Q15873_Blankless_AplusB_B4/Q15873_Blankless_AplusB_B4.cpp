#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string ab;
	cin >> ab;

	int res = 0;

	switch (ab.length()) {
	case 4:
		res = 20;
		break;
	case 3:
		if (ab[1] == '0') {
			res = 10 + (ab[2] - 48);
		}
		else {
			res = 10 + (ab[0] - 48);
		}
		break;
	case 2:
		res = (ab[0] - 48) + (ab[1] - 48);

	}

	cout << res;


}
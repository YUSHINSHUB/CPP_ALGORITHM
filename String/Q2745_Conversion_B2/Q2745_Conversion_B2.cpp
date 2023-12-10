#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	string inp;
	int num;
	cin >> inp >> num;

	int temp = 0;
	int res = 0;

	for (int i = inp.length() - 1; i >= 0; i--) {
		if (inp[i] >= 'A') {
			res += (inp[i] - 55) * pow(num, temp);
			temp++;
		}
		else {
			res += (inp[i] - 48) * pow(num, temp);
			temp++;
		}
	}

	cout << res;
}


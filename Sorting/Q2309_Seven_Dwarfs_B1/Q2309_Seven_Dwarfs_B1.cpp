#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int in[9];
	int sum = 0;
	bool chk = false;

	for (int i = 0; i < 9; i++) {
		cin >> in[i];
		sum += in[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int z = i + 1; z < 9; z++) {
			if (in[i] + in[z] == sum - 100) {
				in[i] = 0;
				in[z] = 0;
				chk = true;
				break;
			}
		}
		if (chk == true) {
			break;
		}
	}

	sort(in, in + 9);

	for (int i = 2; i < 9; i++) {
		cout << in[i] << "\n";
	}

}
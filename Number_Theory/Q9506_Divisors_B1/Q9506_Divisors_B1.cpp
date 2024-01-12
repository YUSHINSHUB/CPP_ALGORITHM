#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int in;
	int sum;

	while (true) {
		cin >> in;
		if (in == -1) {
			break;
		}
		sum = 0;
		vector<bool> chk(in / 2 + 1);

		for (int i = 1; i <= in / 2; i++) {
			if (in % i == 0) {
				chk[i] = true;
				sum += i;
			}
		}

		if (sum == in) {
			cout << in << " = 1";
			for (int i = 2; i <= in / 2; i++) {
				if (chk[i] == true) {
					cout << " + " << i;
				}
			}
			cout << "\n";
		}
		else {
			cout << in << " is NOT perfect.\n";
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string in;
	bool chk = true;

	while (true) {
		cin >> in;
		chk = true;
		if (in == "0") {
			break;
		}

		for (int i = 0; i < in.length(); i++) {
			if (in[i] != in[in.length() - 1 - i]) {
				chk = false;
				break;
			}
		}

		if (chk == true) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}

	}

}
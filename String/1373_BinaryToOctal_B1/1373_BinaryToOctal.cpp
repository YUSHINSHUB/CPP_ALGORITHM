
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string bin;
	cin >> bin;
	int toth = 0;
	string temp = "";
	string oct = "";

	switch (bin.length() % 3) {
	case (1):
		temp = (bin[0] - '0') + '0';
		oct.append(temp);
		break;
	case (2):
		temp = ((bin[0] - '0') * 2 + (bin[1] - '0')) + '0';
		oct.append(temp);
		break;
	default:
		break;
	}

	temp = "";

	for (int i = bin.length() % 3; i < bin.length(); i++) {
		temp += bin[i];
		toth++;
		if (toth == 3) {
			toth = 0;
			temp = ((temp[0] - '0') * 4 + (temp[1] - '0') * 2 + (temp[2] - '0')) + '0';
			oct.append(temp);
			temp = "";
		}
	}

	cout << oct;

}
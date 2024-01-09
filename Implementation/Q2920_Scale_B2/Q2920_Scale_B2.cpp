#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	int nums[8];

	string out = "mixed";

	for (int i = 0; i < 8; i++) {
		cin >> nums[i];
	}

	if (nums[0] == 1) {
		out = "ascending";
		for (int i = 1; i < 8; i++) {
			if (nums[i] != i + 1) {
				out = "mixed";
				break;
			}
		}
	}
	else if (nums[0] == 8) {
		out = "descending";
		for (int i = 1; i < 8; i++) {
			if (nums[i] != 8 - i) {
				out = "mixed";
				break;
			}
		}
	}
	cout << out;

}
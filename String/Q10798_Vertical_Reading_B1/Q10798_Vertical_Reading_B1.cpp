#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {

	string in[5];
	int max = 0;

	for (int i = 0; i < 5; i++) {
		cin >> in[i];
		if (max < in[i].length()) {
			max = in[i].length();
		}
	}

	for (int i = 0; i < max; i++) {
		if (in[0].length() > i) {
			cout << in[0][i];
		}
		if (in[1].length() > i) {
			cout << in[1][i];
		}
		if (in[2].length() > i) {
			cout << in[2][i];
		}
		if (in[3].length() > i) {
			cout << in[3][i];
		}
		if (in[4].length() > i) {
			cout << in[4][i];
		}
	}
}
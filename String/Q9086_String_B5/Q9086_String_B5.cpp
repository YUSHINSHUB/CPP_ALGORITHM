#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	string in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		cout << in[0] << in[in.length() - 1] << "\n";
	}

}
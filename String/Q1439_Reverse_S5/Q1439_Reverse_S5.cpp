#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;


int main() {

	string in;
	cin >> in;
	int zc = 0;
	int oc = 0;

	for (int i = 1; i < in.length(); i++) {
		if (in[i] != in[i - 1]) {
			if (in[i] == '1')
				zc++;
			else
				oc++;
		}
		if (i == in.length() - 1) {
			if (in[i] == '1')
				oc++;
			else
				zc++;
		}
	}

	cout << min(zc, oc);
}

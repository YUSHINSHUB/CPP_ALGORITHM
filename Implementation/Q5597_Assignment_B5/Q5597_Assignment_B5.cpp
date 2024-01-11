#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
using namespace std;


int main() {

	int t = 0;
	map<int, int> hm;

	for (int i = 0; i < 28; i++) {
		cin >> t;
		hm[t] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (hm[i] != 1)
			cout << i << "\n";
	}


}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>

using namespace std;

int main() {

	int n;
	cin >> n;
	int ball = 1;
	int a, b, ak, bk;
	map<int, int> hm;

	hm[1] = 1;
	hm[2] = 2;
	hm[3] = 3;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ak = hm[a];
		bk = hm[b];
		hm[a] = bk;
		hm[b] = ak;

	}

	for (int i = 1; i <= 3; i++) {
		if (hm[i] == 1) cout << i;
	}

}
#include <iostream>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	int cnt[246914];
	int chk[246914];
	int idx = 1;
	cnt[1] = 0;
	cnt[2] = 1;

	chk[1] = 1;
	chk[2] = 2;

	for (int i = 4; i <= 246913; i += 2) {
		chk[i] = 1;
	}

	for (int i = 3; i <= 246913; i++) {
		if (chk[i] != 1) {
			idx++;
			chk[i] = 2;
			for (int z = i * 2; z <= 246913; z += i) {
				chk[z] = 1;
			}
		}
		cnt[i] = idx;
	}

	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		cout << cnt[n * 2] - cnt[n] << "\n";
	}
}
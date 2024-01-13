#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n[1000001];

	n[0] = 1;
	n[1] = 1;

	for (int i = 2; i < 1000001; i++) {
		if (n[i] != 1) {
			n[i] = 0;
			for (int z = i * 2; z < 1000001; z += i) {
				n[z] = 1;
			}
		}
	}

	int t;
	cin >> t;

	vector<int>num(t);
	vector<int>gold(t);

	for (int i = 0; i < t; i++) {
		cin >> num[i];
		gold[i] = 0;
		for (int z = 2; z <= num[i] / 2; z++) {
			if (n[z] == 0 && n[num[i] - z] == 0) {
				gold[i]++;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << gold[i] << "\n";
	}



}

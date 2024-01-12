#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int s, e;
	cin >> s >> e;

	vector<bool> res(e + 1);

	for (int i = 2; i <= e; i += 2) {
		res[i] = true;
	}

	for (int i = 3; i <= e; i += 2) {
		if (!res[i]) {
			for (int z = i * 2; z <= e; z += i) {
				res[z] = true;
			}
		}
	}

	res[1] = true;
	res[2] = false;

	for (int i = s; i <= e; i++) {
		if (!res[i]) cout << i << "\n";
	}


}
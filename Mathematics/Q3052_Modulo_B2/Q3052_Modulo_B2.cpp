#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

	bool rem = true;
	int temp = 0;
	int nums[10];
	int numcnt = 0;

	for (int i = 0; i < 10; i++) {
		rem = true;
		cin >> temp;
		temp %= 42;

		for (int z = 0; z < numcnt; z++) {
			if (nums[z] == temp) {
				rem = false;
				break;
			}
		}
		if (rem == true) {
			nums[numcnt] = temp;
			numcnt++;
		}
	}

	cout << numcnt;

}
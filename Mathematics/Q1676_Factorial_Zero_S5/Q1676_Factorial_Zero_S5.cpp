#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	bool bp = true;

	char fac[3001];
	char ft[3001];

	int cnt = 0;

	int index = 0;
	int index2;

	int temp = 0;
	int tindex = 1;
	int tcount = 0;

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			fac[0] = '1';
		}
		else {

			index2 = index;

			for (int z = 0; z <= index; z++) {
				ft[z] = '0';
			}
			for (int z = 0; z <= index2; z++) {

				temp = ((fac[z] - '0') * i);
				while (temp / tindex != 0) {
					tindex *= 10;
					if (z + tcount > index) {
						index++;
						fac[index] = '0';
						ft[index] = '0';
					}
					ft[z + tcount] += temp % tindex / (tindex / 10);
					tcount++;
				}
				tindex = 1;
				tcount = 0;

			}

			for (int z = 0; z <= index; z++) {
				fac[z] = ft[z];
				ft[z] = '0';
			}

			bp = true;
			while (bp == true) {
				bp = false;
				for (int x = 0; x <= index; x++) {
					if (fac[x] > '9') {
						bp = true;
						if (x == index) {
							index++;
							fac[x + 1] = '0';
							while (fac[x] > '9') {
								fac[x + 1] += 1;
								fac[x] -= 10;
							}
							break;
						}
						else {
							fac[x + 1] += 1;
							fac[x] -= 10;
							break;
						}
					}
				}
			}

		}
	}

	if (n != 0) {
		for (int i = 0; i <= index; i++) {
			if (fac[i] != '0') {
				break;
			}
			cnt++;
		}
	}

	cout << cnt;


}
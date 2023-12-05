#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string in;
	cin >> in;
	int res[27];
	fill_n(res, 27, -1);

	for (int i = 0; i < 26; i++) {
		if (in.find('a' + i) >= 0) {
			for (int z = 0; z < in.length(); z++) {
				if (in[z] == 'a' + i) {
					res[i + 1] = z;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= 26; i++) {
		cout << res[i] << " ";
	}
}
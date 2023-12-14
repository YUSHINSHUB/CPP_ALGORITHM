#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int res = 665;
	int cnt = 0;

	while (true) {
		res++;
		string temp = to_string(res);
		for (int i = 2; i < temp.length(); i++) {
			if (temp[i] == '6' && temp[i - 1] == '6' && temp[i - 2] == '6') {
				cnt++;
				break;
			}
		}
		if (cnt == n) break;
	}

	cout << res;


}
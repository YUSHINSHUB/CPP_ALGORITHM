#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> res(n);

	int tempa;
	int tempb;

	int temp;



	for (int i = 0; i < n; i++) {
		cin >> tempa >> tempb;

		temp = max(tempa, tempb);
		res[i] = temp;

		while (res[i] % tempa != 0 || res[i] % tempb != 0) {
			res[i] += max(tempa, tempb);
		}

	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << "\n";
	}

}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> appli(n);

	for (int i = 0; i < n; i++) {
		cin >> appli[i];
	}

	int sup1, sup2;
	cin >> sup1 >> sup2;

	long int res = 0;

	for (int i = 0; i < n; i++) {
		appli[i] -= sup1;
		res++;
		if (appli[i] > 0) {
			res += appli[i] / sup2;
			appli[i] %= sup2;
			if (appli[i] > 0) {
				res++;
			}
		}
	}

	cout << res;

}
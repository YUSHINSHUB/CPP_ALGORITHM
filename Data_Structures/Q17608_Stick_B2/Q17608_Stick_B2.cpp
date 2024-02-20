#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> stick(n);
	int hig = 0;
	int res = 0;

	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (stick[i] > hig) {
			hig = stick[i];
			res++;
		}
	}

	cout << res;
}
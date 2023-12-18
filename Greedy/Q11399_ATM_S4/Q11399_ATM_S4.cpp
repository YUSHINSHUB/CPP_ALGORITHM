#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> times(n);
	int sum = 0;
	int res = 0;

	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}

	sort(begin(times), end(times));

	for (int i = 0; i < n; i++) {
		sum += times[i];
		res += sum;
	}

	cout << res;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<double> nums(n);
	double m = 0;
	double res = 0;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		m = max(m, nums[i]);
	}

	for (int i = 0; i < n; i++) {
		nums[i] = nums[i] / m * 100;
		res += nums[i];
	}

	cout << res / n;



}
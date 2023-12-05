#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int max = nums[0];
	int min = nums[0];

	for (int i = 0; i < n; i++) {
		if (max < nums[i]) {
			max = nums[i];
		}
		if (min > nums[i]) {
			min = nums[i];
		}
	}

	cout << max * min;
}

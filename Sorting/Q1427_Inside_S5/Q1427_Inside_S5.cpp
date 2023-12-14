#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	string nums;
	cin >> nums;

	vector<int> num(nums.length());

	for (int i = 0; i < nums.length(); i++) {
		num[i] = nums[i] - 48;
	}

	sort(num.begin(), num.end(), [](int o1, int o2) -> int {
		return o1 > o2;
		});

	for (int i = 0; i < num.size(); i++) {
		cout << num[i];
	}

}
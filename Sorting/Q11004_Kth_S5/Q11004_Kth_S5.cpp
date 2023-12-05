#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int nums[5000001];

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + n);
	cout << nums[k - 1];

}

#include <iostream>
#include <math.h>
#include <vector>
#include <climits>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	int low = INT_MAX;
	int hig = INT_MIN;

	vector<int> cur(n);
	int sum = 0;
	int mid = 0;

	for (int i = 0; i < n; i++) {
		cin >> cur[i];
		sum += cur[i];
		low = min(low, cur[i]);
		hig = max(hig, cur[i]);
	}

	int dep;
	cin >> dep;

	if (sum > dep) {
		while (mid != low) {
			mid = (low + hig) / 2;
			sum = 0;
			for (int i = 0; i < n; i++) {
				if (cur[i] > mid) sum += mid;
				else sum += cur[i];
			}

			if (sum > dep) {
				hig = mid;
			}
			else if (sum < dep) {
				low = mid + 1;
			}

		}
		while (true) {
			sum = 0;
			for (int i = 0; i < n; i++) {
				if (cur[i] > mid) sum += mid;
				else sum += cur[i];
			}
			if (sum > dep) mid--;
			else break;
		}

	}
	else {
		mid = hig;
	}

	cout << mid;

}
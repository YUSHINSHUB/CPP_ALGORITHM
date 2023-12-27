#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
int main() {

	int k, n;
	long long cnt, mid;
	long long low = 0, hig = 0;
	cin >> k >> n;

	vector<int> lans(k);

	for (int i = 0; i < k; i++) {
		cin >> lans[i];
		if (hig < lans[i]) hig = lans[i];
	}
	hig++;

	while (low < hig) {
		cnt = 0;
		mid = (low + hig) / 2;
		for (int i = 0; i < k; i++) {
			cnt += lans[i] / mid;
		}

		if (cnt < n) {
			hig = mid;
		}
		else {
			low = mid + 1;
		}
	}

	cout << low - 1;

}

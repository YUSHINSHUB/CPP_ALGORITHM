#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int rnum = n;
	int res = 0;

	vector<int> rop(n);
	for (int i = 0; i < n; i++) {
		cin >> rop[i];
	}

	sort(rop.begin(), rop.end());

	for (int i = 0; i < n; i++) {
		res = max(res, rop[i] * rnum);
		rnum--;
	}

	cout << res;

}
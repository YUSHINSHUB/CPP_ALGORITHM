#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int>scr(n);

	for (int i = 0; i < n; i++) {
		cin >> scr[i];
	}

	sort(scr.begin(), scr.end(), greater<int>());

	cout << scr[k - 1];

}
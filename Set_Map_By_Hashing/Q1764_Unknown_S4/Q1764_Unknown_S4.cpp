#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	string temp;
	map<string, int> hm;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		hm.insert(pair<string, int>(temp, 1));
	}

	set<string> hset;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		hm[temp]++;
		if (hm[temp] == 2) {
			hset.insert(temp);
			idx++;
		}
	}

	vector<string> out;
	out.reserve(hset.size());
	copy(hset.begin(), hset.end(), back_inserter(out));

	cout << idx << "\n";
	for (int i = 0; i < idx; i++) cout << out[i] << "\n";


}
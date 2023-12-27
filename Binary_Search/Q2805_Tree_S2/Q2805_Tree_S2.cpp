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

	int n;
	long long goal;
	cin >> n >> goal;
	long long h = 0;
	long long cut = 0;
	int idx = 0;

	int temp = 0;

	map<int, int> hm;
	set<int> hset;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		hset.insert(temp);
		if (hm.find(temp) != hm.end()) hm[temp]++;
		else hm.insert(pair<int, int>(temp, 1));
	}

	vector<int> trees;
	trees.reserve(hset.size());
	copy(hset.begin(), hset.end(), back_inserter(trees));
	sort(trees.begin(), trees.end(), greater<int>());

	for (int i = 0; i < trees.size() - 1; i++) {
		idx += hm[trees[i]];
		if (cut + ((trees[i] - trees[i + 1]) * idx) <= goal) {
			cut += ((trees[i] - trees[i + 1]) * idx);
			h += trees[i] - trees[i + 1];
		}
		else {
			h += (goal - cut) / idx;
			cut += ((goal - cut) / idx) * idx;
			if (cut != goal) {
				h++;
			}
			cut = goal;
			break;
		}
	}

	if (trees.size() == 1) {
		h = (goal / n);
		if (goal % n != 0) h++;
	}
	else if (cut != goal) {
		h += (goal - cut) / n;
		cut += ((goal - cut) / n) * n;
		if (cut != goal) h++;
	}

	cout << (trees[0] - h) << "";

}
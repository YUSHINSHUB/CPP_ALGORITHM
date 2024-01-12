#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> nc(n);
	for (int i = 0; i < n; i++) {
		cin >> nc[i];
	}
	int m;
	cin >> m;
	vector<int> mc(m);
	map<int, int> hm;
	map<int, int> res;

	for (int i = 0; i < m; i++) {
		cin >> mc[i];
		hm.insert(pair<int, int>(mc[i], i));
		res.insert(pair<int, int>(i, 0));
	}

	int cnt = 0;

	sort(nc.begin(), nc.end());
	sort(mc.begin(), mc.end());

	for (int i = 0; i < n; i++) {
		if (nc[i] == mc[cnt]) {
			res[hm[mc[cnt]]] = 1;
			cnt++;
		}
		else if (nc[i] > mc[cnt]) {
			while (nc[i] > mc[cnt]) {
				cnt++;
				if (cnt == m) break;
				if (mc[cnt] == nc[i]) {
					res[hm[mc[cnt]]] = 1;
					mc[cnt] = 1;
					cnt++;
					break;
				}
			}
		}

		if (cnt == m) break;

	}

	for (int i = cnt; i < m; i++) {
		res[hm[mc[i]]] = 0;
	}

	for (int i = 0; i < m; i++) cout << res[i] << " ";


}

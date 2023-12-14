#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

#define MAX 3000;

static int n;
static int m;
static vector<pair<int, int>> chp;
static vector<pair<int, int>> hop;
static bool pick[13];
static int res;

static void bt(int sidx, int cnt) {
	int sum = 0;
	int temp = 0;
	int minim = MAX;
	if (cnt == m) {
		for (int z = 0; z < hop.size(); z++) {
			minim = MAX;
			for (int i = 0; i < chp.size(); i++) {
				if (pick[i]) {
					temp = abs(hop[z].second - chp[i].second) + abs(hop[z].first - chp[i].first);
					minim = min(temp, minim);
				}
			}
			sum += minim;
		}
		res = min(sum, res);
		return;
	}
	else {
		for (int i = sidx; i < chp.size(); i++) {
			if (!pick[i]) {
				pick[i] = true;
				bt(i + 1, cnt + 1);
				pick[i] = false;
			}
		}
	}
}

int main() {

	cin >> n >> m;
	res = 3000;
	int chc = 0;
	int hom = 0;
	int temp = 0;

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++) {
			cin >> temp;
			if (temp == 1) {
				hop.push_back(pair<int, int>(z, i));
				hom++;
			}
			else if (temp == 2) {
				chp.push_back(pair<int, int>(z, i));
				chc++;
			}
		}
	}

	bt(0, 0);

	cout << res;
}
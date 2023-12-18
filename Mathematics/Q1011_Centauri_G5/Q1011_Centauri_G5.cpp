#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
using namespace std;

int main() {

	int t;
	cin >> t;
	int x, y;
	int spd = 0;
	int pos = 0;
	int res = 0;

	for (int i = 0; i < t; i++) {
		res = 0;
		spd = 0;
		cin >> x >> y;
		y -= x; // y는 거리
		pos = 0; // 현재위치
		while (pos < ((double)y / 2)) {
			spd++;
			pos += spd;
			res++;
		}

		pos -= spd;
		spd--;
		res--;
		res *= 2;

		if (y - (pos * 2) > spd + 1) {
			res += 2;
		}
		else {
			res += 1;
		}

		cout << res << "\n";

	}
}
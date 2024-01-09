#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <deque>
#include <sstream>
#include <stack>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> rag(n);
	int cnt = 1;
	int temp = 0;
	int res = 4;
	bool end = false;

	while (true) {
		temp = pow(cnt, 2);
		if (temp <= n) {
			rag[cnt - 1] = temp;
			cnt++;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < cnt; i++) {
		if (n == rag[i]) {
			res = 1;
			end = true;
			break;
		}
	}

	if (!end) {
		for (int i = 0; i < cnt; i++) {
			for (int j = i; j < cnt; j++) {
				if (n == rag[i] + rag[j]) {
					res = 2;
					end = true;
					break;
				}
			}
			if (end) break;
		}
	}

	if (!end) {
		for (int i = 0; i < cnt; i++) {
			for (int j = i; j < cnt; j++) {
				for (int k = j; k < cnt; k++) {
					if (n == rag[i] + rag[j] + rag[k]) {
						res = 3;
						end = true;
						break;
					}
				}
				if (end) break;
			}
			if (end) break;
		}
	}

	cout << res;
}
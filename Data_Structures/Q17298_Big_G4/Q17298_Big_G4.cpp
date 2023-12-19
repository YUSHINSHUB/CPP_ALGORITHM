#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {


	int n;
	cin >> n;

	vector<int>num(n);

	stack<int> stk;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int cnt = 1;

	while (true) {
		if (stk.empty()) {
			stk.push(cnt);
			cnt++;
			if (cnt > n) {
				break;
			}
		}
		else {
			if (num[(int)(stk.top()) - 1] < num[cnt - 1]) {
				num[(int)stk.top() - 1] = num[cnt - 1];
				stk.pop();
			}
			else {
				stk.push(cnt);
				cnt++;
				if (cnt > n) {
					break;
				}
			}
		}
	}

	while (!stk.empty()) {
		num[stk.top() - 1] = -1;
		stk.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << num[i] << " ";
	}

}

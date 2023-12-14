#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

	int n;
	cin >> n;

	stack<int> stk;

	vector<int> nums(n);
	vector<char> out(n * 2);
	int outcnt = 0;
	int cnt = 1;
	int numcnt = 0;
	int stkcnt = 0;

	bool suc = true;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	while (numcnt < n) {

		if (nums[numcnt] >= cnt) {
			while (nums[numcnt] >= cnt) {
				stk.push(cnt);
				cnt++;
				out[outcnt] = '+';
				outcnt++;
			}
		}
		else {
			if (stk.empty()) {
				suc = false;
				break;
			}
			while (stk.top() != nums[numcnt]) {
				stk.pop();
				out[outcnt] = '-';
				outcnt++;
				if (stk.empty()) {
					suc = false;
					break;
				}
			}
		}



		if (suc == false) {
			break;
		}
		else if (stk.top() == nums[numcnt]) {
			stk.pop();
			out[outcnt] = '-';
			outcnt++;
		}

		numcnt++;

	}

	if (suc == true) {
		for (int i = 0; i < outcnt; i++) {
			cout << out[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}

}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;

int main() {

	int ins[10];
	stack<int> stk;

	for (int i = 0; i < 10; i++) {
		cin >> ins[i];
	}

	int sum = 0;

	int a = 0;
	int b = 0;
	bool chk = true;

	for (int i = 0; i < 10; i++) {
		sum += ins[i];
		stk.push(sum);
		if (sum >= 100) {
			a = stk.top();
			stk.pop();
			if (!stk.empty()) {
				b = stk.top();
				stk.pop();
			}
			chk = false;
			break;
		}
	}

	if (chk == false) {
		a -= 100;
		b = 100 - b;

		if (a > b) {
			cout << 100 - b;
		}
		else {
			cout << a + 100;
		}
	}
	else {
		cout << stk.top();
	}
}
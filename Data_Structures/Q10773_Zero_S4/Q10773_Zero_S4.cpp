#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;


int main() {

	int k;
	int temp = 0;
	cin >> k;
	int res = 0;

	stack<int> stk;

	for (int i = 0; i < k; i++) {
		cin >> temp;
		if (temp == 0) stk.pop();
		else stk.push(temp);
	}

	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}

	cout << res;

}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

double calc(double a, double b, char c) {
	switch (c) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return 0;
	}
}

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	double temp1 = 0;
	double temp2 = 0;

	int index = 0;


	stack<double> stk;

	vector<double> nums(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			stk.push(nums[(s[i] - 65)]);
		}
		else {
			temp2 = stk.top();
			stk.pop();
			temp1 = stk.top();
			stk.pop();
			stk.push(calc(temp1, temp2, s[i]));
		}
	}


	double res = stk.top();
	stk.pop();

	cout.precision(2);
	cout << fixed << res;


}
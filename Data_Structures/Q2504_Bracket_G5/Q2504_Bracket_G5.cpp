#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;

int main() {

	string in;
	cin >> in;

	stack<char> stk;

	int res = 0;
	int mul = 1;

	for (int i = 0; i < in.length(); i++) {
		if (in[i] == '(') {
			mul *= 2;
			stk.push(in[i]);
		}
		else if (in[i] == '[') {
			mul *= 3;
			stk.push(in[i]);
		}
		else if (in[i] == ')') {
			if (stk.empty() || stk.top() == '[') {
				res = 0;
				break;
			}
			else if (in[i - 1] == '(') {
				mul /= 2;
				res += 2 * mul;
				stk.pop();
			}
			else {
				mul /= 2;
				stk.pop();
			}
		}
		else if (in[i] == ']') {
			if (stk.empty() || stk.top() == '(') {
				res = 0;
				break;
			}
			else if (in[i - 1] == '[') {
				mul /= 3;
				res += 3 * mul;
				stk.pop();
			}
			else {
				mul /= 3;
				stk.pop();
			}
		}
	}

	if (!stk.empty()) res = 0;

	cout << res;

}
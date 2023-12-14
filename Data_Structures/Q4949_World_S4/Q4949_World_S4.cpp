#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

bool t(int a) {
	return true;
}

int main() {

	string in;
	stack<char> stk;

	while (true) {
		getline(cin, in);

		if (in == ".") break;

		while (!stk.empty()) stk.pop();

		for (int i = 0; i < in.length(); i++) {
			if (in[i] == '(' || in[i] == '[') stk.push(in[i]);
			else if (in[i] == ')' && !stk.empty()) {
				if (stk.top() == '(') stk.pop();
				else {
					stk.push('0');
					break;
				}
			}
			else if (in[i] == ')' && stk.empty()) {
				stk.push('0');
				break;
			}
			else if (in[i] == ']' && !stk.empty()) {
				if (stk.top() == '[') stk.pop();
				else {
					stk.push('0');
					break;
				}
			}
			else if (in[i] == ']' && stk.empty()) {
				stk.push('0');
				break;
			}
		}

		if (stk.empty()) cout << "yes\n";
		else cout << "no\n";
	}

}
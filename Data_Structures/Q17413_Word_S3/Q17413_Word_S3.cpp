#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main() {

	string inp;
	getline(cin, inp);
	stack<char> stk;
	bool chk = true;

	for (int i = 0; i < inp.length(); i++) {
		while (inp[i] != '<' && inp[i] != ' ') {
			stk.push(inp[i]);
			i++;
			if (i == inp.length()) {
				chk = false;
				break;
			}
		}

		while (!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}

		if (chk == false) break;

		if (inp[i] == ' ') {
			cout << " ";
		}
		else if (inp[i] == '<') {
			while (inp[i] != '>') {
				cout << inp[i];
				i++;
			}
			cout << ">";
		}

	}
}
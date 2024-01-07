#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;

int check(char c) {
	if (c == '/' || c == '*') {
		return 3;
	}
	else if (c == '+' || c == '-') {
		return 2;
	}
	else {
		return 1;
	}
}


int main() {

	string s;

	cin >> s;

	stack<char> stk;
	string res;

	for (int i = 0; i < s.length(); i++) {
		if ((s[i] >= 'A' && s[i] <= 'Z')) {
			res += s[i];
			//A~Z는 순서대로 담아주면 된다.
		}
		else if (s[i] == '(') {
			stk.push(s[i]);
		}
		else if (s[i] == ')') {
			while (stk.top() != '(') {
				res += stk.top();
				stk.pop();
				//괄호가 끝나는 )를 만날경우 스택에서 괄호 내부의 연산자를 꺼낸 후
			}
			stk.pop();
			// 스택의 (를 제거한다.
		}
		else {
			while (!stk.empty() && check(stk.top()) >= check(s[i])) {
				res += stk.top();
				stk.pop();
				//스택에 먼저 담겨있던 연산자의 우선순위가 높을 경우 스택의 연산자를 먼저 꺼낸 후에 다음 연산자를 append해준다.
				//예시: *가 +보다 먼저 스택에 들어가 있을 경우에 *의 우선순위(3)가 +의 우선순위(2)보다 더 높기때문에 *부터 결과값으로
				//꺼내줘서 최종적으로 AB*+와 같은 형태가 되게 만든다.
			}
			stk.push(s[i]);
		}
	}
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
		//스택 내에 남아있는 연산자들을 모두 결과값으로 꺼내준다.
	}

	cout << res;

}

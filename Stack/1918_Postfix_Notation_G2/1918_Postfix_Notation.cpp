// 1918_Postfix_Notation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

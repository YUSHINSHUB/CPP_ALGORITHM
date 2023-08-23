// The concept behind the solution is that it uses a multiplier mul to track the nested depth of the parentheses. 
//Each pair of parentheses contributes a certain value to the final result res, 
//depending on the type of parentheses and the current value of the multiplier. 
//If the parentheses are not properly nested or balanced, the program resets the result to zero.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;

int main() {
	// Input string
	string in;
	cin >> in;

	// Stack to hold parentheses
	stack<char> stk;

	// Result and multiplier variables
	int res = 0;
	int mul = 1;

	// Loop over all characters in the input string
	for (int i = 0; i < in.length(); i++) {
		if (in[i] == '(') {
			// If character is '(', multiply mul by 2 and push it into the stack
			mul *= 2;
			stk.push(in[i]);
		}
		else if (in[i] == '[') {
			// If character is '[', multiply mul by 3 and push it into the stack
			mul *= 3;
			stk.push(in[i]);
		}
		else if (in[i] == ')') {
			// If character is ')', check if stack is empty or the top of stack is '[', if so, reset result and break
			if (stk.empty() || stk.top() == '[') {
				res = 0;
				break;
			}
			else if (in[i - 1] == '(') {
				// If the previous character is '(', add 2*mul to the result and adjust mul, pop from stack
				mul /= 2;
				res += 2 * mul;
				stk.pop();
			}
			else {
				// If the previous character is not '(', just adjust mul and pop from stack
				mul /= 2;
				stk.pop();
			}
		}
		else if (in[i] == ']') {
			// If character is ']', check if stack is empty or the top of stack is '(', if so, reset result and break
			if (stk.empty() || stk.top() == '(') {
				res = 0;
				break;
			}
			else if (in[i - 1] == '[') {
				// If the previous character is '[', add 3*mul to the result and adjust mul, pop from stack
				mul /= 3;
				res += 3 * mul;
				stk.pop();
			}
			else {
				// If the previous character is not '[', just adjust mul and pop from stack
				mul /= 3;
				stk.pop();
			}
		}
	}

	// If stack is not empty after processing all characters, reset result
	if (!stk.empty()) res = 0;

	// Print the result
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

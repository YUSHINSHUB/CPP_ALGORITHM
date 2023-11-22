/*
commented by ChatGPT
This C++ program is designed to create the largest possible number by removing K digits from a given number.
The number is read as a string, and a stack is used to keep track of the digits.
The algorithm iteratively compares the top of the stack with the next digit in the string.
If a smaller digit is found on the stack, it is removed to form a larger number.
The process continues until K digits are removed or the end of the string is reached.
The final number is constructed from the remaining digits in the stack.
이 C++ 프로그램은 주어진 숫자에서 K개의 숫자를 제거하여 가능한 가장 큰 숫자를 만드는 것을 목표로 합니다.
숫자는 문자열로 읽고 스택을 사용하여 숫자를 추적합니다.
알고리즘은 스택의 맨 위와 문자열의 다음 숫자를 반복적으로 비교합니다.
스택에 더 작은 숫자가 발견되면, 더 큰 숫자를 형성하기 위해 제거됩니다.
이 과정은 K개의 숫자가 제거되거나 문자열의 끝에 도달할 때까지 계속됩니다.
최종 숫자는 스택에 남아 있는 숫자로 구성됩니다.
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	string sb = ""; // 최종 숫자를 구성하기 위한 문자열
	int N, K;
	cin >> N >> K; // 숫자의 길이와 제거할 숫자의 개수 입력
	string num; // 주어진 숫자
	cin >> num;
	stack<char> stk; // 숫자를 저장하기 위한 스택

	for (int i = 0; i < N - 1; i++) {
		stk.push(num[i]); // 현재 숫자를 스택에 추가
		// 스택의 맨 위 숫자가 다음 숫자보다 작으면 제거
		while (!stk.empty() && K > 0) {
			if (stk.top() < num[i + 1]) {
				stk.pop();
				K--;
			}
			else
				break;
		}
	}
	stk.push(num[N - 1]); // 마지막 숫자 추가

	// 남은 K만큼 스택에서 숫자 제거
	while (K != 0) {
		stk.pop();
		K--;
	}

	// 스택에 남은 숫자를 문자열에 추가
	while (!stk.empty()) {
		sb += stk.top();
		stk.pop();
	}

	reverse(sb.begin(), sb.end()); // 문자열을 역순으로 변환

	cout << sb; // 결과 출력
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

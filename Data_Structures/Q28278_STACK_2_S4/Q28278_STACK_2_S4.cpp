/*
Commented by ChatGPT
Summary: This program simulates basic stack operations based on user input.
The user specifies the desired operations on the stack and the program executes and outputs the
results of these operations.
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; // Number of operations to be performed
	cin >> n;
	stack<int> stk; // Stack declaration
	int c, num;

	for (int i = 0; i < n; i++) {
		cin >> c;

		switch (c) {
		case 1: // Push an element onto the stack
			cin >> num;
			stk.push(num);
			break;
		case 2: // Pop an element from the stack
			if (stk.empty())
				cout << "-1\n"; // If stack is empty, print -1
			else {
				cout << stk.top() << "\n";
				stk.pop();
			}
			break;
		case 3: // Print the size of the stack
			cout << stk.size() << "\n";
			break;
		case 4: // Check if stack is empty
			if (stk.empty())
				cout << "1\n"; // If empty, print 1
			else
				cout << "0\n"; // If not empty, print 0
			break;
		case 5: // Peek the top element of the stack
			if (stk.empty())
				cout << "-1\n"; // If stack is empty, print -1
			else
				cout << stk.top() << "\n";
			break;
		}
	}
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

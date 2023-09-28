//Commented by ChatGPT
//Summary: program that simulates a double-ended queue (deque) and performs various 
//operations based on the user's input.

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Read the number of operations to perform on the deque
	int n, c, t;
	cin >> n;

	// Create a deque to store integers
	deque<int> stk;

	// Loop through each operation and execute accordingly
	for (int i = 0; i < n; i++) {
		cin >> c; // Read the operation code

		// Switch-case to determine which operation to execute
		switch (c) {
		case 1:
			cin >> t;
			// Add element to the front of the deque
			stk.push_front(t);
			break;
		case 2:
			cin >> t;
			// Add element to the end of the deque
			stk.push_back(t);
			break;
		case 3:
			// Remove and display element from the front of the deque. If deque is empty,
			// display -1
			if (stk.empty())
				cout << "-1\n";
			else {
				cout << stk.front() << "\n";
				stk.pop_front();
			}
			break;
		case 4:
			// Remove and display element from the end of the deque. If deque is empty,
			// display -1
			if (stk.empty())
				cout << "-1\n";
			else {
				cout << stk.back() << "\n";
				stk.pop_back();
			}
			break;
		case 5:
			// Display the current size of the deque
			cout << stk.size() << "\n";
			break;
		case 6:
			// Check if deque is empty and display 1 if true, 0 if false
			if (stk.empty())
				cout << "1\n";
			else
				cout << "0\n";
			break;
		case 7:
			// Display the element at the front of the deque without removing it. If deque
			// is empty, display -1
			if (stk.empty())
				cout << "-1\n";
			else {
				cout << stk.front() << "\n";
			}
			break;
		case 8:
			// Display the element at the end of the deque without removing it. If deque is
			// empty, display -1
			if (stk.empty())
				cout << "-1\n";
			else {
				cout << stk.back() << "\n";
			}
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

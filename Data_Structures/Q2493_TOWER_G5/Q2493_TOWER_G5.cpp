/*
	commented by ChatGPT
	Summary:
	The program processes a sequence of towers (given by their heights). For each tower,
	it determines the closest taller tower to its left and prints its position or 0 if none exists.
*/

#include <iostream>
#include <stack>
using namespace std;

// Class to represent each tower. Contains the height and position of the tower.
class top {
public:
	int hei;  // Height of the tower.
	int pos;  // Position of the tower in the sequence.

	// Constructor to initialize the height and position of the tower.
	top(int hei, int pos) {
		this->hei = hei;
		this->pos = pos;
	}
};

int main()
{
	stack<top> stk;  // Stack to store towers. This aids in finding the nearest taller tower to the left.
	int n;  // Number of towers.
	cin >> n;

	// Looping through each tower.
	for (int i = 1; i <= n; i++) {
		int t;  // Height of the current tower.
		cin >> t;

		// Keep popping towers from the stack until we find a taller tower.
		while (!stk.empty()) {
			if (stk.top().hei > t) break;  // Break out if a taller tower is found.
			else stk.pop();  // If the tower isn't taller, pop it from the stack.
		}

		// If the stack is empty, no taller tower exists to the left.
		if (stk.empty()) cout << "0 ";
		// If the stack isn't empty, the top of the stack is the taller tower.
		else cout << stk.top().pos << " ";

		// Push the current tower onto the stack.
		stk.push(top(t, i));
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

// Q2493_Tower_G5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>

using namespace std;

// Class to encapsulate the properties of a tower: its height and its position
	// in the sequence.
class top {
public:
	int hei; // Height of the tower.
	int pos; // Position of the tower in the sequence.

	// Constructor initializing the height and position of the tower.
	top(int hei, int pos) {
		this->hei = hei;
		this->pos = pos;
	}
};

int main()
{

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// Stack to store towers in the order they're encountered, aiding in the search
	// process.
	stack<top> stk;

	int n;
	cin >> n;

	// Iterate through each tower to determine and write the position of the taller
	// tower to its left.
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;

		// Continue popping towers from the stack until a taller tower is found.
		while (!stk.empty()) {
			if (stk.top().hei > t)
				break; // Stop if a taller tower is found.
			else
				stk.pop(); // Remove shorter or equal height towers from the stack.
		}

		// Write 0 if no taller tower exists to its left, otherwise, write the position
		// of the taller tower.
		if (stk.empty())
			cout << "0 ";
		else
			cout << stk.top().pos << " ";

		// Add the current tower to the stack.
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

/*
Commented by ChatGPT
Summary: This program solves the Tower of Hanoi problem using recursion.
Given the number of disks (n), it calculates the minimum number of moves required to solve the problem and prints the moves step-by-step.
*/

#include <iostream>
#include <math.h>

using namespace std;

// Recursive function to solve the Tower of Hanoi problem
void hanoi(int n, int s, int m, int e) {
	if (n == 1) { // Base case: if only one disk, move it from source to destination
		cout << s << " " << e << "\n";
		return;
	}

	// Move n-1 disks from source to auxiliary peg, using destination peg as
	// auxiliary
	hanoi(n - 1, s, e, m);

	// Move the nth disk from source to destination peg
	cout << s << " " << e << "\n";

	// Move the n-1 disks from auxiliary peg to destination peg, using source peg as
	// auxiliary
	hanoi(n - 1, m, s, e);
}

int main()
{
	int n;
	cin >> n;

	// Print the minimum number of moves required to solve the problem
	cout << (int)pow(2, n) - 1 << "\n";

	// Print the moves step-by-step
	hanoi(n, 1, 2, 3);
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

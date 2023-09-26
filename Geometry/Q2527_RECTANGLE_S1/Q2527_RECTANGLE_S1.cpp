/*
commented by ChatGPT
This C++ code determines the relationship between two given rectangles based on their coordinates.
이 C++ 코드는 주어진 두 개의 사각형의 좌표를 바탕으로 그들 사이의 관계를 판단합니다.
*/

#include <iostream>
using namespace std;

int main()
{
	// Iterating through four sets of rectangle coordinates
	// 4개의 사각형 좌표 세트를 반복 처리합니다.
	for (int i = 0; i < 4; i++) {
		int x1, y1, p1, q1, x2, y2, p2, q2;
		// Reading coordinates for the rectangles from standard input
		// 표준 입력에서 사각형의 좌표를 읽습니다.
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		// Checking the relationship between the two rectangles
		// 두 사각형 사이의 관계를 체크합니다.
		if (x1 > p2 || y1 > q2 || p1 < x2 || q1 < y2)
			cout << "d\n";
		else if ((x1 == p2 && y1 == q2) || (p1 == x2 && y1 == q2) || (x1 == p2 && q1 == y2)
			|| (p1 == x2 && q1 == y2))
			cout << "c\n";
		else if ((x1 == p2) || (y1 == q2) || (p1 == x2) || (q1 == y2))
			cout << "b\n";
		else
			cout << "a\n";
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

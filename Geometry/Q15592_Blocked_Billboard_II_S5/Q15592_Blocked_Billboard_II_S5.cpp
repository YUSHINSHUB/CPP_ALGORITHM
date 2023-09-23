// Commented by ChatGPT
// Summary: This C++ program computes the area of the first rectangle (L) that remains visible after being possibly overlapped by another rectangle (F).

#include <iostream>
using namespace std;

int main()
{
	// Read and store the coordinates of the first rectangle (L).
	int lx1, ly1, lx2, ly2;
	cin >> lx1 >> ly1 >> lx2 >> ly2;

	// Calculate the lengths of the sides of rectangle L.
	int lxlen = lx2 - lx1;
	int lylen = ly2 - ly1;
	int res = lxlen * lylen; // Initial area of rectangle L.

	// Read and store the coordinates of the second rectangle (F).
	int fx1, fy1, fx2, fy2;
	cin >> fx1 >> fy1 >> fx2 >> fy2;

	// Calculate the lengths of the sides of rectangle F (though these values aren't used directly in the code).
	int fxlen = fx2 - fx1;
	int fylen = fy2 - fy1;

	// Check the overlapping conditions between rectangle L and rectangle F.
	if (fy1 <= ly1 && fy2 >= ly2) {
		// When F entirely overlaps L vertically.
		if (fx1 <= lx1 && fx2 >= lx2) {
			// When F entirely overlaps L.
			res = 0;
		}
		else if (fx1 >= lx1 && fx1 <= lx2 && fx2 >= lx2) {
			// When F overlaps the right side of L.
			res = lylen * (fx1 - lx1);
		}
		else if (fx1 <= lx1 && fx2 <= lx2 && fx2 >= lx1) {
			// When F overlaps the left side of L.
			res = lylen * (lx2 - fx2);
		}
	}
	else if (fx1 <= lx1 && fx2 >= lx2) {
		// When F entirely overlaps L horizontally.
		if (fy1 >= ly1 && fy1 <= ly2 && fy2 >= ly2) {
			// When F overlaps the top of L.
			res = lxlen * (fy1 - ly1);
		}
		else if (fy1 <= ly1 && fy2 <= ly2 && fy2 >= ly1) {
			// When F overlaps the bottom of L.
			res = lxlen * (ly2 - fy2);
		}
	}

	// Output the resulting area.
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

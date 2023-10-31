/*
commented by ChatGPT
This C++ code calculates the year when three different cycles will coincide, given their current year within each cycle.
The cycles repeat every 15, 28, and 19 years respectively, and the program outputs the first year when all cycles align.
이 C++ 코드는 각 사이클 내 현재 연도를 주어진 상태에서 세 가지 다른 사이클이 겹치는 연도를 계산합니다.
사이클은 각각 15년, 28년, 19년마다 반복되며, 프로그램은 모든 사이클이 정렬되는 첫 번째 연도를 출력합니다.
*/

#include <iostream>

using namespace std;

int main() {
	// Input variables for the Earth, Sun, and Moon cycles
	int e, s, m;
	cin >> e >> s >> m;

	// Start searching from the current Sun cycle year
	int res = s;

	// Adjust the cycles if they are at their last year to zero-based
	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;

	// Increment by Sun's cycle until a year matches all three cycles
	while (res % 15 != e || res % 28 != s || res % 19 != m) {
		res += 28;
	}

	// Output the result year when all cycles coincide
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

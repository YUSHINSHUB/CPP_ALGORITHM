/*
   commented by ChatGPT
   Summary: The C++ program reads a matrix and calculates the Manhattan distance between
   the first two occurrences of the number "1" in the matrix.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Read matrix dimensions n and m
	int n, m;
	cin >> n >> m;

	// Initialize coordinate variables to store positions of the two occurrences of "1"
	int x1 = -1;
	int x2 = -1;
	int y1 = -1;
	int y2 = -1;

	int temp;

	// Iterate over the matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == 1) {
				if (x1 == -1) {
					// If this is the first occurrence of "1", store its position
					x1 = j;
					y1 = i;
				}
				else {
					// If this is the second occurrence, store its position and break out of loop
					x2 = j;
					y2 = i;
					break;
				}
			}
		}
		// If both occurrences have been found, break out of outer loop
		if (x2 >= 0)
			break;
	}

	// Print the Manhattan distance between the two occurrences of "1"
	cout << abs(x2 - x1) + abs(y2 - y1);
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

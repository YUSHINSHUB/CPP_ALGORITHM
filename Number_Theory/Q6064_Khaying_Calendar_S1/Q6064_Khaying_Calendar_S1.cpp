// Q6064_Khaying_Calendar_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	// Read the number of test cases
	int t;
	cin >> t;
	int m, n, x, y;

	// Loop over the test cases
	for (int i = 0; i < t; i++) {
		// Read the four integers for this test case
		cin >> m >> n >> x >> y;

		// Compute the maximum of m and n
		int hi = max(m, n);

		// Compute the least common multiple of m and n
		int end = hi;
		while (end % m != 0 || end % n != 0) {
			end += hi;
		}

		// Determine the starting point and increment
		int res = min(x, y);
		int up = (res == x) ? m : n;  // if res == x then up = m else up = n

		// If x or y is equal to m or n respectively, set them to zero
		if (m == x) x = 0;
		if (n == y) y = 0;

		// Find the smallest number meeting the conditions
		while (res <= end) {
			if (res % m == x && res % n == y) {
				// If the current number meets the conditions, break the loop
				break;
			}
			else {
				// Otherwise, increment res and check if we've reached the end
				res += up;
				if (res == end) {
					// If we're at the end and x or y is zero, add m or n to it
					if (x == 0) x += m;
					if (y == 0) y += n;
					// If res divides evenly into x and y, break the loop
					if (res % x == 0 && res % y == 0) break;
				}
			}
		}

		// If no suitable number was found, output -1
		if (res > end) res = -1;

		// Output the result
		cout << res << "\n";
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


// Commented by ChatGPT
// This program determines the minimum number of times a ship has to increase its speed to cover a given distance in C++.

#define _CRT_SECURE_NO_WARNINGS // This preprocessor directive is to suppress warnings related to unsafe C runtime library functions.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
using namespace std;

int main() {

	// Number of test cases
	int t;
	cin >> t;

	int x, y; // Starting and ending positions of the ship
	int spd = 0; // The current speed of the ship
	int pos = 0; // Current position of the ship
	int res = 0; // Result - the minimum number of times speed needs to be increased

	// Loop through each test case
	for (int i = 0; i < t; i++) {
		res = 0; // Reset the result for each test case
		spd = 0; // Reset the speed for each test case
		cin >> x >> y;

		y -= x; // Calculating the total distance to be traveled

		// Logic to determine the mid-point of the total distance
		// and then calculate the times speed needs to be increased
		while (pos < ((double)y / 2)) {
			spd++;
			pos += spd;
			res++;
		}

		pos -= spd;
		spd--;
		res--;
		res *= 2;

		// Adjusting the result based on the remaining distance to be covered
		if (y - (pos * 2) > spd + 1) {
			res += 2;
		}
		else {
			res += 1;
		}

		// Display the result for each test case
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

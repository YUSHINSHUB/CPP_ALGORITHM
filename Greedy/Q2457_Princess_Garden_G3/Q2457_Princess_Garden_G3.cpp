/*
commented by ChatGPT
This C++ program is designed to find the minimum number of flowers needed to ensure that at least one flower is blooming each day from March 1st to November 30th.
It reads the blooming and wilting dates of N flowers, converts them into day numbers of the year, and then employs a greedy algorithm to cover the period with the fewest flowers.
If it is impossible to cover the entire period, the program outputs 0.
이 C++ 프로그램은 3월 1일부터 11월 30일까지 매일 최소 한 송이의 꽃이 피어 있도록 필요한 최소한의 꽃을 찾는 것을 목적으로 합니다.
N개의 꽃의 개화 및 시듦 날짜를 읽고 연중 일자로 변환한 다음, 가장 적은 수의 꽃으로 기간을 커버하기 위해 탐욕 알고리즘을 사용합니다.
전체 기간을 커버할 수 없는 경우 프로그램은 0을 출력합니다.
*/

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	int N;
	cin >> N;
	int day[366]; // 각 일자별 꽃이 피는 기간을 저장하는 배열
	int res = 0; // 필요한 꽃의 최소 개수
	bool quit = false; // 전체 기간을 커버할 수 있는지 여부
	fill(day, day + 366, 0); // 배열 초기화

	for (int i = 0; i < N; i++) {
		int bm, bd, wm, wd;
		cin >> bm >> bd >> wm >> wd;
		int start = 0; // 개화 시작 일자
		int end = 0; // 개화 종료 일자

		// 개화 시작 월에 따른 시작 일자 계산
		switch (bm) {
		case 1: start = bd; break;
		case 2: start = 31 + bd; break;
		case 3: start = 59 + bd; break;
		case 4: start = 90 + bd; break;
		case 5: start = 120 + bd; break;
		case 6: start = 151 + bd; break;
		case 7: start = 181 + bd; break;
		case 8: start = 212 + bd; break;
		case 9: start = 243 + bd; break;
		case 10: start = 273 + bd; break;
		case 11: start = 304 + bd; break;
		case 12: start = 334 + bd; break;
		}

		// 개화 종료 월에 따른 종료 일자 계산
		switch (wm) {
		case 1: end = wd; break;
		case 2: end = 31 + wd; break;
		case 3: end = 59 + wd; break;
		case 4: end = 90 + wd; break;
		case 5: end = 120 + wd; break;
		case 6: end = 151 + wd; break;
		case 7: end = 181 + wd; break;
		case 8: end = 212 + wd; break;
		case 9: end = 243 + wd; break;
		case 10: end = 273 + wd; break;
		case 11: end = 304 + wd; break;
		case 12: end = 334 + wd; break;
		}

		day[start] = max(day[start], end - start); // 시작 일자에 대한 최대 커버 기간 업데이트
	}

	int idx = 60; // 시작 일자 (3월 1일)
	while (idx <= 334) { // 종료 일자 (11월 30일)까지
		int hig = INT_MIN; // 현재 위치에서 가능한 최대 커버 기간
		for (int i = idx; i >= 1; i--) {
			hig = max(hig, (i + day[i] - 1) - idx);
		}
		if (hig < 0) { // 커버 불가능한 기간 발견
			quit = true;
			break;
		}

		idx += hig + 1; // 다음 시작 위치로 이동
		res++; // 필요한 꽃의 수 증가
	}

	if (quit)
		cout << "0"; // 전체 기간 커버 불가
	else
		cout << res; // 필요한 꽃의 최소 개수 출력
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

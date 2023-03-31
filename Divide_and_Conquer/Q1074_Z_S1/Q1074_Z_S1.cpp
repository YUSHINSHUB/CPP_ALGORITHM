// Q1074_Z_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int calc(int n, int r, int c, int low, int hig) {

	n--;
	int res = 0;

	int line = (int)pow(2, n - 1);
	int temp = (hig - low) / 4;

	if (r > line && c > line) {
		low += temp * 3;
		r -= line;
		c -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (r <= line && c <= line) {
		hig = low + temp;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (r > line) {
		low += temp * 2;
		hig = low + temp;
		r -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (c > line) {
		low += temp;
		hig = low + temp;
		c -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	r++;
	c++;

	int hig = (int)pow(4, n);
	int line = (int)pow(2, n - 1);

	n++;
	int res = calc(n, r, c, 0, hig);


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

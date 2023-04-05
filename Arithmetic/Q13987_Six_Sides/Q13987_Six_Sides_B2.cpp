// Q13987_Six_Sides.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main()
{
	int win = 0, pair = 0;
	int f[6];
	int s[6];

	for (int i = 0; i < 6; i++) cin >> f[i];
	for (int i = 0; i < 6; i++) cin >> s[i];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (f[i] > s[j]) win++;
			else if (f[i] == s[j]) pair++;
		}
	}

	double add = (double)pair / 36;
	double base = (double)win / 36;
	double res = base;
	double res2 = base;
	base *= add;

	while (true) {
		res2 += base;
		if (res == res2) break;
		else {
			res = res2;
			base *= add;
		}
	}
	//base를 더하는 연산이 double형의 값에 영향을 주지 못할정도로 미세해질 때까지 연산을 반복한다.

	cout.precision(5);
	cout << fixed << res;
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

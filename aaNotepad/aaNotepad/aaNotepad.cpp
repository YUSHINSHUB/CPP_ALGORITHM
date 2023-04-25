// aaNotepad.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <vector>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int res = 0;
	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		int pri;
		if (a == b && a == c && a == d)
			pri = 50000 + (a * 5000);
		else if (a == b && a == c || a == b && a == d || a == c && a == d)
			pri = 10000 + (a * 1000);
		else if (b == c && b == d)
			pri = 10000 + (b * 1000);
		else if (a == b) {
			if (c == d)
				pri = 2000 + (a * 500) + (c * 500);
			else
				pri = 1000 + (a * 100);
		}
		else if (a == c) {
			if (b == d)
				pri = 2000 + (a * 500) + (b * 500);
			else
				pri = 1000 + (a * 100);
		}
		else if (a == d) {
			if (b == c)
				pri = 2000 + (a * 500) + (b * 500);
			else
				pri = 1000 + (a * 100);
		}
		else if (b == c)
			pri = 1000 + (b * 100);
		else if (b == d)
			pri = 1000 + (b * 100);
		else if (c == d)
			pri = 1000 + (c * 100);
		else {
			int hig = 0;
			if (a > hig)
				hig = a;
			if (b > hig)
				hig = b;
			if (c > hig)
				hig = c;
			if (d > hig)
				hig = d;
			pri = hig * 100;
		}

		if (res < pri)
			res = pri;
	}

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
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다
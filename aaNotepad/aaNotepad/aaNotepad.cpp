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

	int pri[1041] = {0,};
	pri[0] = 1; // 1은 소수x 0은 소수
	pri[1] = 0;
	pri[2] = 0;
	for (int i = 4; i <= 1040; i += 2) {
		pri[i] = 1;
	}

	for (int i = 3; i <= 1040; i += 2) {
		if (pri[i] == 0) {
			for (int j = i * 2; j <= 1040; j += i) {
				pri[j] = 1;
			}
		}
	}

	string inp;
	cin >> inp;

	int idx = 0;

	for (int i = 0; i < inp.length(); i++) {
		if (inp[i] >= 'a')
			idx += inp[i] - 'a' + 1;
		else
			idx += inp[i] - 'A' + 27;
	}

	if (pri[idx] == 0)
		cout << "It is a prime word.";
	else
		cout << "It is not a prime word.";
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
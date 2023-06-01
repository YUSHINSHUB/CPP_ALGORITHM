// Q1356_Equidigital_Number_B1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	int a = (int)pow(10, (int)log10(n)) * 10;
	int b = 10;

	string out = "NO";

	int r1 = (n % a) / (a / 10);
	int r2 = (n % b) / (b / 10);

	a /= 10;
	b *= 10;

	if (n >= 1000000000) {
		r1 = n / 1000000000;
		a = 1000000000;
	}


	while (true) {

		if (a == 1) {
			break;
		}

		if (a < b) {
			if (r1 == r2) {
				out = "YES";
			}
			break;
		}

		if (r1 > r2) {
			r2 *= (n % b) / (b / 10);
			b *= 10;
		}
		else {
			r1 *= (n % a) / (a / 10);
			a /= 10;
		}

	}

	string chk = to_string(n);
	int cnt = 0;

	for (int i = 0; i < chk.length(); i++) {
		if (chk[i] == '0') {
			cnt++;
		}
		if (cnt == 2) {
			out = "YES";
			break;
		}
	}

	cout << out;
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

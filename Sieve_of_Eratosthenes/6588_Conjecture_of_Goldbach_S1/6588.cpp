﻿// 6588.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//해당 명령문을 사용하여 cin, cout의 속도를 늘릴 수 있다.

	int chk[1000001];
	//c++에서 bool 배열을 사용하면 왜인지 모르게 틀렸다고 떠서 int형을 사용함.
	//프로젝트 속성에 들어가서 구성속성 -> 링커 -> 시스템에서 스택 예약 크기를 늘려줘야 스택 오버플로우가 발생하지 않음.
	chk[0] = 1;
	chk[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (chk[i] != 1) {
			chk[i] = 0;
			for (int z = i * 2; z <= 1000000; z += i) {
				chk[z] = 1;
			}
		}
	}

	while (true) {

		int n;
		cin >> n;

		if (n == 0) {
			break;
		}
		bool check = true;

		for (int i = 3; i <= n; i += 2) {
			if (chk[i] == 0 && chk[n - i] == 0) {
				cout << n << " = " << i << " + " << n - i << "\n";
				check = false;
				break;
			}

		}

		if (check == true) {
			cout << "Goldbach's conjecture is wrong.\n";
		}


	}

	return 0;
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

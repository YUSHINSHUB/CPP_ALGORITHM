﻿// Q27930_Believe_in_Destiny_B1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	string k = "KOREA";
	string y = "YONSEI";

	int idxk = 0;
	int idxy = 0;

	int res = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == k[idxk]) {
			idxk++;
		}

		if (idxk == 5) {
			res = 1;
			break;
		}

		if (s[i] == y[idxy]) {
			idxy++;
		}

		if (idxy == 6) {
			res = 2;
			break;
		}

	}

	switch (res) {
	case 1:
		cout << "KOREA";
		break;
	case 2:
		cout << "YONSEI";
		break;
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

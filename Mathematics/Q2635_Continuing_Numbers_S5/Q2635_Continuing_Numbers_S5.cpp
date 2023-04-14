﻿// Q2635_Continuing_Numbers_S5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;


int main() {


	int n;
	cin >> n;

	int a = n, b = n, res = 0, acnt = 0, bcnt = 0;

	for (int i = n / 2; i <= n; i++) {
		acnt = bcnt;
		bcnt = 0;
		a = n;
		b = i;
		while (true) {
			int temp = a;
			a = b;
			b = temp - b;
			bcnt++;
			if (b < 0) break;
		}
		if (bcnt < acnt) {
			res = i - 1;
			break;
		}
		else if (i == n) {
			res = i;
			break;
		}
	}

	queue<int> q;
	q.push(n); q.push(res);
	a = n; b = res;
	bcnt = 2;
	while (true) {
		int temp = a;
		a = b;
		b = temp - b;
		if (b < 0) break;
		q.push(b);
		bcnt++;

	}

	cout << bcnt << "\n";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
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
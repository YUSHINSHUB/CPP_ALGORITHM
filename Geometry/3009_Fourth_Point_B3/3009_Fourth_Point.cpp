﻿// 3009_Fourth_Point.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class pos {
public:
	int x;
	int y;

	//C++의 클래스에서 생성자가 존재할 경우 객체 배열을 선언할 때 초기화 오류가 발생하기 떄문에
	// 생성자 대신 메소드를 사용하여 추후에 멤버의 값을 대입하는 방식을 채택하였다.

	void setpos(int x, int y) {
		this->x = x;
		this->y = y;
	}

};

int main() {

	pos p[3];

	int x, y;

	for (int i = 0; i < 3; i++) {
		int tempx, tempy;
		cin >> tempx >> tempy;
		p[i].setpos(tempx, tempy);
	}

	if (p[1].x == p[0].x) {
		x = p[2].x;
	}
	else if (p[2].x == p[0].x) {
		x = p[1].x;
	}
	else {
		x = p[0].x;
	}

	if (p[1].y == p[0].y) {
		y = p[2].y;
	}
	else if (p[2].y == p[0].y) {
		y = p[1].y;
	}
	else {
		y = p[0].y;
	}

	cout << x << " " << y;

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

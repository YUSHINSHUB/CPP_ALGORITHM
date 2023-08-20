﻿// 이 코드는 a, b, c를 입력받아 함수 recur을 호출하는 main 함수와, 
//재귀적으로 a^b를 계산하는 recur 함수로 구성되어 있습니다. 
//recur 함수는 b가 0일 경우 1을 반환하고, b가 짝수일 경우 a^(b/2)를 먼저 계산하여 그 결과를 제곱하고, 
//b가 홀수일 경우 a^(b/2)를 먼저 계산하여 그 결과를 제곱한 후 다시 a를 곱합니다. 
//모든 중간 결과는 c로 나눈 나머지를 사용하여 오버플로우를 방지합니다.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// 함수 recur: a^b를 계산하되, 중간 계산 결과도 c로 나눈 나머지를 사용
static long recur(long a, long b, long c) {
	// base case: 지수가 0이면 1을 반환
	if (b == 0) {
		return 1;
	}
	// 지수가 짝수이면, a^(b/2)를 먼저 계산하여 그 결과를 제곱
	else if (b % 2 == 0) {
		long re = recur(a, b / 2, c) % c;
		return (re * re) % c;
	}
	// 지수가 홀수이면, a^(b/2)를 먼저 계산하여 그 결과를 제곱한 다음 a를 곱함
	else {
		long re = recur(a, b / 2, c) % c;
		return (re * (((re) * (a % c)) % c)) % c;
	}
}

int main() {
	// 사용자로부터 a, b, c를 입력받음
	long a, b, c;
	cin >> a >> b >> c;

	// recur 함수를 호출하여 결과를 출력
	cout << recur(a, b, c);
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
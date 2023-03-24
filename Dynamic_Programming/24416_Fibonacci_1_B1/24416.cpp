// 24416.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 0;
int cnt2 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt1++;
		return 1;  // 코드1
	}
	else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	vector<int>f(n + 1);
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		cnt2++;
		f[i] = f[i - 1] + f[i - 2];  // 코드2
	}
	return f[n];
}

int main() {

	int n;
	cin >> n;
	fib(n);
	fibonacci(n);

	cout << cnt1 << " " << cnt2;
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

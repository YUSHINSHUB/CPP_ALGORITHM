// 2579_Upstair.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;


int main() {

	int n;

	cin >> n;

	vector<int> stair(n);
	vector<int> maxv(n);

	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}

	maxv[0] = stair[0];

	if (n > 1) {
		maxv[1] = stair[0] + stair[1];
	}

	if (n > 2) {
		maxv[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	}

	if (n > 3) {
		for (int i = 3; i < n; i++) {
			maxv[i] = max(maxv[i - 3] + stair[i - 1] + stair[i], maxv[i - 2] + stair[i]);
		}
	}

	cout << maxv[n - 1];

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

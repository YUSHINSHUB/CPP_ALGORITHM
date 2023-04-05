// Q1052_Bottle_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int cnt = 0; //n에서 2를 나누어 나갈때 만나는 홀수의 개수

	queue<int> q; // 홀수 저장
	int res = n;

	int n2 = n;
	while (n2 != 0) {
		if (n2 % 2 == 0) {
			n2 /= 2;
		}
		else {
			q.push(n2);
			n2 /= 2;
			cnt++; //n이 홀수일 때마다 못옮겨담는 병이 하나씩 생긴다.
		}
	}

	if (cnt > k) {
		cnt -= k;
		for (int i = 0; i < cnt; i++) q.pop(); //cnt-k번째로 큰 홀수까지 q에서 뺴준 후 그 뒤부터 진행한다.
		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			temp++;
			while (temp < n) {
				temp *= 2;
			}
			res = min(temp - n, res);
		}
	}
	else res = 0;

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
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

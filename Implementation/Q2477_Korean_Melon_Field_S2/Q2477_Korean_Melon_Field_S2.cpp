// Q2477_Korean_Melon_Field_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;
	int dir[6];
	int len[6];
	int lrbeg = 0;
	int udbeg = 0;
	int clk = -1;
	int res = 0;

	for (int i = 0; i < 6; i++) {
		cin >> dir[i] >> len[i];
		if (dir[i] == 1 || dir[i] == 2) {
			if (clk == -1)
				clk = dir[i];
			lrbeg += dir[i];
		}
		else {
			udbeg += dir[i];
		}
	}

	if (lrbeg == 4) {
		for (int i = 0; i < 6; i++) {
			if (dir[i] == 2) {

				int u = i + 1;
				int d = i - 1;
				if (u > 5)
					u -= 6;
				if (d < 0)
					d += 6;

				if (udbeg == 11) {
					if (dir[u] == 4) {
						res += len[i] * len[u];
						d = u + 2;
						u += 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
					else {
						res += len[i] * len[d];
						d = i + 2;
						u = i + 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
				}
				else {
					if (dir[u] == 3) {
						res += len[i] * len[u];
						d = u + 2;
						u += 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
					else {
						res += len[i] * len[d];
						d = i + 2;
						u = i + 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
				}

			}
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			if (dir[i] == 1) {

				int u = i + 1;
				int d = i - 1;
				if (u > 5)
					u -= 6;
				if (d < 0)
					d += 6;

				if (udbeg == 11) {
					if (dir[u] == 4) {
						res += len[i] * len[u];
						d = u + 2;
						u += 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
					else {
						res += len[i] * len[d];
						d = i + 2;
						u = i + 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
				}
				else {
					if (dir[u] == 3) {
						res += len[i] * len[u];
						d = u + 2;
						u += 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
					else {
						res += len[i] * len[d];
						d = i + 2;
						u = i + 3;
						if (u > 5)
							u -= 6;
						if (d > 5)
							d -= 6;
						res += len[u] * len[d];
					}
				}

			}
		}
	}

	res *= k;
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

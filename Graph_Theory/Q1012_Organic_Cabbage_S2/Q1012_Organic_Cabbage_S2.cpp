// Q1012_Organic_Cabbage_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

static bool pos[50][50];
static bool visited[50][50];
static int xpos[] = { 1, -1, 0, 0 };
static int ypos[] = { 0, 0, 1, -1 };
static int m, n;

static void dfs(int y, int x) {
	int xp, yp;
	for (int i = 0; i < 4; i++) {
		xp = x + xpos[i];
		yp = y + ypos[i];
		if (xp >= 0 && xp < m && yp >= 0 && yp < n) {
			if (pos[yp][xp] && !visited[yp][xp]) {
				visited[yp][xp] = true;
				dfs(yp, xp);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;
	int k;
	int x, y, res;

	for (int i = 0; i < t; i++) {
		res = 0;
		cin >> m >> n >> k;
		memset(pos, false, sizeof(pos));
		memset(visited, false, sizeof(visited));

		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			pos[y][x] = true;
		}

		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				if (pos[j][l] && !visited[j][l]) {
					visited[j][l] = true;
					dfs(j, l);
					res++;
				}
			}
		}

		cout << res << "\n";
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

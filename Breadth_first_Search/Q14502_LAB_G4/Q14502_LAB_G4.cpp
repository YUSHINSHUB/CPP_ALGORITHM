/*
commented by ChatGPT

이 C++ 코드는 주어진 2차원 배열의 특정 지점에 장애물을 3개 설치하여 바이러스가 퍼지지 않는 영역의 최대 크기를 찾는 문제를 해결합니다.
바이러스는 상하좌우로 퍼질 수 있으며, 퍼지지 않는 영역을 찾기 위해 BFS(너비 우선 탐색) 알고리즘을 사용합니다.

This C++ code solves a problem where obstacles are placed at specific points in a given 2D array to find the maximum size of the area where a virus does not spread.
The virus can spread up, down, left, and right. To find the non-infected area, the BFS (Breadth-First Search) algorithm is used.
*/

#include <iostream>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int n, m; // 행과 열의 크기 (Dimensions of the rows and columns)
int res = 0; // 최대 안전 영역의 크기 (Size of the maximum safe area)
int ypos[] = { -1, 1, 1, -1 }; // 세로 방향 이동 (Vertical movement)
int xpos[] = { 0, 1, -1, -1 }; // 가로 방향 이동 (Horizontal movement)
int grp[8][8]; // 입력 맵 (Input map)
queue<int> xq;
queue<int> yq;

// 바이러스를 퍼뜨리는 BFS 함수 (BFS function to spread the virus)
void bfs(int y, int x, int idx) {
	if (idx == 3) {
		int temp = 0;
		int
			tgrp[8][8];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tgrp[i][j] = grp[i][j];
			}
		}

		for (int j = 0; j < yq.size(); j++) {
			queue<int> tyq;
			queue<int> txq;

			tyq.push(yq.front());
			txq.push(xq.front());

			yq.push(yq.front());
			yq.pop();
			xq.push(xq.front());
			xq.pop();

			// 바이러스 퍼뜨리기 (Spreading the virus)
			while (!tyq.empty()) {
				int ty = tyq.front();
				tyq.pop();
				int tx = txq.front();
				txq.pop();

				for (int i = 0; i < 4; i++) {
					ty += ypos[i];
					tx += xpos[i];

					if (ty < 0 || ty >= n || tx < 0 || tx >= m)
						continue;
					else if (tgrp[ty][tx] == 0) {
						tyq.push(ty);
						txq.push(tx);
						tgrp[ty][tx] = 2;
					}
				}
			}
		}

		// 안전 영역 계산 (Calculate the safe area)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tgrp[i][j] == 0)
					temp++;
			}
		}

		res = max(res, temp);

	}
	else {
		// 장애물 설치하기 (Placing obstacles)
		for (int i = y; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == 0 && i == y) j = x;
				if (j >= m) break;
				if (grp[i][j] == 0) {
					grp[i][j] = 1;
					bfs(i, j + 1, idx + 1);
					grp[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grp[i][j];
			if (grp[i][j] == 2) {
				yq.push(i);
				xq.push(j);
			}
		}
	}

	bfs(0, 0, 0);
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

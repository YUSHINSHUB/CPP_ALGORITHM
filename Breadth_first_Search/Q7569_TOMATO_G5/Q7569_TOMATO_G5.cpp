#include <iostream>
#include <queue>

using namespace std;

// Dimensions for the 3D grid (3D 그리드의 크기)
int m, n, h;

// 3D array to store tomato states (토마토 상태를 저장하는 3D 배열)
int tom[101][101][101];

// Result to store minimum days required (모든 토마토가 익는데 필요한 최소 일수)
int res = 0;

// Queues to store coordinates of ripe tomatoes (익은 토마토의 좌표를 저장하기 위한 큐)
queue<int> yq;
queue<int> xq;
queue<int> hq;

// Directions to check neighboring tomatoes in the 3D grid (3D 그리드에서 이웃한 토마토를 확인하기 위한 방향)
int ypos[] = { 1, -1, -1, 1, 0, 0 };
int xpos[] = { 0, 1, -1, -1, 1, 0 };
int hpos[] = { 0, 0, 0, 0, 1, -2 };

// Breadth-first search function to ripen tomatoes (토마토를 익히기 위한 너비 우선 탐색 함수)
void bfs() {
	while (true) {
		queue<int> ytq;
		queue<int> xtq;
		queue<int> htq;

		// Transfering tomatoes from main queues to temp queues (메인 큐에서 임시 큐로 토마토 이동)
		while (!yq.empty()) {
			ytq.push(yq.front()); yq.pop();
			xtq.push(xq.front()); xq.pop();
			htq.push(hq.front()); hq.pop();
		}

		if (ytq.empty()) // If temp queues are empty, break out of loop (임시 큐가 비어있으면 루프 탈출)
			break;

		res++; // Increase days as we go to next level in BFS (BFS의 다음 레벨로 넘어갈 때 일수 증가)

		while (!ytq.empty()) { // Process each tomato in current level (현재 레벨의 각 토마토 처리)
			int y = ytq.front(); ytq.pop();
			int x = xtq.front(); xtq.pop();
			int z = htq.front(); htq.pop();

			for (int i = 0; i < 6; i++) { // Check all 6 directions for each tomato (각 토마토에 대해 6개의 방향 확인)
				y += ypos[i];
				x += xpos[i];
				z += hpos[i];

				if (y < 0 || y >= m || x < 0 || x >= n || z < 0 || z >= h) // Boundary condition (경계 조건)
					continue;

				// If neighboring position is unripe tomato, then ripen it and add to queue (이웃한 위치가 익지 않은 토마토라면 익히고 큐에 추가)
				if (tom[y][x][z] == 0) {
					yq.push(y);
					xq.push(x);
					hq.push(z);
					tom[y][x][z] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> m >> n >> h;

	// Reading initial tomato states and adding ripe tomatoes to queue (토마토의 초기 상태 읽기 및 익은 토마토를 큐에 추가)
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tom[k][j][i];
				if (tom[k][j][i] == 1) {
					yq.push(k);
					xq.push(j);
					hq.push(i);
				}
			}
		}
	}

	bfs(); // Calling BFS function to ripen all tomatoes (BFS 함수 호출하여 모든 토마토 익히기)

	// Check if any tomato is still unripe after BFS (BFS 후에도 익지 않은 토마토가 있는지 확인)
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tom[k][j][i] == 0) {
					res = 0;
				}
			}
		}
	}

	cout << res - 1; // Subtracting 1 from result because the initial state is considered a day (결과에서 1을 빼는 이유는 초기 상태도 하루로 간주되기 때문)
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

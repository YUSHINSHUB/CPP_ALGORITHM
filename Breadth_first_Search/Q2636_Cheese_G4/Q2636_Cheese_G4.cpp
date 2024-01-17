/*
commented by ChatGPT
This C++ code implements a Breadth-First Search (BFS) algorithm to process a grid.
The grid is represented by a 2D integer array 'grid', with corresponding 2D boolean array 'visited' for tracking cell visitation.
The BFS algorithm explores the grid, modifying cell values and counting certain cell types.
The main function reads the grid's dimensions and values, then repeatedly calls the BFS function until a specified condition is met, recording the number of iterations and the count of a specific cell type in the final iteration.
이 C++ 코드는 격자에서 너비 우선 탐색(BFS) 알고리즘을 구현합니다. 격자는 2차원 정수 배열 'grid'로 표현되며, 각 셀이 방문되었는지를 추적하는 2차원 불리언 배열 'visited'가 있습니다.
BFS 알고리즘은 격자를 탐색하면서 셀 값들을 수정하고 특정 셀 유형의 수를 계산합니다.
메인 함수는 격자의 크기와 값을 읽은 후 특정 조건이 충족될 때까지 반복적으로 BFS 함수를 호출하며, 마지막 반복에서 특정 셀 유형의 수와 반복 횟수를 기록합니다.
*/

#include <iostream>
#include <queue>
using namespace std;

int grid[100][100];
bool visited[100][100];
int r, c;
int ny[] = { 1, -1, 0, -1 };
int nx[] = { 0, -1, 2, -1 };

static int bfs() {
	int cnt = 0;

	queue<int> yq;
	queue<int> xq;
	yq.push(0);
	xq.push(0);
	for (int i = 0; i < r; i++) {
		fill(visited[i], visited[i] + c, false);
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 1)
				cnt++;
		}
	}

	while (!yq.empty()) {
		int cy = yq.front();
		int cx = xq.front();
		yq.pop();
		xq.pop();
		if (grid[cy][cx] == 1) {
			grid[cy][cx] = 0;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			cy += ny[i];
			cx += nx[i];
			if (cy < 0 || cx < 0 || cy >= r || cx >= c)
				continue;
			else if (visited[cy][cx])
				continue;

			visited[cy][cx] = true;
			yq.push(cy);
			xq.push(cx);
		}
	}

	return cnt;
}

int main()
{
	int idx = 0;
	int cnt = 0;

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> grid[i][j];
	}

	while (true) {
		int temp = bfs();
		if (temp == 0)
			break;
		cnt = temp;
		idx++;
	}

	cout << idx << "\n" << cnt;
}

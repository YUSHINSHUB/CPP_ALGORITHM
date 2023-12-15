
/*
commented by ChatGPT
This C++ code implements a Breadth-First Search (BFS) algorithm to count the number of islands in a sea represented as a 2D grid.
Each cell in the grid is either land (1) or water (0).
The bfs function marks the cells of an island as visited, using queues to manage the current cell's coordinates.
The search function iterates through the grid, calling bfs for each unvisited land cell and incrementing an island counter.
The program continues to process new grids until an input with both dimensions as zero is provided, indicating the end of input.
이 C++ 코드는 2D 그리드로 표현된 바다에서 섬의 수를 세기 위한 너비 우선 탐색(BFS) 알고리즘을 구현합니다.
그리드의 각 셀은 땅(1) 또는 물(0)입니다.
bfs 함수는 섬의 셀을 방문한 것으로 표시하며, 큐를 사용하여 현재 셀의 좌표를 관리합니다.
search 함수는 그리드를 반복하며 방문하지 않은 땅 셀마다 bfs를 호출하고 섬 카운터를 증가시킵니다.
프로그램은 두 차원 모두 0인 입력이 제공될 때까지 새로운 그리드를 계속 처리합니다.
이는 입력의 끝을 나타냅니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int sea[50][50]; // 2D array representing the sea grid (바다 그리드를 나타내는 2D 배열)
int nexty[] = { 1, 0, 0, -1, 0, -1, 0, 0 }; // Y-axis movements for BFS (BFS를 위한 Y축 이동)
int nextx[] = { -1, 1, 1, -2, 2, -2, 1, 1 }; // X-axis movements for BFS (BFS를 위한 X축 이동)

// BFS function to explore and mark an island (섬을 탐색하고 표시하는 BFS 함수)
static void bfs(int w, int h, int y, int x) {
	queue<int> yq; // Queue for Y-axis positions (Y축 위치를 위한 큐)
	queue<int> xq; // Queue for X-axis positions (X축 위치를 위한 큐)
	yq.push(y);
	xq.push(x);

	while (!yq.empty()) {
		int cury = yq.front();
		int curx = xq.front();
		yq.pop();
		xq.pop();
		for (int i = 0; i < 8; i++) {
			cury += nexty[i];
			curx += nextx[i];
			if (cury < 0 || curx < 0 || cury >= h || curx >= w) // Check boundary conditions (경계 조건 확인)
				continue;
			if (sea[cury][curx] == 0) // Skip if water (물인 경우 건너뛰기)
				continue;
			sea[cury][curx] = 0; // Mark the land as visited (땅을 방문한 것으로 표시)
			yq.push(cury); // Add new positions to the queues (큐에 새 위치 추가)
			xq.push(curx);
		}
	}
}

// Function to search for islands in the grid (그리드에서 섬을 찾기 위한 함수)
static int search(int w, int h) {
	int res = 0; // Counter for the number of islands (섬의 수를 세는 카운터)
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (sea[i][j] == 1) { // If land is found (땅이 발견되면)
				res++; // Increment the island counter (섬 카운터 증가)
				sea[i][j] = 0; // Mark the land as visited (땅을 방문한 것으로 표시)
				bfs(w, h, i, j); // Perform BFS for the island (섬에 대해 BFS 수행)
			}
		}
	}
	return res; // Return the number of islands (섬의 수 반환)
}

int main() {
	int w, h; // Variables for the width and height of the sea grid (바다 그리드의 너비와 높이를 위한 변수)

	while (true) {
		cin >> w >> h; // Read the width and height of the grid (그리드의 너비와 높이 읽기)
		if (w + h == 0) // Check for termination condition (종료 조건 확인)
			break;

		// Read and populate the sea grid (바다 그리드 읽기 및 채우기)
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> sea[i][j];
			}
		}

		cout << search(w, h) << "\n"; // Output the number of islands found (찾은 섬의 수 출력)
	}
}
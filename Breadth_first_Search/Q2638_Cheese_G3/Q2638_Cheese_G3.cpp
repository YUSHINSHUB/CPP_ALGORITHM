
/*
commented by ChatGPT
This C++ code simulates a process that affects a grid, where each cell's state can change under certain conditions, implemented using a breadth-first search (BFS) algorithm.
It initializes a grid with specified dimensions and values, then systematically updates these values through BFS to model a spreading effect.
The program iterates until no further changes are possible according to the specified conditions. The aim is to determine the number of iterations (or "steps") required for the process to complete.
The grid represents a hypothetical scenario where each cell's value can represent various states, and the BFS algorithm models the spread of a condition across adjacent cells.
이 C++ 코드는 특정 조건 하에서 각 셀의 상태가 변경될 수 있는 그리드에 영향을 미치는 과정을 시뮬레이션합니다. 이 과정은 너비 우선 탐색(BFS) 알고리즘을 사용하여 구현됩니다.
지정된 차원 및 값으로 그리드를 초기화한 다음, BFS를 통해 이러한 값들을 체계적으로 업데이트하여 퍼져나가는 효과를 모델링합니다. 프로그램은 지정된 조건에 따라 더 이상 변경이 불가능할 때까지 반복됩니다.
목표는 과정이 완료되기 위해 필요한 반복(또는 "단계") 횟수를 결정하는 것입니다.
그리드는 각 셀의 값이 다양한 상태를 나타낼 수 있는 가상 시나리오를 나타내며, BFS 알고리즘은 인접 셀 간의 조건 확산을 모델링합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int N, M; // N: Grid height, M: Grid width (그리드의 높이, 그리드의 너비)
int grid[100][100]; // Stores the state of each cell in the grid (그리드의 각 셀 상태 저장)
int ny[] = { 1, 0, 0, -1 }; // Movement in the y-direction (y방향 이동)
int nx[] = { 0, -1, 1, 0 }; // Movement in the x-direction (x방향 이동)

void bfs() { // Performs Breadth-First Search to simulate the spreading process (너비 우선 탐색을 수행하여 퍼지는 과정을 시뮬레이션)

	queue<int> yq; // Queue for y-coordinates (y좌표를 위한 큐)
	queue<int> xq; // Queue for x-coordinates (x좌표를 위한 큐)
	bool visited[100][100]; // Tracks whether a cell has been visited (셀이 방문되었는지 추적)

	yq.push(0); // Start from the top-left cell (왼쪽 상단 셀에서 시작)
	xq.push(0);

	for (int i = 0; i < N; i++)
		fill(visited[i], visited[i] + M, false); // Initialize all cells as unvisited (모든 셀을 미방문으로 초기화)

	while (!yq.empty()) { // Continue until there are no more cells to visit (방문할 셀이 더 이상 없을 때까지 계속)

		int cy = yq.front(); // Current y-coordinate (현재 y좌표)
		int cx = xq.front(); // Current x-coordinate (현재 x좌표)
		yq.pop();
		xq.pop();

		for (int i = 0; i < 4; i++) { // Explore all four directions (네 방향 모두 탐색)
			int y = cy + ny[i]; // Calculate new y-coordinate (새로운 y좌표 계산)
			int x = cx + nx[i]; // Calculate new x-coordinate (새로운 x좌표 계산)
			if (y < 0 || x < 0 || y >= N || x >= M) // Skip if out of bounds (범위를 벗어나면 건너뛰기)
				continue;
			if (visited[y][x]) // Skip if already visited (이미 방문한 경우 건너뛰기)
				continue;
			if (grid[y][x] > 0) { // Increment cell value if greater than 0 (0보다 큰 경우 셀 값 증가)
				grid[y][x]++;
				continue;
			}
			visited[y][x] = true; // Mark cell as visited (셀을 방문한 것으로 표시)
			yq.push(y); // Add new coordinates to queues (큐에 새 좌표 추가)
			xq.push(x);
		}

	}

	for (int i = 0; i < N; i++) { // After BFS, update the grid based on new values (BFS 후, 새 값에 따라 그리드 업데이트)
		for (int j = 0; j < M; j++) {
			if (grid[i][j] > 2) // Reset cell to 0 if value is greater than 2 (값이 2보다 큰 경우 0으로 리셋)
				grid[i][j] = 0;
			else if (grid[i][j] == 2) // Set cell to 1 if value is 2 (값이 2인 경우 1로 설정)
				grid[i][j] = 1;
		}
	}
}

bool check() { // Checks if the process is complete (과정이 완료되었는지 확인)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] > 0) // Return false if any cell's value is greater than 0 (어떤 셀의 값이 0보다 크면 false 반환)
				return false;
		}
	}
	return true; // Return true if all cells' values are 0 (모든 셀의 값이 0이면 true 반환)
}

int main() {
	int res = 0; // Counter for the number of iterations (반복 횟수 카운터)

	cin >> N >> M; // Read grid dimensions (그리드 차원 읽기)

	for (int i = 0; i < N; i++) { // Read initial grid state (초기 그리드 상태 읽기)
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	while (true) { // Repeat until the process is complete (과정이 완료될 때까지 반복)
		if (check()) // Check if the process is complete (과정이 완료되었는지 확인)
			break;
		res++; // Increment the iteration counter (반복 카운터 증가)
		bfs(); // Perform BFS (BFS 수행)
	}

	cout << res; // Output the number of iterations (반복 횟수 출력)
}





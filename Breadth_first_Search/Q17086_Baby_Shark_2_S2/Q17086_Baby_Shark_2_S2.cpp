/*
commented by ChatGPT
This C++ code implements a Breadth-First Search (BFS) algorithm to calculate the number of steps required to spread a certain condition across a 2D grid.
It is typically used for problems like spreading infection or ripening of fruits where the condition spreads to adjacent cells.
이 C++ 코드는 2D 그리드 전체에 특정 상태를 전파하는 데 필요한 단계 수를 계산하기 위해 너비 우선 탐색(BFS) 알고리즘을 구현합니다.
이는 감염 확산이나 과일 익히기와 같이 조건이 인접 셀로 퍼지는 문제에 일반적으로 사용됩니다.
*/

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, M; // N and M are the dimensions of the grid (N과 M은 그리드의 차원입니다)
int graph[50][50]; // 2D array representing the grid (그리드를 나타내는 2D 배열)
queue<int> q; // Queue used for BFS (BFS에 사용되는 큐)
int ymove[] = { -1, 0, 0, 1, 0, 1, 0, 0 }; // Array to represent movement in y-axis (y축에서의 이동을 나타내는 배열)
int xmove[] = { -1, 1, 1, -2, 2, -2, 1, 1 }; // Array to represent movement in x-axis (x축에서의 이동을 나타내는 배열)

// Function to perform BFS on the grid
static int bfs() {

	int res = 0; // Variable to store the result (결과를 저장하는 변수)
	int ypos, xpos; // Variables to store current position (현재 위치를 저장하는 변수)
	while (!q.empty()) {
		int temp = q.front(); // Current position (현재 위치)
		q.pop();
		int yidx = temp / M; // Y-coordinate (y좌표)
		int xidx = temp % M; // X-coordinate (x좌표)
		ypos = yidx;
		xpos = xidx;
		for (int i = 0; i < 8; i++) { // Iterate through all possible movements (모든 가능한 이동을 반복)
			ypos += ymove[i];
			xpos += xmove[i];
			if (ypos < 0 || ypos >= N || xpos < 0 || xpos >= M) // Check for boundary conditions (경계 조건 확인)
				continue;
			else if (graph[ypos][xpos] != 0) // Skip if cell is already visited (이미 방문한 셀은 건너뛰기)
				continue;
			graph[ypos][xpos] = graph[yidx][xidx] + 1; // Update the cell value (셀 값 업데이트)
			res = max(res, graph[ypos][xpos]); // Update the result (결과 업데이트)
			q.push(ypos * M + xpos); // Add the new position to the queue (큐에 새 위치 추가)
		}
	}
	return res - 1; // Return result minus 1 since initial cells count as step 1 (초기 셀이 단계 1로 계산되므로 결과에서 1 빼기)
}

int main()
{
	cin >> N >> M; // Input for grid dimensions (그리드 차원 입력)
	// Reading the initial state of each cell in the grid (그리드의 각 셀의 초기 상태 읽기)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) // If cell is initially in the spreadable condition (셀이 초기에 전파 가능 상태인 경우)
				q.push(i * M + j); // Add to queue (큐에 추가)
		}
	}

	cout << bfs(); // Perform BFS and print result (BFS 수행 및 결과 출력)
}
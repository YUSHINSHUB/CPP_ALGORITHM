
/*
commented by ChatGPT
This C++ code is designed to identify and count the number of distinct regions on a 2D grid (board) not covered by specified rectangles.
It uses a Breadth-First Search (BFS) algorithm to explore each region.
The board is initially filled with zeros, and areas covered by rectangles are marked as 1.
The bfs function is called for every unvisited cell (marked as 0), incrementing a counter for each new cell added to the region.
Each region's size is stored in list. After exploring all cells, the program outputs the number of distinct regions and their respective sizes in ascending order.
이 C++ 코드는 2D 그리드(board) 상에서 지정된 직사각형에 의해 덮이지 않은 별개의 영역들의 수를 식별하고 계산하기 위해 설계되었습니다.
너비 우선 탐색(BFS) 알고리즘을 사용하여 각 영역을 탐색합니다.
board는 초기에 0으로 채워지며, 직사각형으로 덮인 영역들은 1로 표시됩니다.
bfs 함수는 방문하지 않은 각 셀(0으로 표시된)에 대해 호출되며, 새로운 셀이 영역에 추가될 때마다 카운터를 증가시킵니다.
각 영역의 크기는 list에 저장됩니다. 모든 셀을 탐색한 후, 프로그램은 별개의 영역들의 수와 각각의 크기를 오름차순으로 출력합니다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N, K; // M: Rows, N: Columns, K: Number of rectangles (M: 행 수, N: 열 수, K: 직사각형 수)
int board[100][100]; // 2D array representing the grid (그리드를 나타내는 2D 배열)
vector<int> list; // List to store the size of each region (각 영역의 크기를 저장하는 벡터)
int nexty[] = { 1, -1, 0, -1 }; // Y-axis movements for BFS (BFS를 위한 Y축 이동)
int nextx[] = { 0, -1, 2, -1 }; // X-axis movements for BFS (BFS를 위한 X축 이동)

// BFS function to explore and count each region (각 영역을 탐색하고 세는 BFS 함수)
void bfs(int y, int x) {
	int idx = 1; // Counter for the size of the region (영역 크기를 세는 카운터)
	queue<int> yq, xq; // Queues for Y-axis and X-axis positions (Y축 및 X축 위치를 위한 큐)
	yq.push(y);
	xq.push(x);
	board[y][x] = 1; // Mark the cell as visited (셀을 방문한 것으로 표시)

	while (!yq.empty()) {
		int cury = yq.front();
		int curx = xq.front();
		yq.pop();
		xq.pop();
		for (int i = 0; i < 4; i++) { // Explore adjacent cells (인접한 셀 탐색)
			cury += nexty[i];
			curx += nextx[i];
			if (cury >= M || curx >= N || cury < 0 || curx < 0) // Check boundary conditions (경계 조건 확인)
				continue;
			if (board[cury][curx] == 1) // Skip if already visited (이미 방문한 경우 건너뛰기)
				continue;
			board[cury][curx] = 1; // Mark the cell as visited (셀을 방문한 것으로 표시)
			idx++; // Increment the size of the region (영역 크기 증가)
			yq.push(cury); // Add new positions to the queues (큐에 새 위치 추가)
			xq.push(curx);
		}
	}

	list.push_back(idx); // Add the size of the region to the list (영역 크기를 리스트에 추가)
}

int main() {
	int dx, dy, ux, uy; // Variables for rectangle coordinates (직사각형 좌표를 위한 변수)
	int cnt = 0; // Counter for the number of regions (영역 수를 세는 카운터)


	cin >> M >> N >> K; // Read grid dimensions and number of rectangles (그리드 크기와 직사각형 수 읽기)
	for (int i = 0; i < M; i++) {
		fill(board[i], board[i] + N, 0); // Fill the grid with zeros (그리드를 0으로 채우기)
	}
	for (int i = 0; i < K; i++) { // Mark the given rectangles on the grid (그리드에 주어진 직사각형 표시)
		cin >> dx >> dy >> ux >> uy;
		ux--;
		uy--;
		for (int j = dy; j <= uy; j++) {
			for (int k = dx; k <= ux; k++)
				board[j][k] = 1;
		}
	}

	for (int i = 0; i < M; i++) { // Explore the grid for unvisited regions (방문하지 않은 영역 탐색)
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) { // If an unvisited region is found (방문하지 않은 영역 발견 시)
				cnt++; // Increment the region counter (영역 카운터 증가)
				bfs(i, j); // Perform BFS for the region (영역에 대해 BFS 수행)
			}
		}
	}

	sort(list.begin(), list.end()); // Sort the sizes of the regions (영역 크기 정렬)
	cout << cnt << "\n"; // Output the number of regions (영역 수 출력)
	for (int i = 0; i < list.size(); i++) // Output the sizes of the regions (영역 크기 출력)
		cout << list[i] << " ";
}

/*
commented by ChatGPT
This C++ code implements a Breadth-First Search (BFS) algorithm to find the shortest path for a knight to move from a starting position to a destination on a chessboard.
The chessboard is represented as a 2D array (board), with each cell initially set to -1, indicating unvisited.
The bfs function explores all possible moves of a knight from the current position, updating each cell with the number of moves taken to reach it.
When the destination is reached, the function returns the number of moves.
The program handles multiple test cases, reading the size of the board and the coordinates of the starting and destination points for each case.
이 C++ 코드는 체스판에서 시작 위치에서 목적지까지 나이트가 이동하는 최단 경로를 찾기 위해 너비 우선 탐색(BFS) 알고리즘을 구현합니다.
체스판은 2D 배열(board)로 표현되며, 각 셀은 초기에 -1로 설정되어 방문하지 않은 것을 나타냅니다.
bfs 함수는 현재 위치에서 나이트의 모든 가능한 이동을 탐색하며, 각 셀을 그 위치에 도달하는 데 필요한 이동 횟수로 업데이트합니다.
목적지에 도달하면 함수는 이동 횟수를 반환합니다.
프로그램은 여러 테스트 케이스를 처리하며, 각 케이스에 대해 체스판의 크기와 시작 및 목적지 좌표를 읽습니다.
*/

#include <iostream>
#include <queue>
using namespace std;

int l; // Size of the chessboard (체스판의 크기)
int board[300][300]; // 2D array representing the chessboard (체스판을 나타내는 2D 배열)
int nexty[] = { -2, 0, 1, 0, 2, 0, 1, 0 }; // Y-axis movements for a knight (나이트의 Y축 이동)
int nextx[] = { -1, 2, -3, 4, -4, 4, -3, 2 }; // X-axis movements for a knight (나이트의 X축 이동)

// BFS function to find the shortest path for a knight (나이트의 최단 경로를 찾기 위한 BFS 함수)
int bfs(int sy, int sx, int dy, int dx) {
	queue<int> yq; // Queue for Y-axis positions (Y축 위치를 위한 큐)
	queue<int> xq; // Queue for X-axis positions (X축 위치를 위한 큐)
	yq.push(sy);
	xq.push(sx);
	int cury, curx, y, x;

	while (!yq.empty()) {
		cury = yq.front();
		curx = xq.front();
		yq.pop();
		xq.pop();
		y = cury;
		x = curx;

		for (int i = 0; i < 8; i++) { // Explore all possible moves for a knight (나이트의 모든 가능한 이동 탐색)
			y += nexty[i];
			x += nextx[i];
			if (y < 0 || x < 0 || y >= l || x >= l) // Check boundary conditions (경계 조건 확인)
				continue;
			if (board[y][x] >= 0) // Skip if already visited (이미 방문한 경우 건너뛰기)
				continue;

			board[y][x] = board[cury][curx] + 1; // Mark the number of moves (이동 횟수 표시)
			if (y == dy && x == dx) // If destination is reached (목적지에 도달한 경우)
				break;
			yq.push(y); // Add new positions to the queues (큐에 새 위치 추가)
			xq.push(x);
		}
	}

	return board[dy][dx]; // Return the shortest path (최단 경로 반환)
}

int main() {
	int T, sy, sx, dy, dx; // T: Number of test cases, sy, sx: Start coordinates, dy, dx: Destination coordinates

	cin >> T; // Read the number of test cases (테스트 케이스 수 읽기)

	while (T > 0) {
		T--; // Decrement test case counter (테스트 케이스 카운터 감소)
		cin >> l; // Read the size of the chessboard (체스판의 크기 읽기)
		for (int i = 0; i < l; i++) {
			fill(board[i], board[i] + l, -1); // Fill the chessboard with -1 (체스판을 -1로 채우기)
		}
		cin >> sy >> sx >> dy >> dx; // Read start and destination coordinates (시작 및 목적지 좌표 읽기)
		board[sy][sx] = 0; // Mark the start position (시작 위치 표시)

		cout << bfs(sy, sx, dy, dx) << "\n"; // Output the shortest path (최단 경로 출력)
	}
}
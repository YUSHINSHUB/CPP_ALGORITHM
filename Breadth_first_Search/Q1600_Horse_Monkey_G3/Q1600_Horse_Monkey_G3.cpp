/*
commented by ChatGPT
This C++ program finds the minimum number of moves required to reach the bottom-right corner from the top-left corner of a grid using a combination of knight moves from chess and standard moves.
Given a grid where obstacles are marked, and the number of knight moves is limited (specified by K), the program utilizes a breadth-first search (BFS) algorithm.
It tracks the state of each cell in a 3D visited array, considering the number of knight moves used to reach that cell.
The algorithm explores all possible moves from each position, prioritizing knight moves until their limit is reached before resorting to standard moves.
If a cell is revisited with fewer knight moves used, it updates the minimum distance.
The solution ensures optimal paths are considered, and if the destination is reachable, returns the minimum number of moves required; otherwise, it returns -1.
이 C++ 프로그램은 체스의 나이트 움직임과 표준 이동의 조합을 사용하여 그리드의 좌상단에서 우하단까지 도달하는 데 필요한 최소 이동 횟수를 찾습니다.
장애물이 있는 그리드가 주어지고 나이트 이동의 수가 제한되어 있음(K로 지정됨), 프로그램은 너비 우선 탐색(BFS) 알고리즘을 사용합니다.
각 셀의 상태를 3차원 방문 배열에 추적하여 해당 셀에 도달하기 위해 사용된 나이트 이동의 수를 고려합니다.
알고리즘은 각 위치에서 가능한 모든 이동을 탐색하며, 나이트 이동의 한도에 도달할 때까지 이를 우선시한 다음 표준 이동으로 전환합니다.
셀이 나이트 이동을 더 적게 사용하여 재방문되면 최소 거리를 업데이트합니다. 솔루션은 최적의 경로를 보장하며, 목적지에 도달할 수 있으면 필요한 최소 이동 횟수를 반환하고, 그렇지 않으면 -1을 반환합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int K; // Maximum number of knight moves allowed
int W, H; // Width and Height of the grid
int grid[200][200]; // Grid with obstacles marked as 1
int visited[200][200][31]; // 3D array to track visited states [y][x][knight moves used]
int nky[] = { -2, -2, -1, -1, 1, 1, 2, 2 }; // Knight move y-offsets
int nkx[] = { -1, 1, -2, 2, -2, 2, -1, 1 }; // Knight move x-offsets
int ny[] = { -1, 0, 0, 1 }; // Standard move y-offsets
int nx[] = { 0, -1, 1, 0 }; // Standard move x-offsets

// Function to perform BFS and find the minimum number of moves
int bfs() {

	// Initialize visited array with high values
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			fill(visited[i][j], visited[i][j] + K + 1, 50000);
	}

	// Queues to hold y, x positions, and the count of knight moves used
	queue<int> yq, xq, cq;
	yq.push(0);
	xq.push(0);
	cq.push(0);
	visited[0][0][0] = 0; // Starting position with 0 knight moves used

	while (!yq.empty()) {
		int y = yq.front(), x = xq.front(), c = cq.front();
		yq.pop();
		xq.pop();
		cq.pop();

		// If the destination is reached, return the number of moves
		if (y == H - 1 && x == W - 1)
			return visited[y][x][c];

		// Try knight moves if under the limit
		if (c < K) {
			for (int i = 0; i < 8; i++) {
				int cy = y + nky[i], cx = x + nkx[i];
				// Check for valid position and if moving improves the current state
				if (cy >= 0 && cx >= 0 && cy < H && cx < W && grid[cy][cx] != 1 && visited[cy][cx][c + 1] > visited[y][x][c] + 1) {
					visited[cy][cx][c + 1] = visited[y][x][c] + 1;
					yq.push(cy);
					xq.push(cx);
					cq.push(c + 1);
				}
			}
		}

		// Try standard moves
		for (int i = 0; i < 4; i++) {
			int cy = y + ny[i], cx = x + nx[i];
			// Check for valid position and if moving improves the current state
			if (cy >= 0 && cx >= 0 && cy < H && cx < W && grid[cy][cx] != 1 && visited[cy][cx][c] > visited[y][x][c] + 1) {
				visited[cy][cx][c] = visited[y][x][c] + 1;
				yq.push(cy);
				xq.push(cx);
				cq.push(c);
			}
		}
	}

	return -1; // If the destination is unreachable
}

int main() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cin >> grid[i][j]; // Input grid with obstacles
	}

	cout << bfs(); // Output the minimum number of moves
}

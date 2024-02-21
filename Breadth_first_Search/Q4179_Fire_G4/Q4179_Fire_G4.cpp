/*
commented by ChatGPT
This C++ code simulates an escape scenario in a grid where a character ('J') tries to escape fires ('F') and obstacles ('#').
The grid is represented by a 2D array, and the character's movements are determined using a Breadth-First Search (BFS) algorithm.
The code efficiently tracks both the spread of fire and the possible escape routes for the character. If an escape is viable, it returns the minimum number of moves required; otherwise, it outputs "IMPOSSIBLE".
이 C++ 코드는 캐릭터('J')가 불('F')과 장애물('#')을 피해 격자에서 탈출하는 시나리오를 시뮬레이션합니다.
2D 배열로 표현된 격자에서 캐릭터의 움직임은 BFS(너비 우선 탐색) 알고리즘을 사용하여 결정됩니다.
코드는 불의 확산과 캐릭터의 가능한 탈출 경로를 효율적으로 추적합니다. 탈출이 가능한 경우, 필요한 최소 이동 횟수를 반환하며, 그렇지 않으면 "IMPOSSIBLE"을 출력합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

queue<int> jy; // Character's y-coordinate queue
queue<int> jx; // Character's x-coordinate queue
queue<int> fy; // Fire's y-coordinate queue
queue<int> fx; // Fire's x-coordinate queue
int ny[] = { 1, 0, 0, -1 }; // Directions for y-coordinate movement
int nx[] = { 0, -1, 1, 0 }; // Directions for x-coordinate movement
int R, C; // Rows and Columns of the grid
bool visited[1000][1000]; // Visited array to keep track of visited cells
int grid[1000][1000]; // Grid representation, where -1 indicates fire or obstacle

static int bfs() {
	while (!jy.empty()) {
		int s = jy.size(); // Size of the queue to process current layer of BFS
		for (int i = 0; i < s; i++) {
			int y = jy.front();
			int x = jx.front();
			jy.pop();
			jx.pop();
			if (grid[y][x] == -1) // Skip if the cell is on fire or an obstacle
				continue;

			for (int j = 0; j < 4; j++) { // Check all four directions
				int cy = y + ny[j];
				int cx = x + nx[j];
				if (cy >= R || cx >= C || cy < 0 || cx < 0) // If it's an escape point
					return grid[y][x] + 1;
				if (grid[cy][cx] == -1) // If the next cell is on fire or an obstacle
					continue;
				if (visited[cy][cx]) // If the next cell is already visited
					continue;
				jy.push(cy); // Add next cell to process
				jx.push(cx);
				grid[cy][cx] = grid[y][x] + 1; // Update the distance from the start
				visited[cy][cx] = true; // Mark the cell as visited
			}
		}

		s = fy.size(); // Process fire spreading in the same layer
		for (int i = 0; i < s; i++) {
			int y = fy.front();
			int x = fx.front();
			fy.pop();
			fx.pop();
			for (int j = 0; j < 4; j++) { // Spread fire in all four directions
				int cy = y + ny[j];
				int cx = x + nx[j];
				if (cy < 0 || cx < 0 || cy >= R || cx >= C) // Skip if outside the grid
					continue;
				if (grid[cy][cx] == -1) // Skip if the cell is already on fire or an obstacle
					continue;
				fy.push(cy); // Add next cell to spread fire
				fx.push(cx);
				grid[cy][cx] = -1; // Mark the cell as on fire
			}
		}
	}

	return -1; // Return -1 if escape is impossible
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		fill(visited[i], visited[i] + C, false); // Initialize visited array
		string in;
		cin >> in;
		for (int j = 0; j < C; j++) {
			grid[i][j] = 0; // Initialize grid
			if (in[j] == '#') // Mark obstacles
				grid[i][j] = -1;
			else if (in[j] == 'J') { // Mark character's starting position
				visited[i][j] = true;
				jy.push(i);
				jx.push(j);
			}
			else if (in[j] == 'F') { // Mark fire's starting position
				grid[i][j] = -1;
				fy.push(i);
				fx.push(j);
			}
		}
	}

	int res = bfs(); // Run BFS to find the shortest escape path
	if (res < 0)
		cout << "IMPOSSIBLE"; // Print "IMPOSSIBLE" if escape is not possible
	else
		cout << res; // Print the minimum number of moves required for escape
}

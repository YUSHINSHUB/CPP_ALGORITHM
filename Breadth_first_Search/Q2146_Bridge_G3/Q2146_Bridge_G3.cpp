/*
commented by ChatGPT
This C++ code is designed to solve the problem of finding the shortest bridge between islands in a grid.
It uses Breadth-First Search (BFS) to identify islands and determine the minimum length of a bridge needed to connect any two islands. The find_island() function marks each island with a unique number, starting from 2.
The bridge() function then calculates the shortest distance from a point on one island to any point on another island.
The main function reads the size of the grid (N) and the grid itself, where 1 represents land and 0 represents water.
Once the islands are identified, the code iterates through each cell of the grid, calling bridge() for cells that are part of an island, and updates the result with the shortest bridge length found.
The code ensures that the search does not revisit the same cell twice or cross the same island.

이 C++ 코드는 격자에서 섬 사이의 가장 짧은 다리를 찾는 문제를 해결하기 위해 설계되었습니다.
이 코드는 너비 우선 탐색(BFS)을 사용하여 섬을 식별하고 두 섬을 연결하는데 필요한 최소 다리 길이를 결정합니다. find_island() 함수는 각 섬에 2부터 시작하는 고유 번호를 부여합니다.
그 후, bridge() 함수는 한 섬의 한 점에서 다른 섬의 임의의 점까지의 최단 거리를 계산합니다. 메인 함수는 격자의 크기(N)와 격자 자체를 읽어들입니다. 여기서 1은 땅을, 0은 물을 나타냅니다.
섬들이 식별되면, 코드는 격자의 각 셀을 반복하며 섬의 일부인 셀에 대해 bridge()를 호출하고, 찾은 가장 짧은 다리 길이로 결과를 업데이트합니다.
이 코드는 동일한 셀을 두 번 방문하거나 같은 섬을 건너는 것을 방지합니다.
*/

#include <iostream>
#include <queue>
#include<climits>
#include <cmath>

using namespace std;

int ny[] = { -1, 0, 0, 1 }; // Directions for Y-axis movement (Y축 이동 방향)
int nx[] = { 0, -1, 1, 0 }; // Directions for X-axis movement (X축 이동 방향)
int grid[100][100]; // Grid representing the map (지도를 나타내는 격자)
bool visited[100][100]; // Array to keep track of visited cells (방문한 셀 추적)
int N; // Size of the grid (격자의 크기)
int res = 0; // Variable to store the result (결과를 저장하는 변수)

// Function to identify islands and mark them with unique numbers
void find_island() {

	queue<int> yq;
	queue<int> xq;
	int idx = 2; // Starting index for islands

	// Looping through the grid to find islands
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 1) { // Land found
				yq.push(i);
				xq.push(j);
				grid[i][j] = idx; // Mark the island with a unique number

				// BFS to mark the entire island
				while (!yq.empty()) {

					int cy = yq.front();
					int cx = xq.front();
					yq.pop();
					xq.pop();

					// Explore adjacent cells
					for (int k = 0; k < 4; k++) {
						int ynext = cy + ny[k];
						int xnext = cx + nx[k];
						if (ynext < 0 || xnext < 0 || ynext >= N || xnext >= N)
							continue;
						if (grid[ynext][xnext] == 0 || grid[ynext][xnext] == idx)
							continue;

						grid[ynext][xnext] = idx; // Mark adjacent cells as part of the island
						yq.push(ynext);
						xq.push(xnext);
					}

				}
				idx++; // Increment index for the next island
			}
		}
	}
}

// Function to calculate the shortest bridge length from an island
int bridge(int y, int x, int idx) {

	// Reset the visited array
	for (int i = 0; i < N; i++)
		fill(visited[i], visited[i] + N, false);

	queue<int> yq;
	queue<int> xq;
	queue<int> b; // Queue to store bridge length
	yq.push(y);
	xq.push(x);
	b.push(0);

	// BFS to find the shortest bridge
	while (!yq.empty()) {

		int cy = yq.front();
		int cx = xq.front();
		int cb = b.front(); // Current bridge length
		yq.pop();
		xq.pop();
		b.pop();

		// Check adjacent cells
		for (int i = 0; i < 4; i++) {
			int ynext = cy + ny[i];
			int xnext = cx + nx[i];
			if (ynext < 0 || xnext < 0 || ynext >= N || xnext >= N)
				continue;
			if (visited[ynext][xnext])
				continue;
			if (grid[ynext][xnext] == idx)
				continue;
			if (grid[ynext][xnext] > 0 && grid[ynext][xnext] != idx)
				return cb; // Reached another island

			yq.push(ynext);
			xq.push(xnext);
			b.push(cb + 1); // Increase bridge length
			visited[ynext][xnext] = true;
		}

	}

	return INT_MAX; // Return maximum value if no bridge is found
}

int main()
{
	int res = INT_MAX; // Initialize result to maximum value

	cin >> N; // Read the grid size

	// Read grid data
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> grid[i][j]; // Input each cell in the grid
	}

	find_island(); // Identify and mark islands

	// Find the shortest bridge for each island
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] > 1) { // Check if the cell is part of an island
				res = min(res, bridge(i, j, grid[i][j])); // Update result with the shortest bridge length
			}
		}
	}

	cout << res; // Output the result
}
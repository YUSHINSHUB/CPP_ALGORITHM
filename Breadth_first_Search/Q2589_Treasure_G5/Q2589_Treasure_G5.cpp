/*
	commented by ChatGPT
	Summary: This program finds the maximum distance from a starting point 'L' on a 2D grid, considering 'W' as obstacles, using BFS algorithm.
*/

#include <iostream>
#include <queue>
using namespace std;

// Define the maximum size for the map grid and BFS calculation grid
static char map[50][50];
static int calc[50][50];

// Define movement directions for BFS. ypos represents vertical movement and xpos represents horizontal movement.
static int ypos[] = { 1, 0, -1, 0 };
static int xpos[] = { 0, 1, 0, -1 };

static int n, m;  // Grid dimensions: n = rows, m = columns
static int res = 0;  // Result variable to hold the maximum distance from any 'L' on the grid

// BFS function to compute distance from a starting point in the grid
static void bfs(int y, int x) {

	// Initialize queues to store coordinates for BFS traversal
	queue<int> yq;
	queue<int> xq;
	yq.push(y);
	xq.push(x);

	// Process nodes in BFS order
	while (!yq.empty()) {

		int yt = yq.front();  // Current y-coordinate
		int xt = xq.front();  // Current x-coordinate
		yq.pop();
		xq.pop();

		// Loop through possible movement directions
		for (int i = 0; i < 4; i++) {
			int yp = yt + ypos[i];  // Calculate new y-coordinate
			int xp = xt + xpos[i];  // Calculate new x-coordinate

			// Check boundaries, obstacles, and previously visited nodes
			if (yp < 0 || yp >= n || xp < 0 || xp >= m) continue;
			else if (map[yp][xp] == 'W') continue;
			else if (calc[yp][xp] >= 0) continue;
			else {
				calc[yp][xp] = calc[yt][xt] + 1;  // Calculate BFS distance
				yq.push(yp);
				xq.push(xp);
				// Check and update the maximum distance found
				if (calc[yp][xp] > res) res = calc[yp][xp];
			}
		}
	}
}

int main() {
	// Input the grid dimensions
	cin >> n >> m;

	// Input the grid itself
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j];
		}
	}

	// Loop through each cell in the grid
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// If the cell is a starting point 'L', run BFS
			if (map[i][j] == 'L') {
				// Initialize BFS calculation grid
				for (int k = 0; k < n; k++) fill(calc[k], calc[k] + m, -1);
				calc[i][j] = 0;  // The starting point has distance 0
				bfs(i, j);  // Run BFS from the current point
			}
		}
	}

	// Output the maximum distance found
	cout << res;
}

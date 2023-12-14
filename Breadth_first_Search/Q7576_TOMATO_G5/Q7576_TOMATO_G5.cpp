// commented by ChatGPT
// Summary: A C++ program that simulates the spreading process in a 2D grid using BFS.
// The result indicates the days required for complete spread or -1 if not all cells are reached.

#include <iostream>
#include <queue>
using namespace std;

// The main grid where the spread is simulated. Fixed size for faster access.
int tom[1002][1002];

// Variable to keep track of the number of days for complete spread.
int res = 0;

// Queues to keep track of the y and x coordinates for BFS traversal.
queue<int> y;
queue<int> x;

// Possible movement directions in the y and x axis.
int yp[] = { 1, -1, -1, 1 };
int xp[] = { 0, 1, -1, -1 };

// Dimensions of the grid.
int n, m;

// Function to perform Breadth-First Search on the grid.
void bfs() {
	while (!y.empty()) {
		int s = y.size();

		for (int j = 0; j < s; j++) {
			int ypos = y.front();
			int xpos = x.front();
			y.pop();
			x.pop();

			// Attempt to spread in all 4 directions.
			for (int i = 0; i < 4; i++) {
				ypos += yp[i];
				xpos += xp[i];

				// Check boundaries and if the cell can be affected.
				if (ypos == 0 || ypos == m + 1 || xpos == 0 || xpos == n + 1)
					continue;
				else if (tom[ypos][xpos] == -1 || tom[ypos][xpos] == 1)
					continue;
				else {
					tom[ypos][xpos] = 1;
					y.push(ypos);
					x.push(xpos);
				}
			}
		}
		// Increment day count after each BFS level.
		res++;
	}
	// Decrement as the final BFS level doesn't contribute to days.
	res--;
}

int main() {
	// Reading the dimensions of the grid.
	cin >> n >> m;

	// Populating the grid and initializing the BFS start points.
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tom[i][j];
			if (tom[i][j] == 1) {
				y.push(i);
				x.push(j);
			}
		}
	}

	// Execute BFS
	bfs();

	// Check if there are unspread cells left.
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (tom[i][j] == 0)
				res = -1; // Indicates incomplete spread.
		}
	}

	// Display the result.
	cout << res;
}
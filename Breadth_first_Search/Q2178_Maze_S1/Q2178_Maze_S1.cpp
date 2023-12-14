#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

static int maze[102][102];
static int bfs[102][102];

static void recur(int n, int m) {

	// Checks the validity of the cell above and updates the distance if needed.
	if (maze[n - 1][m] == 1 && bfs[n - 1][m] > bfs[n][m] + 1) {
		bfs[n - 1][m] = bfs[n][m] + 1;
		recur(n - 1, m);
	}

	// Checks the validity of the cell to the right and updates the distance if
	// needed.
	if (maze[n][m + 1] == 1 && bfs[n][m + 1] > bfs[n][m] + 1) {
		bfs[n][m + 1] = bfs[n][m] + 1;
		recur(n, m + 1);
	}

	// Checks the validity of the cell below and updates the distance if needed.
	if (maze[n + 1][m] == 1 && bfs[n + 1][m] > bfs[n][m] + 1) {
		bfs[n + 1][m] = bfs[n][m] + 1;
		recur(n + 1, m);
	}

	// Checks the validity of the cell to the left and updates the distance if
	// needed.
	if (maze[n][m - 1] == 1 && bfs[n][m - 1] > bfs[n][m] + 1) {
		bfs[n][m - 1] = bfs[n][m] + 1;
		recur(n, m - 1);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	string in;

	// Initializing the BFS distances to a large number.
	fill(bfs[0], bfs[0] + 102, INT_MAX);
	fill(bfs[n + 1], bfs[n + 1] + 102, INT_MAX);

	cin.ignore();

	for (int i = 1; i <= n; i++) {
		fill(bfs[i], bfs[i] + 102, INT_MAX);
		getline(cin, in);
		for (int j = 1; j <= m; j++) {
			maze[i][j] = in[j - 1] - '0';
		}
	}

	// The BFS distance from the first cell to itself is 1.
	bfs[1][1] = 1;

	// Starting the BFS from the first cell.
	recur(1, 1);

	// Writing the shortest distance to the last cell.
	cout << bfs[n][m];

}

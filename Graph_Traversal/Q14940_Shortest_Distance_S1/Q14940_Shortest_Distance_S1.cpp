//Commented by ChatGPT
//Summary: This program calculates the shortest path from a specified point to each cell in a grid using BFS. 
//If a cell is not reachable, it outputs -1.

#include <iostream>
#include <queue>
using namespace std;

// Declare arrays to hold input grid, result, and visited status
int grp[1000][1000]; // Input grid with cell values
int res[1000][1000]; // Array to store the shortest path to each cell
int nexty[] = { 1, 0, -1, 0 }; // Array to indicate vertical direction for BFS (down, none, up, none)
int nextx[] = { 0, 1, 0, -1 }; // Array to indicate horizontal direction for BFS (none, right, none, left)
bool visited[1000][1000]; // Array to track whether each cell has been visited or not
int n, m; // Dimensions of the input grid (rows and columns)

// BFS function to calculate the shortest path from a specified cell to all
	// other cells in the grid
void bfs(int i, int j) {
	// Declare queues to hold the coordinates of cells to be visited
	queue<int> yq; // Queue for y-coordinates (vertical)
	queue<int> xq; // Queue for x-coordinates (horizontal)

	// Add the initial cell coordinates to the queues and mark it as visited
	yq.push(i);
	xq.push(j);
	visited[i][j] = true;

	// BFS algorithm to explore the cells
	while (!yq.empty()) {
		// Get the current cell coordinates from the queues
		int cy = yq.front(); // Current y-coordinate
		int cx = xq.front(); // Current x-coordinate
		yq.pop();
		xq.pop();

		// Loop through the four possible directions from the current cell
		for (int k = 0; k < 4; k++) {
			int ny = cy + nexty[k]; // Calculate next y-coordinate
			int nx = cx + nextx[k]; // Calculate next x-coordinate

			// Check for out-of-bound coordinates, already visited cells, or cells marked as
			// inaccessible (res = 0)
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			else if (visited[ny][nx])
				continue;
			else if (res[ny][nx] == 0)
				continue;

			// Mark the next cell as visited and update the shortest path in the result
			// array
			visited[ny][nx] = true;
			res[ny][nx] = res[cy][cx] + 1; // Increment path length

			// Add the next cell coordinates to the queues for further exploration
			yq.push(ny);
			xq.push(nx);
		}
	}
}

int main()
{
	// Read the dimensions of the grid from the input
	cin >> n >> m;
	int x = 0, y = 0;

	// Initialize the result array with a large value and visited status as false
	for (int i = 0; i < n; i++) {
		fill(res[i], res[i] + m, 10000000);
		fill(visited[i], visited[i] + m, false);
	}

	// Read the input grid and identify the starting point (cell with value 2)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			grp[i][j] = t;
			if (t == 0 || t == 2) {
				if (t == 2) {
					y = i; // Starting point y-coordinate
					x = j; // Starting point x-coordinate
				}
				res[i][j] = 0; // Mark starting and inaccessible cells as 0 in result array
			}
		}
	}

	// Call the BFS function with the starting point coordinates
	bfs(y, x);

	// Write the result array to the output, replacing unreachable cells with -1
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (res[i][j] == 10000000)
				cout << "-1 ";
			else
				cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

//Commented by ChatGPT
//This program determines the number of 'P' cells reachable from the cell with 'I' character in a grid using BFS traversal.

#include <iostream>
#include <queue>
using namespace std;

// Define global variables
static string grp[600]; // Grid represented as an array of strings
static bool visited[600][600]; // 2D boolean array to keep track of visited cells in the grid
static int trax[] = { 1, 0, -1, 0 }; // Array representing possible moves in x-direction during BFS traversal
static int tray[] = { 0, 1, 0, -1 }; // Array representing possible moves in y-direction during BFS traversal
static int n, m; // Integers representing the dimensions of the grid
static int res = 0; // Integer representing the number of reachable 'P' cells


// BFS traversal function starting from cell with coordinates (y, x)
static void bfs(int y, int x) {

	// Mark the starting cell as visited
	visited[y][x] = true;

	// Declare queues to store coordinates of cells in BFS traversal
	queue<int> px;
	queue<int> py;

	// Add the starting cell coordinates to the queues
	px.push(x);
	py.push(y);

	// Continue BFS traversal while there are cells in the queue
	while (!px.empty()) {

		// Get the coordinates of the current cell
		int curx = px.front();
		int cury = py.front();
		px.pop();
		py.pop();

		// Iterate through possible moves from the current cell
		for (int i = 0; i < 4; i++) {
			int xnext = curx + trax[i];
			int ynext = cury + tray[i];

			// Check for valid next cell coordinates
			if (xnext < 0 || ynext < 0 || xnext >= m || ynext >= n)
				continue;
			// Check if the next cell is an 'X' cell
			if (grp[ynext][xnext] == 'X')
				continue;
			// Check if the next cell has already been visited
			if (visited[ynext][xnext] == true)
				continue;

			// Mark the next cell as visited
			visited[ynext][xnext] = true;

			// Increment the count of reachable 'P' cells
			if (grp[ynext][xnext] == 'P')
				res++;

			// Add the next cell coordinates to the queues
			px.push(xnext);
			py.push(ynext);

		}
	}

}

int main()
{
	// Read the dimensions of the grid from the input
	cin >> n >> m;
	int y = 0, x = 0;

	// Read the input grid and find the coordinates of the cell with 'I' character
	for (int i = 0; i < n; i++) {
		cin >> grp[i];
		fill(visited[i], visited[i] + m, false);
		for (int j = 0; j < m; j++) {
			if (grp[i][j] == 'I') {
				y = i;
				x = j;
			}
		}
	}

	// Call the BFS traversal function with the coordinates of the cell with 'I'
	// character
	bfs(y, x);

	// Write the result to the output
	if (res == 0)
		cout << "TT";
	else
		cout << res;
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

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
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

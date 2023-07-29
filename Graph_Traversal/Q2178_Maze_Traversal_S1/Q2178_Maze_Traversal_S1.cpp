//Commented by ChatGPT
//This program is for a recursive breadth-first search (BFS) in a 2D maze. 

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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

/*
Commented by ChatGPT
The program performs a breadth-first search (BFS) to count the maximum number of clusters in a 2D grid.
*/

#include <iostream>
#include <math.h>
using namespace std;

static int area[102][102];
static int bfs[102][102];

void recur(int x, int y, int idx) {

	bfs[x][y] = 1; // Mark the current grid cell as visited

	// Checks the surrounding cells and performs recursive calls if they meet the
	// condition
	if (area[x + 1][y] >= idx && bfs[x + 1][y] == 0)
		recur(x + 1, y, idx);
	if (area[x][y + 1] >= idx && bfs[x][y + 1] == 0)
		recur(x, y + 1, idx);
	if (area[x - 1][y] >= idx && bfs[x - 1][y] == 0)
		recur(x - 1, y, idx);
	if (area[x][y - 1] >= idx && bfs[x][y - 1] == 0)
		recur(x, y - 1, idx);

	return;

}

int main()
{
	int n;
	cin >> n;// Read the size of the grid
	int res = 0; // Variable to store the maximum number of clusters found
	int cur = 0; // Variable to track the current count of clusters


	// Read and populate the grid
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> area[i][j];
		}
	}

	// For each possible value, perform the cluster counting
	for (int i = 1; i <= 100; i++) {

		cur = 0; // Reset the current count

		// Reset the BFS grid for the current iteration
		for (int j = 1; j <= n; j++) {
			fill(bfs[j], bfs[j] + 1 + n, 0);
		}

		// For each grid cell, check if it meets the condition and initiate the
		// recursion
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (area[j][k] >= i && bfs[j][k] == 0) {
					cur++; // Increase the count of clusters
					recur(j, k, i); // Initiate the recursive BFS
				}
			}
		}

		// If no clusters were found, break the loop
		if (cur == 0)
			break;
		else
			res = max(res, cur); // Update the maximum count of clusters
	}

	cout << res; // Write the maximum count of clusters to the output
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

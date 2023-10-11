/*
commented by ChatGPT
이 C++ 코드는 2D 배열로 표현된 빙산이 주어질 때, 빙산이 몇 년 만에 분리되는지를 계산합니다.
This C++ code calculates the number of years it takes for a given iceberg, represented in a 2D array, to break apart.

키워드: 빙산 (Keywords: Iceberg)
*/

#include <iostream>
#include <queue>

using namespace std;

int idx = 0;  // 빙산이 분리되기까지의 시간을 계산하기 위한 변수 (Variable to calculate the time taken for the iceberg to break apart)
int n, m;
int sea[301][301];  // 빙산의 현재 상태를 저장하는 2D 배열 (2D array to store the current state of the iceberg)
int by[] = { 1, -1, -1, 1 };
int bx[] = { 0, 1, -1, -1 };
bool visited[301][301];  // 해당 위치를 방문했는지 체크하기 위한 변수 (Variable to check if the given position was visited)

// DFS를 사용하여 빙산의 덩어리를 찾는 함수 (Function to find the chunks of the iceberg using DFS)
void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		y += by[i];
		x += bx[i];
		if (y < 0 || x < 0 || y >= n || x >= m)
			continue;
		if (sea[y][x] > 0 && !visited[y][x])
			dfs(y, x);
	}
}

// 현재 빙산이 몇 개의 덩어리로 이루어져있는지 확인하는 함수 (Function to check how many chunks the iceberg is currently made of)
int check() {

	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + m, false);
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sea[i][j] > 0 && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	return cnt;
}

// BFS를 사용하여 빙산 주변의 바다에 의해 빙산이 얼마나 녹는지 계산하는 함수 (Function to calculate how much the iceberg melts due to the sea around it using BFS)
void bfs() {

	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + m, false);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sea[i][j] == 0 && !visited[i][j]) {
				int y = i;
				int x = j;
				for (int k = 0; k < 4; k++) {
					y += by[k];
					x += bx[k];
					if (y < 0 || x < 0 || y >= n || x >= m)
						continue;
					else if (sea[y][x] > 0) {
						sea[y][x]--;
						visited[y][x] = true;
					}
				}
			}
		}
	}
}

int main()
{
	// 사용자로부터 빙산의 크기와 상태를 입력받습니다.
	// Reads the size and state of the iceberg from the user.
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> sea[i][j];
		}
	}

	// 빙산이 분리될 때까지 빙산의 상태를 업데이트하며 시간을 계산합니다.
	// Updates the state of the iceberg and calculates the time until the iceberg breaks apart.
	while (true) {

		int chk = check();

		if (chk == 0) {
			idx = 0;
			break;
		}
		else if (chk >= 2)
			break;

		idx++;
		bfs();
	}

	cout << idx;
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

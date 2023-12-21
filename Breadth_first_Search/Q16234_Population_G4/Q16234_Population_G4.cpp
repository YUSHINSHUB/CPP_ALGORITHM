// Q16234_Population_G4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int ny[] = { -1, 1, 0, 1 };
int nx[] = { 0, -1, 2, -1 };
int N, L, R;
int grid[50][50];
bool visited[50][50];

static void bfs(int y, int x) {

	int sum = grid[y][x];
	int size = 1;
	queue<int> ay;
	queue<int> ax;
	queue<int> yq;
	queue<int> xq;
	yq.push(y);
	xq.push(x);
	ay.push(y);
	ax.push(x);

	while (!yq.empty()) {

		int cy = yq.front();
		int cx = xq.front();
		yq.pop();
		xq.pop();
		int ly = cy;
		int lx = cx;

		for (int i = 0; i < 4; i++) {
			ly += ny[i];
			lx += nx[i];
			if (ly >= N || lx >= N || ly < 0 || lx < 0)
				continue;
			else if (visited[ly][lx])
				continue;
			else if ((int)abs(grid[ly][lx] - grid[cy][cx]) >= L
				&& (int)abs(grid[ly][lx] - grid[cy][cx]) <= R) {
				visited[ly][lx] = true;
				yq.push(ly);
				xq.push(lx);
				ay.push(ly);
				ax.push(lx);
				sum += grid[ly][lx];
				size++;
			}
		}

	}

	sum /= size;

	while (!ay.empty()) {
		int ly = ay.front();
		int lx = ax.front();
		ay.pop();
		ax.pop();
		grid[ly][lx] = sum;
	}

}

static int search() {

	int res = 0;
	int y, x;

	while (true) {

		for (int i = 0; i < N; i++)
			fill(visited[i], visited[i] + N, false);

		bool pass = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j])
					continue;
				y = i;
				x = j;
				for (int k = 0; k < 4; k++) {
					y += ny[k];
					x += nx[k];
					if (y >= N || x >= N || y < 0 || x < 0)
						continue;
					else if (visited[y][x])
						continue;
					if ((int)abs(grid[i][j] - grid[y][x]) >= L
						&& (int)abs(grid[i][j] - grid[y][x]) <= R) {
						pass = true;
						visited[i][j] = true;
						bfs(i, j);
						break;
					}
				}
			}
		}

		if (!pass)
			break;
		else
			res++;
	}

	return res;

}


int main()
{
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	cout << search();
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

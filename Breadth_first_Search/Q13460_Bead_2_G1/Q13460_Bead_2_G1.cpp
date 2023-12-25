// Q13460_Bead_2_G1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

static char grid[10][10];
static int mem[10][10][10][10];
static bool pass = true;

int bfs(int fby, int fbx, int fry, int frx) {

	queue<int> byq;
	queue<int> bxq;
	queue<int> ryq;
	queue<int> rxq;
	byq.push(fby);
	bxq.push(fbx);
	ryq.push(fry);
	rxq.push(frx);

	while (!byq.empty()) {
		int cby = byq.front();
		int cbx = bxq.front();
		int cry = ryq.front();
		int crx = rxq.front();
		byq.pop();
		bxq.pop();
		ryq.pop();
		rxq.pop();
		if (mem[cry][crx][cby][cbx] >= 10)
			break;

		int by = cby;
		int bx = cbx;
		int ry = cry;
		int rx = crx;

		while (true) {
			if (grid[by + 1][bx] == '#' && grid[ry + 1][rx] == '#')
				break;
			else if (grid[by + 1][bx] == '#' && by == ry + 1 && bx == rx)
				break;
			else if (grid[ry + 1][rx] == '#' && ry == by + 1 && bx == rx)
				break;
			else if (grid[by + 1][bx] == '#')
				ry++;
			else if (grid[ry + 1][rx] == '#')
				by++;
			else {
				ry++;
				by++;
			}

			if (grid[by][bx] == 'O' || grid[ry][rx] == 'O')
				break;
		}

		if (grid[by][bx] != 'O' && (by != cby || bx != cbx || ry != cry || rx != crx)
			&& (mem[ry][rx][by][bx] < 0)) {

			if (grid[ry][rx] == 'O') {
				if (by < ry && bx == rx) {
					while (grid[by][bx] != '#') {
						by++;
						if (grid[by][bx] == 'O') {
							pass = false;
							break;
						}
					}
				}
				if (pass)
					return mem[cry][crx][cby][cbx] + 1;
				else
					pass = true;
			}
			else {
				mem[ry][rx][by][bx] = mem[cry][crx][cby][cbx] + 1;
				ryq.push(ry);
				rxq.push(rx);
				byq.push(by);
				bxq.push(bx);
			}
		}

		by = cby;
		bx = cbx;
		ry = cry;
		rx = crx;
		while (true) {
			if (grid[by - 1][bx] == '#' && grid[ry - 1][rx] == '#')
				break;
			else if (grid[by - 1][bx] == '#' && by == ry - 1 && bx == rx)
				break;
			else if (grid[ry - 1][rx] == '#' && ry == by - 1 && bx == rx)
				break;
			else if (grid[by - 1][bx] == '#')
				ry--;
			else if (grid[ry - 1][rx] == '#')
				by--;
			else {
				ry--;
				by--;
			}

			if (grid[by][bx] == 'O' || grid[ry][rx] == 'O')
				break;
		}

		if (grid[by][bx] != 'O' && (by != cby || bx != cbx || ry != cry || rx != crx)
			&& (mem[ry][rx][by][bx] < 0)) {
			if (grid[ry][rx] == 'O') {
				if (by > ry && bx == rx) {
					while (grid[by][bx] != '#') {
						by--;
						if (grid[by][bx] == 'O') {
							pass = false;
							break;
						}
					}
				}
				if (pass)
					return mem[cry][crx][cby][cbx] + 1;
				else
					pass = true;
			}
			else {
				mem[ry][rx][by][bx] = mem[cry][crx][cby][cbx] + 1;
				ryq.push(ry);
				rxq.push(rx);
				byq.push(by);
				bxq.push(bx);
			}
		}

		by = cby;
		bx = cbx;
		ry = cry;
		rx = crx;
		while (true) {
			if (grid[by][bx + 1] == '#' && grid[ry][rx + 1] == '#')
				break;
			else if (grid[by][bx + 1] == '#' && bx == rx + 1 && by == ry)
				break;
			else if (grid[ry][rx + 1] == '#' && rx == bx + 1 && by == ry)
				break;
			else if (grid[by][bx + 1] == '#')
				rx++;
			else if (grid[ry][rx + 1] == '#')
				bx++;
			else {
				rx++;
				bx++;
			}

			if (grid[by][bx] == 'O' || grid[ry][rx] == 'O')
				break;
		}

		if (grid[by][bx] != 'O' && (by != cby || bx != cbx || ry != cry || rx != crx)
			&& (mem[ry][rx][by][bx] < 0)) {

			if (grid[ry][rx] == 'O') {
				if (bx < rx && by == ry) {
					while (grid[by][bx] != '#') {
						bx++;
						if (grid[by][bx] == 'O') {
							pass = false;
							break;
						}
					}
				}
				if (pass)
					return mem[cry][crx][cby][cbx] + 1;
				else
					pass = true;
			}
			else {
				mem[ry][rx][by][bx] = mem[cry][crx][cby][cbx] + 1;
				ryq.push(ry);
				rxq.push(rx);
				byq.push(by);
				bxq.push(bx);
			}
		}

		by = cby;
		bx = cbx;
		ry = cry;
		rx = crx;
		while (true) {
			if (grid[by][bx - 1] == '#' && grid[ry][rx - 1] == '#')
				break;
			else if (grid[by][bx - 1] == '#' && bx == rx - 1 && by == ry)
				break;
			else if (grid[ry][rx - 1] == '#' && rx == bx - 1 && by == ry)
				break;
			else if (grid[by][bx - 1] == '#')
				rx--;
			else if (grid[ry][rx - 1] == '#')
				bx--;
			else {
				rx--;
				bx--;
			}

			if (grid[by][bx] == 'O' || grid[ry][rx] == 'O')
				break;
		}

		if (grid[by][bx] != 'O' && (by != cby || bx != cbx || ry != cry || rx != crx)
			&& (mem[ry][rx][by][bx] < 0)) {

			if (grid[ry][rx] == 'O') {
				if (bx > rx && by == ry) {
					while (grid[by][bx] != '#') {
						bx--;
						if (grid[by][bx] == 'O') {
							pass = false;
							break;
						}
					}
				}
				if (pass)
					return mem[cry][crx][cby][cbx] + 1;
				else
					pass = true;
			}
			else {
				mem[ry][rx][by][bx] = mem[cry][crx][cby][cbx] + 1;
				ryq.push(ry);
				rxq.push(rx);
				byq.push(by);
				bxq.push(bx);
			}
		}

	}

	return -1;
}


int main()
{
	int N, M;
	int by = 0;
	int bx = 0;
	int ry = 0;
	int rx = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string in;
		cin >> in;
		for (int j = 0; j < M; j++) {
			grid[i][j] = in[j];
			if (grid[i][j] == 'R') {
				ry = i;
				rx = j;
			}
			if (grid[i][j] == 'B') {
				by = i;
				bx = j;
			}
			for (int k = 0; k < N; k++)
				fill(mem[i][j][k], mem[i][j][k] + M, -1);
		}
	}

	mem[ry][rx][by][bx] = 0;

	cout << bfs(by, bx, ry, rx);
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

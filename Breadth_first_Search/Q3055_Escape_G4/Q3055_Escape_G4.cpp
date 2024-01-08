// Q3055_Escape_G4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int R, C;
char grid[50][50];
int mem[50][50];
queue<int> wyq;
queue<int> wxq;
queue<int> hyq;
queue<int> hxq;
int ny[] = { 1, -1, 0, -1 };
int nx[] = { 0, -1, 2, -1 };

void bfs() {

	while (!hyq.empty()) {
		int s = wyq.size();
		for (int tc = 0; tc < s; tc++) {
			int y = wyq.front();
			int x = wxq.front();
			wyq.pop();
			wxq.pop();
			for (int i = 0; i < 4; i++) {
				y += ny[i];
				x += nx[i];
				if (y < 0 || x < 0 || y >= R || x >= C)
					continue;
				else if (grid[y][x] == '*' || grid[y][x] == 'X' || grid[y][x] == 'D')
					continue;
				grid[y][x] = '*';
				wyq.push(y);
				wxq.push(x);
			}
		}

		s = hyq.size();
		for (int tc = 0; tc < s; tc++) {
			int cury = hyq.front();
			int curx = hxq.front();
			hyq.pop();
			hxq.pop();
			int y = cury;
			int x = curx;
			for (int i = 0; i < 4; i++) {
				y += ny[i];
				x += nx[i];
				if (y < 0 || x < 0 || y >= R || x >= C)
					continue;
				else if (grid[y][x] == '*' || grid[y][x] == 'X')
					continue;
				else if (mem[y][x] >= 0)
					continue;
				mem[y][x] = mem[cury][curx] + 1;
				hyq.push(y);
				hxq.push(x);
			}
		}

	}

}



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int y = 0, x = 0;
	string in;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		fill(mem[i], mem[i] + C, -1);
		cin >> in;
		for (int j = 0; j < C; j++) {
			grid[i][j] = in[j];
			if (grid[i][j] == '*') {
				wyq.push(i);
				wxq.push(j);
			}
			else if (grid[i][j] == 'S') {
				hyq.push(i);
				hxq.push(j);
				mem[i][j] = 0;
			}
			else if (grid[i][j] == 'D') {
				y = i;
				x = j;
			}
		}
	}

	bfs();
	if (mem[y][x] < 0)
		cout << "KAKTUS";
	else
		cout << mem[y][x];
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

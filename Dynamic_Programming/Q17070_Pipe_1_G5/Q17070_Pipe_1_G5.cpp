// Q17070_Pipe_1_G5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

static int mem[16][16][3];
static int grid[16][16];
static int N;

static int dp(int y, int x, int cur) {

	if (y < 0 || x < 0 || y >= N || x >= N)
		return 0;

	if (mem[y][x][cur] >= 0) {
		return mem[y][x][cur];
	}

	if (cur == 0) {
		mem[y][x][0] = dp(y, x - 1, 0) + dp(y, x - 1, 2);
		return mem[y][x][0];
	}
	else if (cur == 1) {
		mem[y][x][1] = dp(y - 1, x, 1) + dp(y - 1, x, 2);
		return mem[y][x][1];
	}
	else {
		mem[y][x][2] = dp(y - 1, x - 1, 0) + dp(y - 1, x - 1, 1) + dp(y - 1, x - 1, 2);
		return mem[y][x][2];
	}

}

int main()
{
	int res;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fill(mem[i][j], mem[i][j] + 3, -1);
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 1) {
				fill(mem[i][j], mem[i][j] + 3, 0);
				if (j + 1 < N) {
					mem[i][j + 1][0] = 0;
					mem[i][j + 1][2] = 0;
				}
				if (i + 1 < N) {
					mem[i + 1][j][1] = 0;
					mem[i + 1][j][2] = 0;
				}
				if (i + 1 < N && j + 1 < N)
					mem[i + 1][j + 1][2] = 0;
			}
		}
	}

	mem[0][1][0] = 1;

	res = dp(N - 1, N - 1, 0) + dp(N - 1, N - 1, 1) + dp(N - 1, N - 1, 2);
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

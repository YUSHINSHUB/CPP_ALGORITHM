/*
commented by ChatGPT
This C++ code simulates a color blindness check. It reads an `n x n` matrix of RGB colors and determines the number of color regions for both normal and color blind people. In the case of color blindness, 'R' (red) and 'G' (green) are considered as indistinguishable.

이 C++ 코드는 색맹 검사를 시뮬레이션합니다. RGB 색상의 `n x n` 행렬을 읽어들여 일반인과 색맹인 모두에 대한 색상 영역의 수를 결정합니다. 색맹의 경우 'R'(빨강)과 'G'(녹색)은 구별할 수 없다고 간주됩니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int n;
char rgb[101][101];
int nres = 0;
int yres = 0;
queue<int> yq;
queue<int> xq;
int ypos[] = { 1, -1, -1, 1, };  // 방향성을 가진 y 좌표 (Directional y coordinates)
int xpos[] = { 0, 1, -1, -1, };  // 방향성을 가진 x 좌표 (Directional x coordinates)

// BFS 방식으로 같은 색상 영역을 찾는 함수 (Function to find the same color region using BFS method)
void bfs() {

	// yrgb 행렬은 색맹을 시뮬레이션하기 위한 행렬입니다. (yrgb matrix is for simulating color blindness)
	char yrgb[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			yrgb[i][j] = rgb[i][j];
	}

	// 일반 사람들에 대한 같은 색상 영역 찾기 (Finding the same color region for normal people)
	while (true) {

		char chk = ' ';  // 현재 확인중인 색상 (Current color being checked)

		// 방문하지 않은 색상 영역 찾기 (Find unvisited color region)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (rgb[i][j] != 'C') {
					chk = rgb[i][j];
					rgb[i][j] = 'C';
					yq.push(i);
					xq.push(j);
					break;
				}
			}
			if (chk != ' ')
				break;
		}

		// 모든 색상 영역을 확인했으면 종료 (Exit if all color regions are checked)
		if (chk == ' ')
			break;

		nres++;  // 영역 수 증가 (Increase the region count)

		// 현재 색상 영역에 대해 BFS 수행 (Perform BFS for the current color region)
		while (!yq.empty()) {

			int y = yq.front();
			yq.pop();
			int x = xq.front();
			xq.pop();

			// 모든 방향에 대해 확인 (Check for all directions)
			for (int i = 0; i < 4; i++) {
				y += ypos[i];
				x += xpos[i];

				if (y < 0 || y >= n || x < 0 || x >= n)
					continue;

				if (rgb[y][x] == chk) {
					yq.push(y);
					xq.push(x);
					rgb[y][x] = 'C';
				}
			}
		}
	}

	// 색맹 사람들에 대한 같은 색상 영역 찾기 (Finding the same color region for color blind people)
	while (true) {

		char chk = ' ';  // 현재 확인중인 색상 (Current color being checked)

		// 방문하지 않은 색상 영역 찾기 (Find unvisited color region)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (yrgb[i][j] != 'C') {
					chk = yrgb[i][j];
					yrgb[i][j] = 'C';
					yq.push(i);
					xq.push(j);
					break;
				}
			}
			if (chk != ' ')
				break;
		}

		// 모든 색상 영역을 확인했으면 종료 (Exit if all color regions are checked)
		if (chk == ' ')
			break;

		yres++;  // 영역 수 증가 (Increase the region count)

		// 현재 색상 영역에 대해 BFS 수행 (Perform BFS for the current color region)
		while (!yq.empty()) {

			int y = yq.front();
			yq.pop();
			int x = xq.front();
			xq.pop();

			// 모든 방향에 대해 확인 (Check for all directions)
			for (int i = 0; i < 4; i++) {
				y += ypos[i];
				x += xpos[i];

				if (y < 0 || y >= n || x < 0 || x >= n)
					continue;

				if (yrgb[y][x] == chk || (yrgb[y][x] == 'R' && chk == 'G') || (yrgb[y][x] == 'G' && chk == 'R')) {
					yq.push(y);
					xq.push(x);
					yrgb[y][x] = 'C';
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	string temp;

	// 사용자로부터 n x n 행렬 입력 받기 (Receive the n x n matrix input from the user)
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < n; j++) {
			rgb[i][j] = temp[j];
		}
	}

	// BFS 방식으로 색상 영역 찾기 (Find color regions using BFS method)
	bfs();

	// 결과 출력 (Output the results)
	cout << nres << " " << yres;
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


/*
commented by ChatGPT
This C++ code finds the maximum distance a person can move on a grid without revisiting a cell or encountering a previously visited alphabet.
The grid is filled with alphabets, and the person can move in four directions: up, down, left, or right.
The solution uses backtracking to traverse the grid and checks for revisited cells or alphabets.
이 C++ 코드는 그리드에서 이전에 방문한 셀이나 알파벳을 다시 만나지 않고 이동할 수 있는 최대 거리를 찾습니다.
그리드는 알파벳으로 채워져 있으며, 사람은 위, 아래, 왼쪽, 오른쪽 네 방향으로 이동할 수 있습니다.
해결 방법은 그리드를 순회하기 위해 백트래킹을 사용하며, 다시 방문한 셀이나 알파벳을 확인합니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Define grid, visited cells and alphabets array.
char grp[20][20]; // 그리드 정의
bool visited[20][20]; // 방문한 셀 표시
bool alp[26]; // 알파벳을 표시하는 배열
int res = 0; // 최대 이동 거리 저장
// Movement direction arrays (이동 방향 배열)
int yt[] = { 1, -1, -1, 1 }; // Vertical movement (상하 이동)
int xt[] = { 0, 1, -1, -1 }; // Horizontal movement (좌우 이동)

int R, C; // Grid dimensions (그리드의 차원)

void bt(int y, int x, int cur) {

	// Mark the current cell as visited and update the alphabet.
	visited[y][x] = true; // 현재 셀을 방문했음을 표시
	alp[grp[y][x] - 'A'] = true; // 해당 알파벳 방문 표시
	cur++; // Increase the current distance (현재 거리 증가)
	res = max(res, cur); // Update the result with the maximum value (결과를 최대값으로 업데이트)

	for (int i = 0; i < 4; i++) {
		// Calculate next positions based on movement arrays.
		y += yt[i];
		x += xt[i];

		// Check for boundaries of the grid.
		if (y < 0 || y >= R || x < 0 || x >= C) // 그리드 경계 확인
			continue;
		// Check if the cell is visited or the alphabet is visited.
		else if (visited[y][x] || alp[grp[y][x] - 'A']) // 셀 또는 알파벳이 방문되었는지 확인
			continue;

		// Recursive backtracking call.
		bt(y, x, cur);
		// Backtrack: Mark the cell and alphabet as unvisited.
		visited[y][x] = false; // 해당 셀 방문 취소
		alp[grp[y][x] - 'A'] = false; // 해당 알파벳 방문 취소
	}
}

int main()
{
	string in;

	cin >> R >> C; // Input grid dimensions (그리드 차원 입력)

	// Initialize the alphabet array as unvisited.
	fill(alp, alp + 26, false); // 알파벳 배열을 미방문 상태로 초기화

	for (int i = 0; i < R; i++) {
		cin >> in; // Input each row of the grid (그리드의 각 행 입력)
		fill(visited[i], visited[i] + C, false); // Initialize the visited array for the row (해당 행에 대한 방문 배열 초기화)
		for (int j = 0; j < C; j++) {
			grp[i][j] = in[j]; // Populate the grid with input data (입력 데이터로 그리드 채우기)
		}
	}

	bt(0, 0, 0); // Start backtracking from the top-left corner (왼쪽 상단 모서리에서 백트래킹 시작)

	cout << res; // Print the result (결과 출력)
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

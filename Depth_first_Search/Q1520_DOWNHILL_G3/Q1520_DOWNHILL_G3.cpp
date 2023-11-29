/*
commented by ChatGPT
This C++ code implements a Depth-First Search (DFS) algorithm to find the number of paths from the top-left corner (0,0) to the bottom-right corner (M-1,N-1) in a grid.
Each cell in the grid has a value, and a path can only move to a cell with a lower value.
Memoization is used to store the number of paths from each cell to avoid redundant calculations.
이 C++ 코드는 그리드에서 왼쪽 상단 모서리(0,0)에서 오른쪽 하단 모서리(M-1,N-1)로 가는 경로의 수를 찾기 위해 깊이 우선 탐색(DFS) 알고리즘을 구현합니다.
그리드의 각 셀에는 값이 있으며, 경로는 더 낮은 값을 가진 셀로만 이동할 수 있습니다.
메모이제이션을 사용하여 각 셀에서 목적지까지의 경로 수를 저장함으로써 중복 계산을 방지합니다.
*/

#include <iostream>
using namespace std;

int M, N; // 그리드의 행과 열 크기
int grp[501][501]; // 그리드의 각 셀 값을 저장하는 2차원 배열
int ny[] = { -1, 1, 0, 1 }; // y축 이동 벡터 (상, 하, 좌, 우)
int nx[] = { 0, -1, 2, -1 }; // x축 이동 벡터 (상, 하, 좌, 우)
int visited[501][501]; // 방문 여부 및 경로 수를 저장하는 2차원 배열
int res = 0; // 최종 결과(경로의 수)

int dfs(int y, int x) {
	// 이미 방문한 셀인 경우 저장된 경로 수 반환
	if (visited[y][x] != -1)
		return visited[y][x];
	else
		visited[y][x] = 0; // 초기 방문의 경우 경로 수를 0으로 설정

	int oy = y;
	int ox = x;
	for (int i = 0; i < 4; i++) {
		oy += ny[i]; // 다음 y 좌표 계산
		ox += nx[i]; // 다음 x 좌표 계산

		// 그리드 경계 및 값 검사
		if (oy < 0 || ox < 0 || oy >= M || ox >= N)
			continue; // 경계를 벗어나면 이동하지 않음
		else if (grp[oy][ox] >= grp[y][x])
			continue; // 현재 셀보다 값이 크거나 같으면 이동하지 않음
		else
			visited[y][x] += dfs(oy, ox); // 재귀적으로 DFS 수행 및 경로 수 추가
	}

	return visited[y][x]; // 계산된 경로 수 반환
}

int main() {
	cin >> M >> N; // 행과 열 크기 입력

	// 그리드 값 입력 및 방문 배열 초기화
	for (int i = 0; i < M; i++) {
		fill(visited[i], visited[i] + N, -1); // 방문 배열을 -1로 초기화
		for (int j = 0; j < N; j++)
			cin >> grp[i][j]; // 각 셀의 값을 입력
	}

	visited[M - 1][N - 1] = 1; // 목적지에 도달한 경우의 경로 수는 1
	cout << dfs(0, 0); // DFS를 사용하여 경로의 수 계산 및 출력
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

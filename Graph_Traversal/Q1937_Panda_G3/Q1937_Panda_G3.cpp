/*
commented by ChatGPT
This C++ code implements a dynamic programming solution to find the longest increasing path in a matrix. The matrix is represented by the 'grp' array, where each element has a unique value. The solution uses Depth-First Search (DFS) with memoization to find the longest increasing path from any cell, considering only adjacent cells with a higher value.
이 C++ 코드는 행렬에서 가장 긴 증가하는 경로를 찾는 동적 프로그래밍 솔루션을 구현합니다. 행렬은 'grp' 배열로 표현되며, 각 요소에는 고유한 값이 있습니다. 솔루션은 메모이제이션을 사용한 깊이 우선 탐색(DFS)을 사용하여 더 높은 값을 가진 인접 셀만 고려하여 어떤 셀에서 가장 긴 증가하는 경로를 찾습니다.
*/

#include<cmath>
#include <iostream>
using namespace std;

int mem[500][500]; // 메모이제이션을 위한 배열, 각 셀에서 시작하는 최장 경로의 길이 저장
int grp[500][500]; // 행렬의 값을 저장하는 배열
int ny[] = { -1, 1, 0, 1 }; // y축 이동 벡터 (상, 하, 좌, 우)
int nx[] = { 0, -1, 2, -1 }; // x축 이동 벡터 (상, 하, 좌, 우)
int N; // 행렬의 크기

int dp(int y, int x) {
	// 이미 계산된 셀의 경우 저장된 값을 반환
	if (mem[y][x] >= 0)
		return mem[y][x];
	else {
		mem[y][x] = 1; // 기본 경로 길이는 1
		int cy = y;
		int cx = x;
		for (int i = 0; i < 4; i++) {
			cy += ny[i]; // 다음 y 좌표 계산
			cx += nx[i]; // 다음 x 좌표 계산

			// 행렬 경계 및 값 검사
			if (cx < 0 || cy < 0 || cx >= N || cy >= N)
				continue; // 경계를 벗어나면 이동하지 않음
			else if (grp[cy][cx] <= grp[y][x])
				continue; // 현재 셀보다 값이 작거나 같으면 이동하지 않음
			mem[y][x] = max(mem[y][x], dp(cy, cx) + 1); // 재귀적으로 dp 호출 및 최대 경로 길이 갱신
		}

		return mem[y][x]; // 계산된 최대 경로 길이 반환
	}
}

int main() {
	cin >> N; // 행렬 크기 입력
	int res = 0; // 최종 결과(최대 경로 길이)

	// 행렬 값 입력 및 메모이제이션 배열 초기화
	for (int i = 0; i < N; i++) {
		fill(mem[i], mem[i] + N, -1); // 메모이제이션 배열을 -1로 초기화
		for (int j = 0; j < N; j++) {
			cin >> grp[i][j]; // 각 셀의 값을 입력
		}
	}

	// 모든 셀에 대해 dp 호출하여 최대 경로 길이 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res = max(res, dp(i, j));
		}
	}

	cout << res; // 결과 출력
}

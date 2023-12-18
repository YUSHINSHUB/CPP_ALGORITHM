/*
commented by ChatGPT
This C++ program is designed to find the shortest path in an N×M grid where '0' represents a traversable cell and '1' represents an impassable wall. The goal is to move from the top-left corner (0, 0) to the bottom-right corner (N-1, M-1) using the shortest path, including the possibility of breaking through one wall if it leads to a shorter route. The program employs a Breadth-First Search (BFS) algorithm, utilizing two queues to manage the traversal process: one for traversing through open cells and another for cells next to walls. The 'visited' array tracks the number of steps to each cell, and a special value (-2) marks the destination cell.
이 C++ 프로그램은 N×M 그리드에서 최단 경로를 찾는 것을 목표로 합니다. 여기서 '0'은 이동할 수 있는 칸을, '1'은 벽으로 지나갈 수 없는 칸을 나타냅니다. 목표는 왼쪽 상단 모서리 (0, 0)에서 오른쪽 하단 모서리 (N-1, M-1)까지 가능한 가장 짧은 경로를 사용하여 이동하는 것이며, 이는 더 짧은 경로를 제공하는 경우 한 개의 벽을 부수는 것을 포함합니다. 프로그램은 너비 우선 탐색(BFS) 알고리즘을 사용하며, 열린 칸을 통한 이동과 벽 옆의 칸을 통한 이동을 관리하기 위해 두 개의 큐를 사용합니다. 'visited' 배열은 각 칸까지의 이동 횟수를 추적하며, 특별한 값(-2)은 목적지 칸을 표시합니다.
*/

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int grp[1000][1000]; // 그리드 상태 배열 (0: 이동 가능, 1: 벽)
int visited[1000][1000]; // 각 칸까지의 최소 이동 횟수 배열
int ny[] = { -1, 1, 0, 0 }; // y축 이동 방향 벡터
int nx[] = { 0, 0, -1, 1 }; // x축 이동 방향 벡터

void search() {
	queue<int> yq, xq; // 이동 가능한 칸의 y, x 좌표 큐
	queue<int> wyq, wxq; // 벽 옆의 칸의 y, x 좌표 큐
	yq.push(0);
	xq.push(0);

	// 기본 BFS 수행
	while (!yq.empty()) {
		int cy = yq.front();
		int cx = xq.front();
		yq.pop();
		xq.pop();

		for (int i = 0; i < 4; i++) {
			int y = cy + ny[i];
			int x = cx + nx[i];
			if (y < 0 || x < 0 || y >= N || x >= M)
				continue;
			if (visited[y][x] >= 0)
				continue;
			if (grp[y][x] == 1) {
				visited[y][x] = visited[cy][cx] + 1;
				wyq.push(y);
				wxq.push(x);
				continue;
			}

			visited[y][x] = visited[cy][cx] + 1;
			yq.push(y);
			xq.push(x);
		}
	}

	// 벽 옆의 칸을 탐색하며 BFS 수행
	while (!wyq.empty()) {
		yq.push(wyq.front());
		xq.push(wxq.front());
		wyq.pop();
		wxq.pop();

		while (!yq.empty()) {
			int cy = yq.front();
			int cx = xq.front();
			yq.pop();
			xq.pop();

			for (int i = 0; i < 4; i++) {
				int y = cy + ny[i];
				int x = cx + nx[i];
				if (y < 0 || y >= N || x < 0 || x >= M)
					continue;
				if (grp[y][x] == 1)
					continue;
				if (visited[y][x] >= 0 && visited[y][x] <= visited[cy][cx] + 1)
					continue;

				visited[y][x] = visited[cy][cx] + 1;
				yq.push(y);
				xq.push(x);
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		fill(visited[i], visited[i] + M, -1);
		for (int j = 0; j < M; j++)
			grp[i][j] = temp[j] - '0';
	}

	visited[N - 1][M - 1] = -2; // 목적지에 특별한 값(-2)을 설정
	visited[0][0] = 0; // 시작점의 이동 횟수를 0으로 초기화

	search(); // BFS로 최단 경로 탐색

	cout << visited[N - 1][M - 1] + 1; // 최단 경로 길이 출력
}

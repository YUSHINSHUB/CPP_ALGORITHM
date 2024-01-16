
/*
commented by ChatGPT
This C++ code implements a Dijkstra's algorithm-based approach to navigate through a grid, where the objective is to find the minimum cost path from the top-left to the bottom-right corner.
The grid cells can have different values representing obstacles or open paths. The code uses a priority queue to process grid cells based on their accumulated cost.
It keeps track of the least cost to reach each cell and updates this cost as it explores the grid.
이 C++ 코드는 그리드를 탐색하기 위한 Dijkstra 알고리즘 기반 접근 방식을 구현합니다. 목표는 좌상단에서 우하단 모서리까지의 최소 비용 경로를 찾는 것입니다.
그리드 셀은 장애물 또는 개방 경로를 나타내는 다양한 값들을 가질 수 있습니다. 코드는 누적된 비용에 따라 그리드 셀을 처리하기 위해 우선순위 큐를 사용합니다.
각 셀에 도달하기 위한 최소 비용을 추적하고 그리드를 탐색하면서 이 비용을 업데이트합니다.
*/

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int grid[100][100]; // 그리드 배열
int mem[100][100]; // 각 셀에 도달하기 위한 최소 비용을 저장하는 배열
bool visited[100][100]; // 각 셀의 방문 여부를 추적하는 배열
int N

, M; // N과 M은 그리드의 가로 및 세로 크기를 나타냄
int ny[] = { 1, -1, 0, 0 }; // y축 이동을 위한 배열 (상, 하 이동)
int nx[] = { 0, 0, 1, -1 }; // x축 이동을 위한 배열 (우, 좌 이동)

// Dijkstra 알고리즘을 사용하여 그리드를 탐색하고 최소 비용 경로를 찾는 함수
void dajikstra() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // 최소 힙을 사용하는 우선순위 큐

	pq.push(make_pair(0, make_pair(0, 0))); // 시작점 (0,0)을 큐에 추가

	while (!pq.empty()) {
		pair<int, int> p = pq.top().second; // 현재 셀의 위치
		pq.pop();
		int y = p.first;
		int x = p.second;
		if (visited[y][x]) // 이미 방문한 셀이면 무시
			continue;
		visited[y][x] = true; // 셀 방문 표시

		for (int i = 0; i < 4; i++) { // 상, 하, 좌, 우 방향으로 탐색
			int cy = y + ny[i];
			int cx = x + nx[i];
			if (cy < 0 || cx < 0 || cy >= M || cx >= N) // 그리드 범위를 벗어나면 무시
				continue;

			// 현재 셀을 통해 이동할 때 비용을 계산하고 최소 비용을 업데이트
			if (grid[cy][cx] == 1)
				mem[cy][cx] = min(mem[cy][cx], mem[y][x] + 1);
			else
				mem[cy][cx] = min(mem[y][x], mem[cy][cx]);

			// 방문하지 않은 셀을 우선순위 큐에 추가
			if (!visited[cy][cx]) pq.push(make_pair(mem
				[cy][cx], make_pair(cy, cx)));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); // 입출력 효율을 위한 설정
	cin.tie(0); // cin과 cout의 tie를 해제하여 입출력 속도 향상

	string in;

	cin >> N >> M; // 그리드의 크기를 입력받음

	// 그리드 데이터를 입력받고, mem 배열과 visited 배열을 초기화
	for (int i = 0; i < M; i++) {
		fill(mem[i], mem[i] + N, 10001); // mem 배열을 큰 값으로 초기화
		fill(visited[i], visited[i] + N, false); // visited 배열을 false로 초기화
		cin >> in;
		for (int j = 0; j < N; j++) {
			grid[i][j] = in[j] - '0'; // 문자를 정수로 변환하여 그리드에 저장
		}
	}

	mem[0][0] = 0; // 시작점의 비용을 0으로 설정

	dajikstra(); // Dijkstra 알고리즘을 사용하여 최소 비용 경로 탐색

	cout << mem[M - 1][N - 1]; // 목표 지점까지의 최소 비용 출력
}
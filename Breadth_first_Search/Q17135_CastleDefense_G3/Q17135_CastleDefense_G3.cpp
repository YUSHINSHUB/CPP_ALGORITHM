/*
commented by ChatGPT
This C++ code is a simulation for a defense game strategy, where the player sets up to three archers at the last row of a grid to defend against advancing enemies.
Each turn, the archers can attack enemies within a certain range (D), aiming to eliminate as many as possible.
The simulation explores all possible archer placements using backtracking and calculates the maximum number of enemies that can be eliminated in one turn, utilizing a breadth-first search (BFS) algorithm to model the archers' attacks.
이 C++ 코드는 방어 게임 전략의 시뮬레이션으로, 플레이어는 그리드의 마지막 행에 최대 세 명의 궁수를 배치하여 진군하는 적들을 방어합니다.
각 턴마다, 궁수는 일정 범위(D) 내의 적을 공격하여 가능한 한 많은 적을 제거하려고 합니다.
이 시뮬레이션은 백트래킹을 사용하여 모든 가능한 궁수 배치를 탐색하고 궁수의 공격을 모델링하기 위해 너비 우선 탐색(BFS) 알고리즘을 사용하여 한 턴에 제거할 수 있는 최대 적 수를 계산합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int out = 0; // 최대 제거 가능한 적의 수를 저장하는 변수
int N, M, D; // 그리드의 세로(N), 가로(M), 궁수의 공격 범위(D)
int ny[] = { 0, -1, 0 }; // 궁수 공격 시 y축 이동 방향 (-1은 위, 0은 제자리)
int nx[] = { -1, 0, 1 }; // 궁수 공격 시 x축 이동 방향 (-1은 왼쪽, 1은 오른쪽)
int grid[16][15]; // 적의 위치를 나타내는 그리드
bool check[16]; // 궁수 배치 여부를 확인하는 배열
int sel[3]; // 선택된 궁수의 위치를 저장하는 배열

// 궁수의 공격을 시뮬레이션하는 BFS 함수
static void bfs() {
	queue<int> yq; // y좌표를 저장하는 큐
	queue<int> xq; // x좌표를 저장하는 큐

	int res = 0; // 현재 배치에서 제거할 수 있는 적의 수
	int remy[3]; // 각 궁수가 공격하는 적의 y좌표
	int remx[3]; // 각 궁수가 공격하는 적의 x좌표
	int dis[16][15]; // BFS 탐색을 위한 거리 배열
	int tgrid[16][15]; // 탐색 중 상태를 저장하는 임시 그리드
	// 원본 그리드를 임시 그리드에 복사
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tgrid[i][j] = grid[i][j];
		}
	}

	// 적이 모두 제거될 때까지 반복
	while (true) {
		fill(remy, remy + 3, N); // 각 궁수의 공격 대상 초기화
		fill(remx, remx + 3, 0);

		// 세 궁수에 대해 BFS 실행
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i <= N; i++)
				fill(dis[i], dis[i] + M, 0); // 거리 배열 초기화
			yq.push(N); // 궁수의 위치에서 시작
			xq.push(sel[j]);
			while (!yq.empty()) {
				int y = yq.front();
				int x = xq.front();
				yq.pop();
				xq.pop();
				if (dis[y][x] == D) { // 공격 범위를 초과하면 중단
					remy[j] = N; // 공격 대상이 없음을 표시
					remx[j] = 1;
					break;
				}
				// 인접 셀을 탐색
				for (int i = 0; i < 3; i++) {
					int cy = y + ny[i];
					int cx = x + nx[i];
					if (cy >= N || cx >= M || cy < 0 || cx < 0)
						continue;
					if (dis[cy][cx] > 0)
						continue;
					if (tgrid[cy][cx] == 1) { // 적을 발견하면 기록하고 중단
						remy[j] = cy;
						remx[j] = cx;
						break;
					}
					yq.push(cy);
					xq.push(cx);
					dis[cy][cx] = dis[y][x] + 1;
				}
				if (remy[j] != N)
					break;
			}
			yq = queue<int>(); // 큐 초기화
			xq = queue<int>();
		}

		// 공격 대상이 된 적을 제거
		for (int i = 0; i < 3; i++) {
			if (tgrid[remy[i]][remx[i]] == 1) {
				tgrid[remy[i]][remx[i]] = 0;
				res++;
			}
		}

		// 적을 전진시킴
		for (int i = 0; i < M; i++)
			tgrid[N - 1][i] = 0; // 맨 아래 행 초기화
		int cnt = 0; // 이동한 적의 수
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (tgrid[i][j] == 1) {
					tgrid[i][j] = 0;
					tgrid[i + 1][j] = 1;
					cnt++;
				}
			}
		}
		if (cnt == 0) // 더 이상 이동할 적이 없으면 종료
			break;
	}

	out = max(out, res); // 최대 제거 수 갱신
}

// 모든 궁수 배치를 시도하는 백트래킹 함수
static void backtracking(int cur, int idx) {
	if (idx == 3) { // 세 궁수를 모두 배치했으면 공격 시뮬레이션 실행
		bfs();
		return;
	}

	// 가능한 모든 위치에 궁수를 배치해보기
	for (int i = cur; i < M; i++) {
		if (check[i]) // 이미 궁수가 배치된 위치는 제외
			continue;
		sel[idx] = i; // 궁수 배치
		check[i] = true;
		backtracking(i + 1, idx + 1); // 다음 궁수 배치
		check[i] = false; // 배치 취소 (백트래킹)
	}
}

int main() {
	cin >> N >> M >> D; // 그리드 크기와 궁수의 공격 범위 입력 받기

	// 그리드 상태 입력 받기 (적의 위치)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	fill(check, check + M, false); // 궁수 배치 상태 배열 초기화
	backtracking(0, 0); // 백트래킹 시작

	cout << out; // 최대 제거 가능한 적의 수 출력
}

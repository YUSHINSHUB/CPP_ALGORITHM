/*
commented by ChatGPT
This C++ code implements a dynamic programming solution to find the maximum time required to complete a specific task in a project, where tasks have dependencies.
It represents the tasks as nodes in a directed acyclic graph (DAG).
Each node has a completion time, and a task can only start after all its dependencies are completed.
The code uses memoization to optimize the computation of task completion times.
이 C++ 코드는 작업에 의존성이 있는 프로젝트에서 특정 작업을 완료하는 데 필요한 최대 시간을 찾는 동적 프로그래밍 솔루션을 구현합니다.
작업은 방향성 비순환 그래프(DAG)의 노드로 표현되며, 각 노드는 완료 시간을 가지고 있습니다.
작업은 모든 의존성이 완료된 후에만 시작할 수 있습니다.
코드는 작업 완료 시간을 계산하는 데 메모이제이션을 사용하여 최적화합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int D[1001]; // 각 작업의 지속 시간을 저장하는 배열
int visited[1001]; // 메모이제이션을 위한 배열, 각 작업의 최대 완료 시간을 저장
queue<int> grp[1001]; // 작업 의존성을 나타내는 그래프 (의존성 목록)

static int dp(int idx) {
	// 이미 계산된 작업의 경우 저장된 값을 반환
	if (visited[idx] >= 0) {
		return visited[idx];
	}

	// 현재 작업에 대한 모든 선행 작업 처리
	while (!grp[idx].empty()) {
		visited[idx] = max(dp(grp[idx].front()) + D[idx], visited[idx]);
		grp[idx].pop(); // 선행 작업 처리 완료 후 제거
	}

	// 선행 작업이 없는 경우 현재 작업의 지속 시간으로 설정
	if (visited[idx] < 0)
		visited[idx] = D[idx];

	return visited[idx]; // 계산된 최대 완료 시간 반환
}


int main() {
	int T; // 테스트 케이스 수
	cin >> T;

	for (int cs = 0; cs < T; cs++) {
		int N, K, W; // 작업의 수(N), 의존성의 수(K), 목표 작업(W)
		cin >> N >> K;
		fill(visited, visited + N + 1, -1); // 메모이제이션 배열 초기화
		for (int i = 1; i <= N; i++) {
			cin >> D[i]; // 각 작업의 지속 시간 입력
			while (!grp[i].empty()) grp[i].pop(); // 이전 데이터 초기화
		}
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			grp[b].push(a); // 작업 의존성 추가
		}

		cin >> W; // 목표 작업 번호 입력
		cout << dp(W) << "\n"; // 목표 작업까지의 최대 완료 시간 계산 및 출력
	}
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

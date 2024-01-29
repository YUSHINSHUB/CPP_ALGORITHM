
/*
commented by ChatGPT
This C++ code implements a solution to find the minimum number of steps required for a character to move from position N to position K, considering options such as moving forward, backward, or teleporting (doubling the position).
The code uses a Breadth-First Search (BFS) algorithm to explore all possible moves from the starting position N, keeping track of the minimum number of steps required to reach each position.
Once the BFS is completed, the program recursively traces the path from K back to N to count the number of unique paths.
The main function reads the starting position N and the target position K from the user, then calls the bfs and find functions to compute the minimum steps and the number of paths, respectively.

이 C++ 코드는 캐릭터가 N 위치에서 K 위치로 이동하는 데 필요한 최소 단계 수를 찾는 솔루션을 구현합니다. 이 코드는 앞으로 이동, 뒤로 이동, 순간 이동(위치를 두 배로 하는)과 같은 옵션을 고려합니다.
코드는 시작 위치 N에서 모든 가능한 이동을 탐색하기 위해 BFS(너비 우선 탐색) 알고리즘을 사용하며, 각 위치에 도달하기 위해 필요한 최소 단계 수를 추적합니다.
BFS가 완료되면, 프로그램은 K에서 N으로 되돌아가는 경로를 재귀적으로 추적하여 고유한 경로 수를 계산합니다.
메인 함수는 사용자로부터 시작 위치 N과 목표 위치 K를 읽은 다음, bfs 함수와 find 함수를 호출하여 각각 최소 단계와 경로 수를 계산합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int mem[110000]; // 각 위치까지의 최소 단계 수를 추적하는 배열
int res = 0; // 고유한 경로 수를 저장하는 변수

// N에서 K까지의 최소 단계를 찾는 BFS 함수
void bfs(int N, int K) {
	fill(mem, mem + 110000, -1); // 모든 위치를 방문하지 않은 상태로 초기화
	mem[N] = 0; // 시작 위치
	queue<int> q;
	q.push(N);

	// 모든 가능한 이동을 탐색
	while (!q.empty()) {
		int cur = q.front(); // 현재 위치
		q.pop();
		int next;

		// 앞으로 이동
		next = cur + 1;
		if (next < 110000 && next >= 0 && mem[next] < 0) {
			q.push(next);
			mem[next] = mem[cur] + 1;
		}

		// 뒤로 이동
		next = cur - 1;
		if (next < 110000 && next >= 0 && mem[next] < 0) {
			q.push(next);
			mem[next] = mem[cur] + 1;
		}

		// 순간 이동
		next = cur * 2;
		if (next < 110000 && next >= 0 && mem[next] < 0) {
			q.push(next);
			mem[next] = mem[cur] + 1;
		}
	}
}

// K에서 N까지의 경로를 찾는 함수
static void find(int cur) {

	if (mem[cur] == 0) { // 시작점에 도달하면 경로 수 증가
		res++;
		return;
	}
	int next;

	// 역순으로 경로 추적
	next = cur + 1;
	if (next < 110000 && next >= 0 && mem[next] == mem[cur] - 1) {
		find(next);
	}

	next = cur - 1;
	if (next < 110000 && next >= 0 && mem[next] == mem[cur] - 1) {
		find(next);
	}

	if (cur % 2 == 0) { // 순간 이동이 가능한 경우
		next = cur / 2;
		if (next < 110000 && next >= 0 && mem[next] == mem[cur] - 1) {
			find(next);
		}
	}
}

int main()
{
	int N, K; // 시작 위치 N과 목표 위치 K

	cin >> N >> K;

	bfs(N, K); // BFS를 수행하여 최소 단계를 찾음
	find(K); // 경로를 찾음

	// 최소 단계와 경로 출력
	cout << mem[K] << "\n" << res;
}
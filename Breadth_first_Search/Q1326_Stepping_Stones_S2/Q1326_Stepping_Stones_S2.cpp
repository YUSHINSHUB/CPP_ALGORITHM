/*
commented by ChatGPT
This C++ code implements a Breadth-First Search (BFS) algorithm to solve a problem on a line of stones, where each stone has a specific jumping distance.
The algorithm finds the minimum number of jumps needed to get from a starting stone 's' to an ending stone 'e'.
The BFS navigates through the stones by making jumps of varying distances in both forward and backward directions, determined by the jumping distance of each stone.
이 C++ 코드는 각 돌이 특정 점프 거리를 가진 돌의 선에서 문제를 해결하기 위한 너비 우선 탐색(BFS) 알고리즘을 구현합니다.
이 알고리즘은 시작 돌 's'에서 끝 돌 'e'까지 가는 데 필요한 최소 점프 횟수를 찾습니다. '
BFS는 각 돌의 점프 거리에 따라 정해지는 앞쪽과 뒤쪽 방향으로 다양한 거리를 점프하며 돌을 탐색합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

static int stone[10001]; // Array to store the jump distance for each stone (각 돌의 점프 거리를 저장하는 배열)
static int mem[10001]; // Array to store the minimum number of jumps to reach each stone (각 돌에 도달하는 데 필요한 최소 점프 수를 저장하는 배열)

// Function to perform BFS and calculate the minimum number of jumps
static int bfs(int N, int s, int e) {

	queue<int> q; // Queue for BFS (BFS에 사용되는 큐)
	q.push(s); // Start BFS from the starting stone (시작 돌에서 BFS 시작)
	while (!q.empty()) {
		int idx = q.front(); // Current stone (현재 돌)
		q.pop();
		// Forward jump (앞쪽 점프)
		for (int i = idx + stone[idx]; i <= N; i += stone[idx]) {
			if (mem[i] < 0) { // If the stone is not visited yet (돌이 아직 방문되지 않았다면)
				mem[i] = mem[idx] + 1; // Update the number of jumps (점프 수 업데이트)
				q.push(i); // Add the stone to the queue (큐에 돌 추가)
			}
		}

		// Backward jump (뒤쪽 점프)
		for (int i = idx - stone[idx]; i >= 1; i -= stone[idx]) {
			if (mem[i] < 0) { // If the stone is not visited yet (돌이 아직 방문되지 않았다면)
				mem[i] = mem[idx] + 1; // Update the number of jumps (점프 수 업데이트)
				q.push(i); // Add the stone to the queue (큐에 돌 추가)
			}
		}
	}

	return mem[e]; // Return the number of jumps to reach the end stone (끝 돌에 도달하는 데 필요한 점프 수 반환)
}

int main()
{
	int N, s, e; // Variables for number of stones (N), start stone (s), and end stone (e)
	cin >> N; // Read the number of stones
	fill(mem, mem + 1 + N, -1); // Initialize memory array with -1 (unvisited)
	for (int i = 1; i <= N; i++) {
		cin >> stone[i]; // Read the jump distance for each stone
	}
	cin >> s >> e; // Read the start and end stones
	mem[s] = 0; // Starting stone has 0 jumps

	cout << bfs(N, s, e); // Perform BFS and output the result
}
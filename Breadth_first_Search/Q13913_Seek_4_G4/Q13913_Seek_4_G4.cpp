
/*
commented by ChatGPT
This C++ code implements a solution to find the shortest path from a starting point N to a target point K using a Breadth-First Search (BFS) algorithm.
The code utilizes an array mem to store the minimum number of steps needed to reach each position from N, and a vector list to record the path taken.
The bfs function explores all possible moves (one step forward or backward, and teleporting to twice the current position) and fills the mem array with the number of steps taken to reach each position.
The find function recursively reconstructs the path from K back to N by choosing positions that are one step closer to N. The final path is stored in reverse order in list.
After calculating the path, the code outputs the minimum number of steps and the sequence of positions leading from N to K.

이 C++ 코드는 너비 우선 탐색(BFS) 알고리즘을 사용하여 시작점 N에서 목표점 K까지의 최단 경로를 찾는 솔루션을 구현합니다.
코드는 N에서 각 위치까지 도달하는데 필요한 최소 단계 수를 저장하기 위해 mem 배열을 사용하며, 취한 경로를 기록하기 위해 벡터 list를 사용합니다.
bfs 함수는 가능한 모든 이동(한 걸음 앞으로 또는 뒤로 이동하거나 현재 위치의 두 배로 순간 이동)을 탐색하고 각 위치에 도달하는 데 걸린 단계 수로 mem 배열을 채웁니다.
find 함수는 N에 한 걸음 더 가까운 위치를 선택하며 K에서 N으로 되돌아가는 경로를 재귀적으로 재구성합니다. 최종 경로는 list에 역순으로 저장됩니다.
경로를 계산한 후, 코드는 최소 단계 수와 N에서 K로 이어지는 위치의 순서를 출력합니다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mem[110000]; // Array to keep track of minimum steps to each position
vector<int> list; // Vector to store the path

// BFS to find the minimum steps from N to K
static void bfs(int N, int K) {
	fill(mem, mem + 110000, -1); // Initialize all positions as unvisited
	mem[N] = 0; // Starting position
	queue<int> q;
	q.push(N);

	// Explore all possible moves
	while (!q.empty()) {
		int cur = q.front(); // Current position
		q.pop();
		int next;

		// Move forward
		next = cur + 1;
		if (next < 110000 && next >= 0 && mem[next] < 0) {
			q.push(next);
			mem[next] = mem[cur] + 1;
		}

		// Move backward
		next = cur - 1;
		if (next < 110000 && next >= 0 && mem[next] < 0) {
			q.push(next);
			mem[next] = mem[cur] + 1;
		}

		// Teleport
		next = cur * 2;
		if (next < 110000 && next >= 0 && mem[next] < 0) {
			q.push(next);
			mem[next] = mem[cur] + 1;
		}
	}
}

// Function to find the path from K to N
static void find(int cur) {
	list.push_back(cur);
	if (mem[cur] == 0) return; // Base case

	int next;

	// Trace the path in reverse order
	next = cur + 1;
	if (next < 110000 && next >= 0 && mem[next] == mem[cur] - 1) {
		find(next);
		return;
	}

	next = cur - 1;
	if (next < 110000 && next >= 0 && mem[next] == mem[cur] - 1) {
		find(next);
		return;
	}

	next = cur / 2;
	if (next < 110000 && next >= 0 && mem[next] == mem[cur] - 1) {
		find(next);
		return;
	}
}

int main() {
	int N, K; // Starting position N and target position K

	cin >> N >> K;

	bfs(N, K); // Perform BFS to find the minimum steps
	find(K); // Find the path

	// Output the minimum steps and the path
	cout << mem[K] << "\n";
	for (int i = mem[K]; i >= 0; i--)
		cout << list[i] << " ";
}
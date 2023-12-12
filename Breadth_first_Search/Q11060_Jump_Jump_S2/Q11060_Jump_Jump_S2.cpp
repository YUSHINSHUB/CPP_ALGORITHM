
/*
commented by ChatGPT
This C++ code implements a BFS (Breadth-First Search) algorithm to solve a maze-like problem.
The maze is represented by an array where each element indicates the maximum jump distance from that position.
The goal is to determine the minimum number of steps required to reach the end of the array.
The bfs function uses a queue to explore all possible moves from the current position.
The mem array tracks the minimum number of steps to reach each index. If it's impossible to reach the end, the function returns -1.
이 C++ 코드는 BFS (너비 우선 탐색) 알고리즘을 사용하여 미로와 같은 문제를 해결합니다.
미로는 각 요소가 해당 위치에서의 최대 점프 거리를 나타내는 배열로 표현됩니다.
목표는 배열의 끝에 도달하는 데 필요한 최소 단계 수를 결정하는 것입니다.
bfs 함수는 큐를 사용하여 현재 위치에서 가능한 모든 움직임을 탐색합니다.
mem 배열은 각 인덱스에 도달하는 데 필요한 최소 단계 수를 추적합니다.
끝에 도달할 수 없는 경우 함수는 -1을 반환합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int N; // Size of the maze
int mem[1001]; // Array to store the minimum number of steps to reach each index
int maze[1001]; // Array representing the maze with maximum jump lengths

// Function to perform BFS and find the minimum number of steps
int bfs() {

	queue<int> q; // Queue for BFS
	q.push(0); // Start from the first index
	mem[0] = 0; // Starting point has 0 steps

	while (!q.empty()) {
		int idx = q.front(); // Current index
		q.pop();
		for (int i = idx; i <= idx + maze[idx]; i++) {
			if (i >= N) // If the index is beyond the maze, break the loop
				break;
			if (mem[i] < 0) { // If this index is not visited yet
				mem[i] = mem[idx] + 1; // Update the number of steps
				q.push(i); // Add this index to the queue
			}
		}
	}

	return mem[N - 1]; // Return the minimum number of steps to reach the end
}

int main()
{
	cin >> N; // Read the size of the maze
	for (int i = 0; i < N; i++) {
		cin >> maze[i]; // Fill the maze array
	}
	fill(mem, mem + N, -1); // Fill the memory array with -1 (unvisited)

	cout << bfs(); // Output the result of the BFS function
}






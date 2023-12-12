
/*
commented by ChatGPT
This C++ code implements a Breadth-First Search (BFS) algorithm to find the shortest path between two nodes in a graph.
The graph is represented using an adjacency list.
The algorithm calculates the minimum number of edges required to travel from node 'a' to node 'b'.
이 C++ 코드는 두 노드 간의 최단 경로를 찾기 위해 너비 우선 탐색(BFS) 알고리즘을 구현합니다.
그래프는 인접 리스트를 사용하여 표현됩니다.
이 알고리즘은 노드 'a'에서 노드 'b'까지 이동하는 데 필요한 최소 간선 수를 계산합니다.
*/

#include <iostream>
#include<queue>
#include<vector>

using namespace std;

queue<int> q; // Queue for BFS (BFS에 사용되는 큐)
vector<int> list[1001]; // Adjacency list for the graph (그래프의 인접 리스트)
static int mem[1001]; // Array to store the distance from node 'a' to each node (노드 'a'에서 각 노드까지의 거리를 저장하는 배열)
static int a, b; // Start node and end node (시작 노드와 종료 노드)
static int N, M; // Number of nodes (N) and edges (M) (노드의 수(N)와 간선의 수(M))

// Function to perform BFS and find the shortest path
static int bfs() {

	q.push(a); // Start BFS from node 'a' (노드 'a'에서 BFS 시작)

	while (!q.empty()) {
		int idx = q.front(); // Current node (현재 노드)
		q.pop();
		// Iterate through all adjacent nodes (모든 인접 노드를 반복)
		for (int i = 0; i < list[idx].size(); i++) {
			int temp = list[idx][i]; // Adjacent node (인접 노드)
			if (mem[temp] < 0) { // If the node is not visited yet (노드가 아직 방문되지 않았다면)
				mem[temp] = mem[idx] + 1; // Update the distance (거리 업데이트)
				q.push(temp); // Add the node to the queue (큐에 노드 추가)
			}
		}
	}

	return mem[b]; // Return the distance from 'a' to 'b' (노드 'a'에서 'b'까지의 거리 반환)
}

int main()
{
	cin >> a >> b; // Input start and end nodes (시작 및 종료 노드 입력)
	cin >> N >> M; // Input number of nodes and edges (노드 및 간선 수 입력)

	fill(mem, mem + N + 1, -1); // Initialize memory array with -1 (메모리 배열을 -1로 초기화)
	mem[a] = 0; // Distance from 'a' to itself is 0 (노드 'a'에서 자기 자신까지의 거리는 0)

	// Input edges and update adjacency list (간선 입력 및 인접 리스트 업데이트)
	int i1, i2;
	for (int i = 0; i < M; i++) {
		cin >> i1 >> i2;
		list[i1].push_back(i2);
		list[i2].push_back(i1);
	}

	cout << bfs(); // Perform BFS and output the result (BFS 수행 및 결과 출력)
}






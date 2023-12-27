/*
commented by ChatGPT
This C++ code implements Dijkstra's algorithm to find the shortest path in a graph, similar to the Java code previously discussed.
The program calculates the shortest path from node 1 to node N, passing through two specific nodes v1 and v2 in either order.
It determines the shortest of the two possible routes (1 -> v1 -> v2 -> N and 1 -> v2 -> v1 -> N) and outputs the minimum total distance, or -1 if no path exists.
이 C++ 코드는 앞서 논의한 Java 코드와 유사하게, 그래프에서 최단 경로를 찾기 위해 다익스트라 알고리즘을 구현합니다.
이 프로그램은 두 개의 특정 노드 v1과 v2를 거쳐 노드 1에서 노드 N까지의 최단 경로를 계산합니다.
두 가지 가능한 경로(1 -> v1 -> v2 -> N 및 1 -> v2 -> v1 -> N) 중 더 짧은 것을 결정하고 최소 총 거리를 출력하거나, 경로가 없으면 -1을 출력합니다.
*/

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int N, E; // Number of nodes (N) and edges (E) (노드 (N)와 엣지 (E)의 수)
int v1, v2; // Two specific nodes to pass through (거쳐야 할 두 개의 특정 노드)
vector<int> route[801]; // Adjacency list for the graph (그래프의 인접 리스트)
int dist[801][801]; // Array to store distances between nodes (노드 간 거리를 저장하는 배열)
int mem[801]; // Memory array for Dijkstra's algorithm (다익스트라 알고리즘을 위한 메모리 배열)
bool visited[801]; // Array to track visited nodes (방문한 노드를 추적하는 배열)

static int dijk(int start, int end) { // Dijkstra's algorithm function (다익스트라 알고리즘 함수)

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // Priority queue for selecting the node with the smallest distance (가장 작은 거리의 노드를 선택하기 위한 우선순위 큐)

	fill(visited, visited + N + 1, false); // Reset visited nodes (방문한 노드 초기화)
	fill(mem, mem + N + 1, 200000000); // Initialize memory array with high values (메모리 배열을 높은 값으로 초기화)
	mem[start] = 0; // Distance to the start node is 0 (시작 노드까지의 거리는 0)
	pq.push(make_pair(0, start)); // Add start node to priority queue (시작 노드를 우선순위 큐에 추가)

	while (!pq.empty()) {
		int cur = pq.top().second; // Get the current node (현재 노드 가져오기)
		pq.pop();
		if (visited[cur]) // Skip if already visited (이미 방문한 경우 건너뛰기)
			continue;
		visited[cur] = true;
		for (int i = 0; i < route[cur].size(); i++) {
			int temp = route[cur][i];
			mem[temp] = min(mem[temp], mem[cur] + dist[cur][temp]); // Update the distance to the neighboring nodes (인접 노드까지의 거리 업데이트)
			pq.push(make_pair(mem[temp], temp)); // Add neighboring node to priority queue (인접 노드를 우선순위 큐에 추가)
		}
	}

	return mem[end]; // Return the shortest distance to the end node (종료 노드까지의 최단 거리 반환)
}

int main()
{
	ios_base::sync_with_stdio(0); // Fast IO setup (빠른 입출력 설정)
	cin.tie(0); // Untie cin from cout (cin을 cout에서 분리)
	cout.tie(0); // Untie cout (cout 분리)

	cin >> N >> E; // Read the number of nodes and edges (노드와 엣지의 수 읽기)

	// Read edges and their distances (엣지와 그 거리 읽기)
	for (int i = 0; i < E; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		route[a].push_back(b);
		route[b].push_back(a);
		dist[a][b] = d;
		dist[b][a] = d;
	}
	cin >> v1 >> v2; // Read the two specific nodes (두 개의 특정 노드 읽기)

	// Calculate the shortest path considering both routes (두 경로 모두 고려하여 최단 경로 계산)
	int r1 = dijk(1, v1) + dijk(v1, v2) + dijk(v2, N);
	int r2 = dijk(1, v2) + dijk(v2, v1) + dijk(v1, N);
	int res = min(r1, r2); // Determine the shorter of the two routes (두 경로 중 더 짧은 것 결정)

	// Output the result (-1 if no path exists) (결과 출력, 경로가 없으면 -1)
	if (res >= 200000000)
		cout << "-1";
	else
		cout << res;
}







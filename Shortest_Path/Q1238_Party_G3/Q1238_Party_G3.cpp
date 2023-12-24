/*
commented by ChatGPT
This C++ code implements a modified Dijkstra's algorithm to find the longest round trip time to a specified target node X in a network of nodes.
It calculates the shortest path from every node to X and then the longest path from X back to each node.
이 C++ 코드는 노드 네트워크에서 지정된 대상 노드 X까지의 최장 왕복 시간을 찾기 위해 수정된 다익스트라 알고리즘을 구현합니다.
모든 노드에서 X까지의 최단 경로와 X에서 각 노드로 돌아가는 최장 경로를 계산합니다.
*/

#include <iostream>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

int N, X; // Number of nodes (N) and the target node (X) (노드의 수 (N) 및 대상 노드 (X))
vector<int> route[1001]; // Array of vectors to store routes (노선을 저장하는 벡터 배열)
int distan[1001][1001]; // 2D array to store distances between nodes (노드 간 거리를 저장하는 2D 배열)
int mem[1001]; // Array to store minimum distances to each node (각 노드까지의 최소 거리를 저장하는 배열)
bool visited[1001]; // Array to track visited nodes (방문한 노드를 추적하는 배열)
int dist[1001]; // Array to store the total distance for the round trip (왕복 여행에 대한 총 거리를 저장하는 배열)

int dijk(int dep) { // Function implementing Dijkstra's algorithm (다익스트라 알고리즘을 구현하는 함수)

	fill(visited, visited + N + 1, false); // Reset visited array (방문 배열 초기화)
	fill(mem, mem + N + 1, INT_MAX); // Initialize memory array with maximum distances (메모리 배열을 최대 거리로 초기화)
	mem[dep] = 0; // Set the starting node's distance to 0 (시작 노드의 거리를 0으로 설정)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue for nodes (노드를 위한 우선순위 큐)

	pq.push(make_pair(0, dep)); // Add the starting node to the queue (시작 노드를 큐에 추가)

	while (!pq.empty()) { // Process nodes until the queue is empty (큐가 빌 때까지 노드 처리)

		int cur = pq.top().second; // Current node (현재 노드)
		pq.pop(); // Remove the current node from the queue (큐에서 현재 노드 제거)
		if (visited[cur]) // Skip if already visited (이미 방문한 경우 건너뛰기)
			continue;
		visited[cur] = true; // Mark the current node as visited (현재 노드를 방문한 것으로 표시)

		for (int i = 0; i < route[cur].size(); i++) { // Iterate over connected nodes (연결된 노드들을 반복)
			int next = route[cur][i]; // Connected node (연결된 노드)
			mem[next] = min(mem[next], mem[cur] + distan[cur][next]); // Update minimum distance (최소 거리 업데이트)
			if (!visited[next]) { // If the connected node is not visited (연결된 노드가 방문되지 않았다면)
				pq.push(make_pair(mem[next], next)); // Add connected node to the queue (연결된 노드를 큐에 추가)
			}
		}
	}

	return mem[X]; // Return the minimum distance to the target node X (대상 노드 X까지의 최소 거리 반환)
}

int back() { // Function to find the longest return trip (가장 긴 귀환 여행을 찾는 함수)

	int res = 0; // Variable to store the longest distance (가장 긴 거리를 저장하는 변수)

	fill(visited, visited + N + 1, false); // Reset visited array (방문 배열 초기화)
	fill(mem, mem + N + 1, INT_MAX); // Initialize memory array with maximum distances (메모리 배열을 최대 거리로 초기화)
	mem[X] = 0; // Set the target node's distance to 0 (대상 노드의 거리를 0으로 설정)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue for nodes (노드를 위한 우선순위 큐)

	pq.push(make_pair(0, X)); // Add the target node to the queue (대상 노드를 큐에 추가)

	while (!pq.empty()) { // Process nodes until the queue is empty (큐가 빌 때까지 노드 처리)

		int cur = pq.top().second; // Current node (현재 노드)
		pq.pop(); // Remove the current node from the queue (큐에서 현재 노드 제거)
		if (visited[cur]) // Skip if already visited (이미 방문한 경우 건너뛰기)
			continue;
		visited[cur] = true; // Mark the current node as visited (현재 노드를 방문한 것으로 표시)

		for (int i = 0; i < route[cur].size(); i++) { // Iterate over connected nodes (연결된 노드들을 반복)
			int next = route[cur][i]; // Connected node (연결된 노드)
			mem[next] = min(mem[next], mem[cur] + distan[cur][next]); // Update minimum distance (최소 거리 업데이트)
			if (!visited[next]) { // If the connected node is not visited (연결된 노드가 방문되지 않았다면)
				pq.push(make_pair(mem[next], next)); // Add connected node to the queue (연결된 노드를 큐에 추가)
			}
		}
	}

	for (int i = 1; i <= N; i++) { // Iterate over all nodes (모든 노드를 반복)
		if (i == X) // Skip the target node X (대상 노드 X 건너뛰기)
			continue;
		dist[i] += mem[i]; // Add the distance from X to each node (X에서 각 노드까지의 거리 추가)
		res = max(res, dist[i]); // Update the result with the maximum distance (최대 거리로 결과 업데이트)
	}

	return res; // Return the longest round trip distance (가장 긴 왕복 여행 거리 반환)
}

int main() {
	ios_base::sync_with_stdio(0); // Fast IO setup (빠른 입출력 설정)
	cin.tie(0); // Untie cin from cout (cin을 cout에서 분리)
	cout.tie(0); // Untie cout (cout 분리)

	int dep, arr, dis; // Variables for input (입력을 위한 변수)
	int M; // Number of routes (노선 수)
	int res = 0; // Variable to store the result (결과를 저장할 변수)

	cin >> N >> M >> X; // Read the number of nodes, routes, and the target node (노드 수, 노선 수, 대상 노드 읽기)

	for (int i = 1; i <= N; i++) {
		fill(distan[i], distan[i] + N + 1, 101); // Initialize distances with a large number (거리를 큰 수로 초기화)
	}

	for (int i = 0; i < M; i++) {
		cin >> dep >> arr >> dis; // Read route and distance (노선과 거리 읽기)
		if (distan[dep][arr] > 100) // Add the route if not already present (이미 존재하지 않는 경우 노선 추가)
			route[dep].push_back(arr);
		distan[dep][arr] = min(distan[dep][arr], dis); // Update the distance (거리 업데이트)
	}

	visited[X] = true; // Mark the target node as visited (대상 노드를 방문한 것으로 표시)

	for (int i = 1; i <= N; i++) { // Calculate distances to X (X까지의 거리 계산)
		if (i == X) // Skip the target node X (대상 노드 X 건너뛰기)
			continue;
		dist[i] = dijk(i); // Calculate distance using Dijkstra's algorithm (다익스트라 알고리즘을 사용하여 거리 계산)
	}

	cout << back(); // Output the longest round trip distance (가장 긴 왕복 여행 거리 출력)
}

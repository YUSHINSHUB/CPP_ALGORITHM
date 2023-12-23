/*
commented by ChatGPT
This C++ code implements Dijkstra's algorithm using a priority queue.
It finds the shortest path with the minimum cost between two nodes in a graph, where each edge has an associated cost.
이 C++ 코드는 우선 순위 큐를 사용하여 다익스트라 알고리즘을 구현합니다.
각 간선에 연결된 비용이 있는 그래프에서 두 노드 사이의 최단 경로와 최소 비용을 찾습니다.
*/

#include <iostream>
#include <queue>
#include<climits>
#include<cmath>

using namespace std;

int fee[1001][1001]; // 2D array to store travel costs between nodes (노드 간 여행 비용을 저장하는 2D 배열)
vector<int> route[1001]; // Array of vectors to store routes (노선을 저장하는 벡터 배열)
int departure, arrival; // Departure and arrival nodes (출발 및 도착 노드)
bool visited[1001]; // Array to track visited nodes (방문한 노드를 추적하는 배열)
long long mem[1001]; // Array to store minimum travel cost to each node (각 노드까지의 최소 여행 비용을 저장하는 배열)

long long dijk() { // Dijkstra's algorithm implementation (다익스트라 알고리즘 구현)

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // Priority queue for nodes (노드를 위한 우선순위 큐)

	pq.push(pair<int, int>(0, departure)); // Adding departure node to the queue (출발 노드를 큐에 추가)

	while (!pq.empty()) { // Processing nodes in the queue (큐의 노드 처리)
		int idx = pq.top().second; // Current node (현재 노드)
		pq.pop(); // Remove node from queue (큐에서 노드 제거)
		if (visited[idx]) // Skip if already visited (이미 방문한 경우 건너뛰기)
			continue;
		visited[idx] = true; // Mark as visited (방문으로 표시)
		for (int i = 0; i < route[idx].size(); i++) { // Iterate over connected nodes (연결된 노드 반복)
			int temp = route[idx][i]; // Connected node (연결된 노드)
			mem[temp] = min(mem[temp], mem[idx] + fee[idx][temp]); // Update minimum cost (최소 비용 업데이트)
			pq.push(pair<int, int>(mem[temp], temp)); // Add connected node to the queue (연결된 노드를 큐에 추가)
		}
	}

	return mem[arrival]; // Return minimum cost to arrival node (도착 노드까지의 최소 비용 반환)

}

int main() {
	ios_base::sync_with_stdio(0); // Fast IO (빠른 입출력 설정)
	cin.tie(0); // Untie cin and cout (cin과 cout 연결 해제)
	cout.tie(0); // Untie cout (cout 연결 해제)

	int dep, arr, pri; // Variables for input (입력을 위한 변수)
	int N, M; // Number of nodes and routes (노드 및 노선 수)

	cin >> N >> M; // Input number of nodes and routes (노드 및 노선 수 입력)

	fill(visited, visited + N + 1, false); // Set all nodes as not visited (모든 노드를 미방문으로 설정)
	fill(mem, mem + N + 1, LLONG_MAX); // Set initial costs to maximum (초기 비용을 최대로 설정)
	for (int i = 1; i <= N; i++) {
		fill(fee[i], fee[i] + N + 1, INT_MAX); // Initialize travel costs to maximum (여행 비용을 최대로 초기화)
	}

	for (int i = 0; i < M; i++) { // Input routes and costs (노선 및 비용 입력)
		cin >> dep >> arr >> pri; // Read route and cost (노선 및 비용 읽기)
		fee[dep][arr] = min(fee[dep][arr], pri); // Store minimum cost (최소 비용 저장)
		route[dep].push_back(arr); // Add route (노선 추가)
	}

	cin >> departure >> arrival; // Input departure and arrival nodes (출발 및 도착 노드 입력)

	mem[departure] = 0; // Set cost to depart from departure node to 0 (출발 노드에서 출발하는 비용을 0으로 설정)

	cout << dijk(); // Execute Dijkstra's algorithm and output result (다익스트라 알고리즘 실행 및 결과 출력)
}

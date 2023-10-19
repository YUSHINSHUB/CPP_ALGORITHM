/*
commented by ChatGPT
This C++ code implements the Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices in a graph.
The graph is represented using an adjacency list and priority queue to improve performance.
The code outputs the shortest distances to each vertex; if a vertex is unreachable, it outputs "INF".
이 C++ 코드는 그래프에서 출발 정점부터 모든 다른 정점까지의 최단 경로를 찾기 위해 다익스트라 알고리즘을 구현합니다.
그래프는 인접 리스트와 우선순위 큐를 사용하여 표현되며 성능을 향상시킵니다.
코드는 각 정점까지의 최단 거리를 출력합니다; 만약 정점에 도달할 수 없으면 "INF"를 출력합니다.
*/

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {

	// Custom comparator for the priority queue to sort based on distance.
	// 우선순위 큐를 거리를 기준으로 정렬하기 위한 사용자 정의 비교자.
	auto compare = [](pair<int, int> o1, pair<int, int> o2) {
		return o1.second > o2.second;
	};

	int V, E, K;
	cin >> V >> E >> K;

	int mem[20001];
	// Initialize the distances to a high value (infinity representation).
	// 거리를 높은 값(무한대 표현)으로 초기화.
	fill(mem, mem + V + 1, 100000000);
	// Set the distance of the starting node to 0.
	// 시작 노드의 거리를 0으로 설정.
	mem[K] = 0;

	// Representation of the graph using adjacency list.
	// 인접 리스트를 사용한 그래프 표현.
	vector<vector<pair<int, int>>> grp;
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

	// Initializing the adjacency list.
	// 인접 리스트 초기화.
	for (int i = 0; i <= V; i++) {
		vector<pair<int, int>> temp;
		grp.push_back(temp);
	}

	// Reading the edges of the graph.
	// 그래프의 간선 읽기.
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		grp[u].push_back({ v, w });
	}

	// Push the starting node into the priority queue.
	// 시작 노드를 우선순위 큐에 넣습니다.
	pq.push({ K, 0 });

	// Dijkstra's algorithm implementation.
	// 다익스트라 알고리즘 구현.
	while (!pq.empty()) {
		pair<int, int> dij = pq.top();
		pq.pop();
		int node = dij.first;
		int dis = dij.second;

		// Visit all the neighbors of the current node.
		// 현재 노드의 모든 이웃을 방문합니다.
		for (int i = 0; i < grp[node].size(); i++) {
			// Update the shortest distance if a shorter path is found.
			// 더 짧은 경로가 발견되면 최단 거리를 업데이트합니다.
			if (dis + grp[node][i].second < mem[grp[node][i].first]) {
				mem[grp[node][i].first] = dis + grp[node][i].second;
				pq.push({ grp[node][i].first, mem[grp[node][i].first] });
			}
		}
	}

	// Output the shortest distances to all vertices.
	// 모든 정점까지의 최단 거리를 출력합니다.
	for (int i = 1; i <= V; i++) {
		if (mem[i] >= 100000000)
			cout << "INF\n"; // Vertex is unreachable. 정점에 도달할 수 없습니다.
		else
			cout << mem[i] << "\n";
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

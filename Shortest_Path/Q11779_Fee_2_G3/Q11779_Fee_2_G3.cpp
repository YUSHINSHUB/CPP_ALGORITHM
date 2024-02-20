/*
commented by ChatGPT
This C++ code implements the Dijkstra's algorithm to find the shortest path between a source node and a destination node in a graph.
It utilizes a priority queue to efficiently select the next node with the least cost from the source.
The graph is represented using adjacency lists for successor nodes and predecessor nodes to reconstruct the path once the shortest path cost is determined.
The final part of the code reconstructs the path from the destination back to the source by tracing through the predecessors.
이 C++ 코드는 그래프에서 소스 노드와 목적지 노드 사이의 최단 경로를 찾기 위해 다익스트라 알고리즘을 구현합니다.
우선순위 큐를 사용하여 소스로부터 최소 비용의 다음 노드를 효율적으로 선택합니다.
그래프는 후속 노드와 선행 노드에 대한 인접 리스트를 사용하여 표현되며, 최단 경로 비용이 결정되면 경로를 재구성하기 위해 사용됩니다.
코드의 마지막 부분은 선행자를 통해 목적지에서 소스로 경로를 재구성합니다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int cost[1001]; // 각 노드까지의 최소 비용을 저장하는 배열
int edge[1001][1001]; // 노드 간의 가중치(비용)를 저장하는 2차원 배열
vector<vector<int>> nx(1001, vector<int>(1001)); // 각 노드에서 다음으로 이동할 수 있는 노드 목록
vector<vector<int>> pr(1001, vector<int>(1001)); // 각 노드로 들어오는 이전 노드 목록
vector<int> path; // 최종 경로를 저장하는 벡터
int from, to; // 시작 노드와 종료 노드
bool visited[1001]; // 노드의 방문 여부를 추적하는 배열

// 우선순위 큐에서 사용할 비교 함수. 더 낮은 비용을 가진 노드를 우선하여 처리
auto comp = [](const int a, const int b) {
	return cost[a] > cost[b];
};

priority_queue<int, vector<int>, decltype(comp)> pq(comp); // 최소 비용 노드를 우선 처리하기 위한 우선순위 큐

int dajikstra() {

	pq.push(from); // 시작 노드를 우선순위 큐에 추가
	cost[from] = 0; // 시작 노드의 비용을 0으로 초기화

	while (!pq.empty()) {
		int cur = pq.top(); // 현재 노드
		pq.pop(); // 우선순위 큐에서 제거
		visited[cur] = true; // 현재 노드 방문 처리
		for (int i = 0; i < nx[cur].size(); i++) { // 모든 인접 노드에 대해
			int temp = nx[cur][i]; // 인접 노드
			if (visited[temp])
				continue; // 이미 방문한 노드는 건너뛰기
			if (cost[temp] > cost[cur] + edge[cur][temp]) { // 더 낮은 비용의 경로를 찾은 경우
				cost[temp] = cost[cur] + edge[cur][temp]; // 비용 업데이트
				pq.push(temp); // 업데이트된 노드를 우선순위 큐에 추가
			}
		}
	}

	return cost[to]; // 목적지 노드까지의 최소 비용 반환
}

void find_path() {

	int cur = to; // 목적지 노드에서 시작
	path.push_back(to); // 경로에 목적지 노드 추가

	while (cur != from) { // 시작 노드에 도달할 때까지
		for (int i = 0; i < pr[cur].size(); i++) { // 모든 이전 노드에 대해
			int p = pr[cur][i]; // 이전 노드
			if (cost[p] + edge[p][cur] == cost[cur]) { // 최단 경로를 만족하는 이전 노드 찾기
				path.push_back(p); // 경로에 이전 노드 추가
				cur = p; // 현재 노드 업데이트
				break; // 하나의 이전 노드만 필요
			}
		}
	}

}

int main()
{
	int n, m, res;

	cin >> n >> m;
	fill(visited, visited + n + 1, false); // 방문 배열 초기화
	fill(cost, cost + n + 1, INT_MAX); // 비용 배열 초기화

	for (int i = 1; i <= n; i++) {
		fill(edge[i], edge[i] + n + 1, INT_MAX); // 가중치 배열 초기화
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		nx[a].push_back(b); // 다음 노드로 이동 가능한 노드 추가
		pr[b].push_back(a); // 이전 노드 목록에 추가
		edge[a][b] = min(edge[a][b], c); // 노드 간 최소 비용 업데이트
	}

	cin >> from >> to; // 시작 노드와 목적지 노드 입력

	res = dajikstra(); // 다익스트라 알고리즘 실행
	find_path(); // 최단 경로 찾기

	cout << res << "\n" << path.size() << "\n"; // 결과 출력
	for (int i = path.size() - 1; i >= 0; i--) // 경로 역순으로 출력
		cout << path[i] << " ";
}

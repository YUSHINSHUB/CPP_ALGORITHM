
/*
commented by ChatGPT
This C++ code checks if the given graph can be bipartite (i.e., it can be colored using only two colors such that no two adjacent vertices share the same color).
It uses a Breadth-First Search approach to try coloring the vertices and checks if there are any contradictions in the process.
If the graph can be bipartite, it outputs "YES"; otherwise, it outputs "NO".
이 C++ 코드는 주어진 그래프가 이분 그래프인지 (즉, 인접한 두 정점이 같은 색상을 공유하지 않도록 오직 두 가지 색상만을 사용하여 색칠할 수 있는지) 확인합니다.
정점을 색칠하려고 시도하는 데 너비 우선 탐색 접근법을 사용하고, 과정에서 모순이 있는지 확인합니다.
그래프가 이분 그래프라면 "YES"를 출력하고, 그렇지 않으면 "NO"를 출력합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int V, E;
queue<int> q[20001];
int chk[20001];

bool search() {
	bool res = true; // Result variable to store if the graph is bipartite (그래프가 이분 그래프인지를 저장하는 결과 변수)
	int idx = 0; // Variable to hold the current color index (현재 색상 인덱스를 저장하는 변수)
	queue<int> bq; // Queue to perform BFS (BFS를 수행하기 위한 큐)
	for (int i = 1; i <= V; i++) {
		if (chk[i] == 0) { // If vertex i is not visited yet (정점 i가 아직 방문되지 않은 경우)
			idx = 1; // Starting with color index 1 (색상 인덱스 1부터 시작)
			chk[i] = 1; // Mark vertex i as visited with color 1 (정점 i를 색상 1으로 방문 표시)
			bq.push(i); // Add vertex i to BFS queue (BFS 큐에 정점 i 추가)
			while (!bq.empty()) {
				int temp = bq.front();
				bq.pop();
				idx = chk[temp]; // Get color index of current vertex (현재 정점의 색상 인덱스 가져오기)
				while (!q[temp].empty()) {
					int t = q[temp].front();
					q[temp].pop();

					if (chk[t] == 0) { // If neighboring vertex is not visited (인접한 정점이 아직 방문되지 않은 경우)
						// Coloring the neighboring vertex with opposite color (인접한 정점을 반대 색으로 색칠)
						chk[t] = (idx == 1) ? 2 : 1;
						bq.push(t);
					}
					// If neighboring vertex has the same color as current vertex, set res to false (인접한 정점이 현재 정점과 같은 색상을 가지면 res를 false로 설정)
					else if ((idx == 1 && chk[t] == 1) || (idx == 2 && chk[t] == 2)) {
						res = false;
						break;
					}
				}

				if (!res) // If contradiction found, break (모순이 발견되면 종료)
					break;
			}
			if (!res) // If contradiction found, break (모순이 발견되면 종료)
				break;
			idx = 0;
		}
	}
	return res;
}

int main() {
	int K; // Number of test cases (테스트 케이스의 수)
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		fill(chk, chk + V + 1, 0); // Initialize the chk array (chk 배열 초기화)

		// Clear the queues for each vertex (각 정점에 대한 큐 초기화)
		for (int j = 1; j <= V; j++)
			q[j] = queue<int>();

		// Input edges of the graph (그래프의 간선 입력)
		for (int j = 0; j < E; j++) {
			int a, b;
			cin >> a >> b;

			// Since it's an undirected graph, add both ways (무방향 그래프이므로 양쪽 모두 추가)
			q[a].push(b);
			q[b].push(a);
		}

		// If the graph can be bipartite, print "YES", otherwise "NO" (그래프가 이분 그래프일 경우 "YES" 출력, 그렇지 않으면 "NO" 출력)
		if (search()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}
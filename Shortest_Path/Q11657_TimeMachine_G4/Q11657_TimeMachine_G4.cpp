/*
commented by ChatGPT
This C++ code implements the Bellman-Ford algorithm to find the shortest paths from a single source to all other vertices in a graph that may contain edges with negative weights.
It can also detect negative cycles in the graph. The Bellman-Ford algorithm is particularly useful in routing protocols where the cost between nodes can change dynamically and can be negative.
This implementation initializes distances from the source to all vertices as infinite and updates them iteratively based on the edges of the graph.
이 C++ 코드는 음수 가중치를 가진 간선이 포함된 그래프에서 단일 출발점에서 모든 다른 정점까지의 최단 경로를 찾기 위해 Bellman-Ford 알고리즘을 구현합니다.
또한 그래프에서 음수 사이클을 감지할 수 있습니다. Bellman-Ford 알고리즘은 노드 간의 비용이 동적으로 변경될 수 있고 음수일 수 있는 라우팅 프로토콜에서 특히 유용합니다.
이 구현은 출발점에서 모든 정점까지의 거리를 무한대로 초기화하고 그래프의 간선을 기반으로 반복적으로 업데이트합니다.
*/

#include <iostream>
#include <vector>
#include <climits> // For using LLONG_MAX which represents the maximum value for a long long int

using namespace std;

class edge {
public:
	int s; // Start vertex of the edge
	int e; // End vertex of the edge
	int w; // Weight of the edge

	// Constructor to initialize an edge with start vertex 's', end vertex 'e', and weight 'w'
	edge(int s, int e, int w) {
		this->s = s;
		this->e = e;
		this->w = w;
	}
};

long long dist[6001]; // Array to store the shortest distance from the source to each vertex
vector<edge> list; // Vector to store all edges of the graph
int N, M; // N is the number of vertices, M is the number of edges

bool bellman() {
	// Iterates N times over all edges to find the shortest path
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			edge e = list[j];
			if (dist[e.s] == LLONG_MAX) // If the starting vertex has not been reached yet, skip
				continue;
			else {
				// Relaxation step: if the current distance to the end vertex can be reduced, update it
				if (dist[e.s] + e.w < dist[e.e]) {
					if (i == N) // If we can relax an edge in the Nth iteration, a negative cycle exists
						return false;
					dist[e.e] = dist[e.s] + e.w;
				}
			}
		}
	}

	return true; // Returns true if no negative cycle is detected
}

int main() {
	cin >> N >> M;

	fill(dist, dist + N + 1, LLONG_MAX); // Initializes all distances to infinity
	dist[1] = 0; // Distance to the source itself is zero

	// Reading edges from input and adding them to the list
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		list.push_back(edge(s, e, w));
	}

	// Run Bellman-Ford algorithm
	if (!bellman())
		cout << "-1"; // If a negative cycle is detected, print -1
	else {
		// Print the shortest distance to all vertices from the source
		for (int i = 2; i <= N; i++) {
			if (dist[i] == LLONG_MAX)
				cout << "-1\n"; // If a vertex is unreachable, print -1
			else
				cout << dist[i] << "\n"; // Otherwise, print the shortest distance
		}
	}
}
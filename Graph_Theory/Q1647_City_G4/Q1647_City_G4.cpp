/*
commented by ChatGPT
This C++ code is an implementation of Kruskal's algorithm to construct a Minimum Spanning Tree (MST) for a given graph, and then calculates the total cost of the MST excluding the cost of the most expensive edge.
The graph is represented by its edges, where each edge connects two nodes (s and e) and has an associated cost.
The edges are stored in a priority queue with a custom comparator to ensure they are processed in ascending order of cost.
The Union-Find data structure is utilized to detect cycles and ensure the MST remains acyclic.
After constructing the MST and identifying the most expensive edge included in it, the code outputs the total cost of the MST minus the cost of this edge, effectively finding a nearly minimal way to connect all nodes with one less constraint.

이 C++ 코드는 주어진 그래프에 대한 최소 신장 트리(MST)를 구성하기 위한 크루스칼 알고리즘의 구현이며, 가장 비싼 간선의 비용을 제외한 MST의 총 비용을 계산합니다.
그래프는 각 간선으로 표현되며, 각 간선은 두 노드(s 및 e)를 연결하고 연관된 비용이 있습니다. 간선들은 비용의 오름차순으로 처리되도록 사용자 정의 비교자를 사용하여 우선순위 큐에 저장됩니다.
Union-Find 자료 구조는 사이클을 감지하고 MST가 비순환적임을 보장하기 위해 사용됩니다.
MST를 구성하고 그 안에 포함된 가장 비싼 간선을 식별한 후, 코드는 이 간선의 비용을 뺀 MST의 총 비용을 출력하여, 하나 덜 제약 조건으로 모든 노드를 거의 최소한으로 연결하는 방법을 찾습니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int parent[100001]; // Parent array for Union-Find

class node { // Class to represent an edge

public:
	int s, e, cost; // Start node, end node, and cost of the edge

	node(int s, int e, int cost) { // Constructor
		this->s = s;
		this->e = e;
		this->cost = cost;
	}
};

int getpar(int n) { // Find function for Union-Find

	if (n == parent[n]) // If node is its own parent
		return parent[n];
	else { // Path compression
		parent[n] = getpar(parent[n]); // Find and set the ultimate parent
		return parent[n]; // Return the ultimate parent
	}
}

int main() {
	auto comp = [](const node& a, const node& b) {
		return a.cost > b.cost; // Comparator for priority queue to sort edges by ascending cost
	};
	std::priority_queue<node, vector<node>, decltype(comp)> pq(comp); // Priority queue for edges
	int N, M; // Number of nodes and edges
	int sum = 0; // Total cost of MST
	int maxcost = 0; // Cost of the most expensive edge in the MST

	cin >> N >> M; // Input number of nodes and edges

	for (int i = 1; i <= N; i++) // Initialize parent array
		parent[i] = i;

	for (int i = 0; i < M; i++) { // Input edges
		int s, e, cost;
		cin >> s >> e >> cost;
		pq.push(node(s, e, cost)); // Add edge to priority queue
	}

	while (!pq.empty()) { // Process edges in ascending order of cost
		node cur = pq.top(); // Get the cheapest edge
		pq.pop();
		if (getpar(cur.s) == getpar(cur.e)) // Skip if adding this edge creates a cycle
			continue;

		parent[getpar(cur.e)] = parent[cur.s]; // Union operation
		sum += cur.cost; // Add edge cost to total
		maxcost = cur.cost; // Update most expensive edge

	}

	cout << sum - maxcost; // Output total cost of MST excluding the most expensive edge
}

/*
commented by ChatGPT
This C++ code calculates the diameter of a tree (the longest path between any two nodes in the tree).
It uses a two-step DFS (Depth-First Search) process. The node class represents each node, storing its children and the distances to these children.
In the first step of DFS, the code finds the farthest node (edge) from an arbitrary starting node.
In the second step, it calculates the farthest distance from this edge node, determining the tree's diameter. The visited array is used to track visited nodes during DFS to avoid revisiting them.

이 C++ 코드는 트리의 지름(트리 내 임의의 두 노드 간 가장 긴 경로)을 계산합니다. 두 단계의 DFS(깊이 우선 탐색) 접근 방식을 사용합니다.
node 클래스는 각 노드를 표현하며, 자식 노드들과 그 자식들까지의 거리를 저장합니다. DFS의 첫 번째 단계에서 코드는 임의의 시작 노드로부터 가장 먼 노드(edge)를 찾습니다.
두 번째 단계에서는 이 edge 노드로부터 가장 먼 거리를 계산하여 트리의 지름을 결정합니다. visited 배열은 DFS 동안 노드의 방문 여부를 추적하여 재방문을 방지하는 데 사용됩니다.
*/

#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	vector<int> child; // 자식 노드들을 저장하는 벡터
	vector<int> dist; // 각 자식 노드까지의 거리를 저장하는 벡터

	node() {
	}
};

int n; // 트리의 노드 수
node nodes[100001]; // 노드 배열
bool visited[100001]; // 방문 여부를 추적하는 배열
int edge = 0; // 가장 먼 노드 인덱스
int res = 0; // 최대 거리 (트리의 지름)

// 깊이 우선 탐색을 통한 최대 거리 계산 함수
void dfs(int idx, int len) {
	// 현재 거리가 최대 거리보다 길면 갱신
	if (len > res) {
		res = len;
		edge = idx;
	}

	// 모든 자식 노드에 대해 탐색
	for (int i = 0; i < nodes[idx].child.size(); i++) {
		if (visited[nodes[idx].child[i]])
			continue;
		visited[nodes[idx].child[i]] = true;
		dfs(nodes[idx].child[i], len + nodes[idx].dist[i]);
		visited[nodes[idx].child[i]] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int in, in2, in3;

	cin >> n;
	fill(visited, visited + n + 1, false); // 방문 배열 초기화

	// 트리 구성
	for (int i = 0; i < n; i++) {
		cin >> in;
		while (true) {
			cin >> in2;
			if (in2 == -1) break;
			cin >> in3;
			nodes[in].child.push_back(in2);
			nodes[in].dist.push_back(in3);
		}
	}

	// 첫 번째 DFS 실행
	visited[1] = true;
	dfs(1, 0);
	visited[1] = false;

	// 두 번째 DFS 실행
	visited[edge] = true;
	dfs(edge, 0);

	cout << res; // 결과 출력
}
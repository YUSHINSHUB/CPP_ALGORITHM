
/*
commented by ChatGPT
This C++ code calculates the maximum path length between any two nodes in a tree.
It uses a Depth-First Search (DFS) approach, implemented in the dfs function, to find the maximum distance from each node to its furthest descendant.
The node class stores the children of each node and the distances to these children.
The code iterates through each node, calculates the two longest paths emanating from it, and updates the maximum path length found so far.
The mem array is used for memoization to optimize the DFS calls.

이 C++ 코드는 트리 내의 임의의 두 노드 간의 최대 경로 길이를 계산합니다. 깊이 우선 탐색(DFS) 접근 방식을 사용하며, 이는 dfs 함수에서 구현됩니다.
node 클래스는 각 노드의 자식과 이들 자식까지의 거리를 저장합니다. 코드는 각 노드를 순회하며 해당 노드에서 발산하는 두 가장 긴 경로를 계산하고, 지금까지 발견된 최대 경로 길이를 갱신합니다.
mem 배열은 DFS 호출을 최적화하기 위해 메모이제이션에 사용됩니다.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class node {
public:
	vector<int> child; // 자식 노드들을 저장하는 벡터
	vector<int> dist; // 각 자식 노드까지의 거리를 저장하는 벡터

	node() {
	}
};

int n; // 트리의 노드 수
node nodes[10001]; // 노드 배열
int mem[10001]; // 메모이제이션을 위한 배열

// 깊이 우선 탐색을 통한 최대 거리 계산 함수
int dfs(int idx) {
	// 이미 계산된 값이 있으면 반환
	if (mem[idx] >= 0)
		return mem[idx];

	// 모든 자식 노드에 대해 최대 거리 계산
	for (int i = 0; i < nodes[idx].child.size(); i++) {
		mem[idx] = max(mem[idx], dfs(nodes[idx].child[i]) + nodes[idx].dist[i]);
	}

	// 자식 노드가 없는 경우 0으로 설정
	if (mem[idx] < 0)
		mem[idx] = 0;
	return mem[idx];
}

int main() {
	int in1, in2, in3;
	int f, s, temp; // f: 첫 번째로 긴 경로, s: 두 번째로 긴 경로
	int res = 0; // 최대 경로 길이

	cin >> n;
	fill(mem, mem + n + 1, -1); // 메모이제이션 배열 초기화

	// 트리 구성
	for (int i = 0; i < n - 1; i++) {
		cin >> in1 >> in2 >> in3;
		nodes[in1].child.push_back(in2);
		nodes[in1].dist.push_back(in3);
	}

	// 각 노드에서 두 가장 긴 경로를 찾아 합산
	for (int i = 1; i <= n; i++) {
		f = 0;
		s = 0;
		for (int j = 0; j < nodes[i].child.size(); j++) {
			temp = nodes[i].dist[j] + dfs(nodes[i].child[j]);
			if (f < temp) {
				s = f;
				f = temp;
			}
			else if (s < temp)
				s = temp;
		}
		res = max(res, f + s); // 두 경로를 합산하여 최대값 갱신
	}
	cout << res;
}
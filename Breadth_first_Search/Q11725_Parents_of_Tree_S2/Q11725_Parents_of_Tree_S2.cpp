/*
commented by ChatGPT
This C++ program constructs a parent array for a tree rooted at node 1.
It uses a breadth-first search (BFS) approach to traverse the tree and assign parent nodes to each node.
The result is then printed, showing the parent of each node in the tree.
이 C++ 프로그램은 루트 노드가 1인 트리에 대한 부모 배열을 구성합니다.
너비 우선 탐색 (BFS) 방식을 사용하여 트리를 탐색하고 각 노드에 부모 노드를 할당합니다.
그 결과는 각 노드의 부모를 나타내며 출력됩니다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

	int N;
	int a, b;
	int res[100001] = { 0, };
	queue<int> q;
	vector<vector<int>> list(100001);

	cin >> N;
	q.push(1);

	// Constructing the tree using input edges (입력된 간선을 사용하여 트리 구성)
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}

	// Performing BFS to assign parent nodes (부모 노드를 할당하기 위한 BFS 수행)
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (int i = 0; i < list[idx].size(); i++) {
			if (res[list[idx][i]] == 0) {
				res[list[idx][i]] = idx;
				q.push(list[idx][i]);
			}
		}
	}

	// Printing the result, showing the parent of each node (각 노드의 부모를 나타내는 결과 출력)
	for (int i = 2; i <= N; i++)
		cout << res[i] << "\n";

}


/*
commented by ChatGPT
This C++ code implements a solution to find the minimum degree of kinship (shortest path) between two individuals in a family tree.
It uses a Breadth-First Search (BFS) approach to traverse the family tree.
The family tree is represented using a vector of vectors (fam), storing connections between family members, and an array (parent) for direct parent-child relationships.
The search function performs BFS starting from one individual (a) and seeks the shortest path to the other (b).
The mem array is used to track the minimum number of steps to reach each family member from a.
The program outputs the minimum number of steps to reach b from a, or -1 if they are not related.
이 C++ 코드는 가계도에서 두 개인 간의 최소 친족 관계(최단 경로)를 찾는 해결책을 구현합니다.
가족 트리를 순회하기 위해 너비 우선 탐색(BFS) 접근 방식을 사용합니다.
가족 트리는 벡터의 벡터(fam)를 사용하여 가족 구성원 간의 연결을 저장하고, 배열(parent)을 사용하여 직접적인 부모-자식 관계를 나타냅니다.
search 함수는 한 개인(a)에서 시작하여 BFS를 수행하고 다른 개인(b)까지의 최단 경로를 찾습니다.
mem 배열은 a에서 각 가족 구성원에 도달하기까지의 최소 단계 수를 추적하는 데 사용됩니다.
프로그램은 a에서 b까지 도달하는 데 필요한 최소 단계 수를 출력하거나, 두 사람이 관련이 없는 경우 -1을 출력합니다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mem[101]; // Array to keep track of the number of steps to each family member from 'a' (가족 구성원 'a'로부터 각 가족 구성원까지의 단계 수를 추적하는 배열)
vector<int> fam[101]; // Vector of vectors to represent the family connections (가족 연결을 나타내는 벡터의 벡터)
int parent[101]; // Array to store direct parent-child relationships (직접적인 부모-자식 관계를 저장하는 배열)
int a, b; // The two individuals between whom the kinship degree is sought (친족 관계를 찾고자 하는 두 개인)

// Function to find the shortest path using BFS (BFS를 사용하여 최단 경로를 찾는 함수)
static int search() {
	queue<int> q; // Queue for BFS (BFS를 위한 큐)
	q.push(a);
	mem[a] = 0; // Starting point (시작점)

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		// Check the parent (부모 확인)
		if (parent[cur] > 0 && mem[parent[cur]] < 0) {
			q.push(parent[cur]);
			mem[parent[cur]] = mem[cur] + 1;
			if (parent[cur] == b)
				break;
		}
		// Check other family members (다른 가족 구성원 확인)
		for (int i = 0; i < fam[cur].size(); i++) {
			if (mem[fam[cur][i]] >= 0)
				continue;
			q.push(fam[cur][i]);
			mem[fam[cur][i]] = mem[cur] + 1;
			if (fam[cur][i] == b)
				break;
		}
	}

	return mem[b]; // Return the number of steps to 'b' (가족 구성원 'b'까지의 단계 수 반환)
}

int main() {
	int n, m; // Variables for the number of family members and relationships (가족 구성원 및 관계 수를 위한 변수)

	cin >> n >> a >> b >> m; // Read the number of family members, the two individuals, and the number of relationships (가족 구성원 수, 두 개인, 관계 수 읽기)
	fill(parent, parent + n + 1, 0); // Initialize the parent array (부모 배열 초기화)
	fill(mem, mem + n + 1, -1); // Initialize the mem array (mem 배열 초기화)

	for (int i = 0; i < m; i++) { // Read and store relationships (관계 읽기 및 저장)
		int x, y;
		cin >> x >> y;
		fam[x].push_back(y);
		parent[y] = x;
	}

	cout << search(); // Output the shortest path length (최단 경로 길이 출력)
}
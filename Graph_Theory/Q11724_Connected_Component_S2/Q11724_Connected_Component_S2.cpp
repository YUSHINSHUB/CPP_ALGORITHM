// Commented by ChatGPT
// This C++ program reads a graph as input and calculates the number of connected components in the graph using a DFS algorithm. The graph is represented using an adjacency list.

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// Create an array of vectors to represent the adjacency list of the graph
vector<int> a[1001];
// Create an array to track whether a node is visited or not
bool check[1001];

// DFS algorithm to traverse the connected component starting from the node
void dfs(int node) {
	// Mark the node as visited
	check[node] = true;
	// Loop through the adjacency list of the node
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		// If the adjacent node is not visited, traverse it
		if (check[next] == false) {
			dfs(next);
		}
	}

}

int main() {
	int n, m;
	// Read the number of nodes and edges
	scanf("%d %d", &n, &m);
	// Loop to read edges of the graph
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		// Add the edges to the adjacency list
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int ans = 0;

	// Loop through all the nodes
	for (int i = 1; i <= n; i++) {
		// If the node is not visited
		if (check[i] == false) {
			// Traverse the connected component starting from the node
			dfs(i);
			// Increase the counter of connected components
			ans += 1;
		}

	}
	// Print the number of connected components
	printf("%d\n", ans);
	return 0;
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

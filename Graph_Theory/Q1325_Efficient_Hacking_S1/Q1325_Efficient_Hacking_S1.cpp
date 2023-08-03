// Q1325_Efficient_Hacking_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> visited; // Array to keep track of visited nodes during BFS
static int cur = 0; // Variable to count the number of nodes visited during a BFS
vector<vector<int>> node; // Adjacency list to represent the graph

void bfs(int idx) { // Function to perform a BFS starting from node idx

	queue<int> q; // Queue to manage the BFS
	q.push(idx); // Adding the starting node to the queue
	cur++; // Incrementing the count of nodes visited
	visited[idx] = 1; // Marking the starting node as visited

	while (!q.empty()) { // While there are still nodes to visit in the queue
		int n = q.front(); // Remove the node from the queue
		q.pop();
		for (int temp : node[n]) { // Go through all the adjacent nodes
			if (visited[temp] == 0) { // If the node has not been visited
				q.push(temp); // Add it to the queue
				visited[temp] = 1; // Mark it as visited
				cur++; // Increment the count of nodes visited
			}
		}
	}
}


int main()
{
	int n; // Number of nodes
	int m; // Number of edges
	cin >> n >> m;
	int hig = 0; // Initialize maximum reachable nodes
	vector<int> scr(n + 1); // Array to store the number of reachable nodes for each node
	node = vector<vector<int>>(n+1);
	visited = vector<int>(n+1);
	int a, b;

	for (int i = 0; i < m; i++) { // Read edges
		cin >> a >> b;
		node[b].push_back(a); // Add 'a' to the list of nodes reachable from 'b'
	}

	for (int i = 1; i <= n; i++) { // For each node
		fill(visited.begin(), visited.end(), 0); // Reset visited array
		cur = 0; // Reset count of nodes visited
		bfs(i); // Perform BFS from node i
		scr[i] = cur; // Store the number of reachable nodes from node i
		if (cur > hig) // If this number is greater than the current maximum
			hig = cur; // Update the maximum
	}

	string res = "";
	for (int i = 1; i <= n; i++) { // For each node
		if (scr[i] == hig) // If the number of reachable nodes from this node is equal to the maximum
			res += to_string(i) + " "; // Add the node to the result
	}

	cout << res; // Write the result
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

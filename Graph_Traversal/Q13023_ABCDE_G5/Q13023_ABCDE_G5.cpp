/*
commented by ChatGPT
This C++ code implements a Depth-First Search (DFS) algorithm to solve a problem that involves finding a specific connection pattern among a group of people. The goal is to determine if there exists a sequence of five people where each person is directly connected to the next one. The program constructs a network of connections and then uses DFS to explore these connections. It uses a boolean array mem to track which people have been visited during the DFS to avoid revisiting the same person. If a chain of five connected people is found, the res flag is set to true, indicating the pattern exists.
이 C++ 코드는 사람들 그룹 중 특정 연결 패턴을 찾기 위한 깊이 우선 탐색(DFS) 알고리즘을 구현합니다. 목표는 각 사람이 다음 사람과 직접 연결된 5명의 사람 시퀀스가 존재하는지 여부를 결정하는 것입니다. 프로그램은 연결 네트워크를 구성한 다음 DFS를 사용하여 이러한 연결을 탐색합니다. 불리언 배열 mem을 사용하여 DFS 동안 방문한 사람들을 추적하여 동일한 사람을 재방문하지 않습니다. 연결된 5명의 사람 체인이 발견되면 res 플래그는 패턴이 존재한다는 것을 나타내는 true로 설정됩니다.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> peo[2000]; // Array of vectors to store connections between people (사람들 간의 연결을 저장하는 벡터의 배열)
bool mem[2000]; // Boolean array to track visited people (방문한 사람들을 추적하는 불리언 배열)
bool res = false; // Boolean flag to indicate if the required pattern is found (필요한 패턴이 발견되었는지 나타내는 불리언 플래그)

// Depth-first search function to explore connections (연결을 탐색하는 깊이 우선 탐색 함수)
static void dfs(int cur, int idx) {
	if (idx == 5) { // If a sequence of 5 connected people is found (5명의 연결된 사람 시퀀스가 발견되면)
		res = true; // Set the result flag to true (결과 플래그를 true로 설정)
		return;
	}

	for (int i = 0; i < peo[cur].size(); i++) { // Iterate over all connections of the current person (현재 사람의 모든 연결을 반복)
		if (mem[peo[cur][i]]) { // If the connected person is not yet visited (연결된 사람이 아직 방문되지 않았다면)
			mem[peo[cur][i]] = false; // Mark the person as visited (사람을 방문한 것으로 표시)
			dfs(peo[cur][i], idx + 1); // Recursively call dfs for the connected person (연결된 사람에 대해 dfs를 재귀적으로 호출)
			mem[peo[cur][i]] = true; // Reset the visited status (방문 상태를 재설정)
		}
	}
}

int main() {
	int N, M; // N: Number of people, M: Number of connections (N: 사람 수, M: 연결 수)
	int a, b; // Variables to store connections (연결을 저장하는 변수)

	cin >> N >> M; // Read the number of people and connections (사람 수와 연결 수 읽기)

	// Initialize the connection network (연결 네트워크 초기화)
	for (int i = 0; i < M; i++) {
		cin >> a >> b; // Read each connection (각 연결 읽기)
		peo[a].push_back(b); // Add the connection to both people (두 사람 모두에게 연결 추가)
		peo[b].push_back(a);
	}
	fill(mem, mem + N, true); // Initially, all people are unvisited (초기에 모든 사람은 미방문 상태임)

	// Start dfs from each person (각 사람에서 dfs 시작)
	for (int i = 0; i < N; i++) {
		mem[i] = false; // Mark the current person as visited (현재 사람을 방문한 것으로 표시)
		dfs(i, 1); // Call dfs function (dfs 함수 호출)
		mem[i] = true; // Reset the visited status (방문 상태 재설정)
		if (res) // If the required pattern is found (필요한 패턴이 발견되면)
			break; // Break the loop (루프 중단)
	}

	// Output the result (결과 출력)
	if (res)
		cout << "1";
	else
		cout << "0";
}
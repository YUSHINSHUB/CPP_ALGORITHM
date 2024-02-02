/*
commented by ChatGPT
This C++ code is designed to solve a problem where a person tries to reach a festival location from a starting point, having the ability to walk 1000 meters with a bottle of beer before needing to stop for another.
The program employs a Breadth-First Search (BFS) algorithm to explore all reachable points (convenience stores for beer refills and the festival location), marking them as visited.
The output is "happy" if the festival location is reachable under these conditions, and "sad" otherwise.
이 C++ 코드는 출발점에서 축제 장소까지 맥주 한 병으로 1000미터를 걸을 수 있는 사람이 다른 맥주를 위해 멈추기 전에 도달하려고 시도하는 문제를 해결하기 위해 설계되었습니다.
프로그램은 모든 도달 가능한 지점(맥주 리필을 위한 편의점 및 축제 장소)을 탐색하고 방문한 것으로 표시하는 너비 우선 탐색(BFS) 알고리즘을 사용합니다.
이러한 조건 하에서 축제 장소에 도달할 수 있으면 출력은 "happy"이고, 그렇지 않으면 "sad"입니다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> ylist; // Stores y-coordinates of all points including start, convenience stores, and festival
vector<int> xlist; // Stores x-coordinates of all points including start, convenience stores, and festival
bool visited[100]; // Tracks whether each point has been visited to avoid revisiting during BFS
int n; // Number of convenience stores

// BFS function to determine if the festival is reachable with the given beer walking constraint
bool  bfs(int y, int x) {
	queue<int> yq; // Queue for y-coordinates in BFS
	queue<int> xq; // Queue for x-coordinates in BFS
	yq.push(y); // Starting point y-coordinate
	xq.push(x); // Starting point x-coordinate

	while (!yq.empty()) {
		int cy = yq.front(); // Current y-coordinate from the queue
		int cx = xq.front(); // Current x-coordinate from the queue
		yq.pop(); // Remove current y-coordinate from the queue
		xq.pop(); // Remove current x-coordinate from the queue

		for (int i = 0; i <= n; i++) { // Iterate through all points
			if (visited[i]) // Skip if already visited
				continue;
			// Check if the point is within 1000 meters from the current point, simulating beer consumption limits
			if ((abs(cy - ylist[i]) + abs(cx - xlist[i])) <= 1000) {
				visited[i] = true; // Mark the point as visited
				yq.push(ylist[i]); // Add to queue for further exploration
				xq.push(xlist[i]);
			}
		}
	}

	return visited[n]; // Return true if festival location is visited
}

int main() {
	int t, y, x; // Number of test cases, starting y and x coordinates
	int in1, in2; // Input variables for coordinates
	cin >> t; // Read number of test cases

	for (int i = 0; i < t; i++) {
		ylist.clear(); // Clear list for new test case
		xlist.clear();
		cin >> n; // Read number of convenience stores
		fill(visited, visited + n + 1, false); // Reset visited array for new test case, including festival
		cin >> y >> x; // Read starting coordinates
		for (int j = 0; j <= n; j++) { // Read convenience store and festival coordinates
			cin >> in1 >> in2;
			ylist.push_back(in1);
			xlist.push_back(in2);
		}
		// Output result based on BFS
		if (bfs(y, x))
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}
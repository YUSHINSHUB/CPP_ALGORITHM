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
	node = vector<vector<int>>(n + 1);
	visited = vector<int>(n + 1);
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
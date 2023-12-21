//Commented by ChatGPT
//This program calculates the transitive closure of a directed graph using the Floyd-Warshall algorithm. 
//It reads the adjacency matrix of the graph, computes the transitive closure, and prints the resulting matrix.

#include <iostream>
using namespace std;

int main()
{
	// Read the number of vertices in the graph
	int n;
	cin >> n;
	// Create a 2D array to represent the adjacency matrix of the graph
	int grp[101][101];

	// Read and populate the adjacency matrix from the input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grp[i][j];
		}
	}

	// Compute the transitive closure using the Floyd-Warshall algorithm
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Check if there is a direct edge from vertex j to vertex i
			if (grp[j][i] == 1) {
				for (int k = 0; k < n; k++) {
					// If there is an edge from vertex i to vertex k,
					// set grp[j][k] to 1 to indicate that there is a path from vertex j to vertex k
					if (grp[i][k] == 1)
						grp[j][k] = 1;
				}
			}
		}
	}

	// Write the transitive closure matrix to the output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << grp[i][j] << " "; // Write each cell of the matrix followed by a space
		cout << "\n"; // Write a newline character to separate rows
	}
}
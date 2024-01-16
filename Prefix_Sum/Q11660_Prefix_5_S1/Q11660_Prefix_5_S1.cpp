//Commented by ChatGPT
//The problem asks for the sum of submatrix elements within a given matrix. 

#include <iostream>
#include <vector>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Take the size of matrix and number of sub-matrices as input
	int n, m;
	cin >> n >> m;

	// Define the prefix sum matrix
	vector<vector<int>> ps(n + 1, vector<int>(n + 1));
	// Fill the prefix sum matrix
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> ps[i][j];
	}

	// Initialize the first row and column of prefix sum matrix to 0
	for (int i = 0; i <= n; i++) {
		ps[0][i] = 0;
		ps[i][0] = 0;
	}

	// Compute the prefix sum
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
		}
	}

	// Handle each sub-matrix query
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// Compute the sum of elements in the sub-matrix using the prefix sum
		int res = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
		cout << res << "\n";
	}
}
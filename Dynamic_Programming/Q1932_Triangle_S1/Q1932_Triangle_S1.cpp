// //Commented by ChatGPT
//This Java program solves the problem of finding the maximum total from top to bottom in a triangle of integers.
//It employs a bottom-up dynamic programming approach, calculating the maximum sums row-by-row from the bottom of 
//the triangle.
//The program handles single-row cases separately for efficiency and outputs the maximum total to the standard 
//output.


#include <iostream>

using namespace std;

int tri[501][501];
int dp[501][501];

// Recursive function to calculate maximum sum for each row, starting from the
	// bottom
static void recur(int n) {
	// If the maximum sum for the next row is not yet calculated, calculate it first
	if (dp[n + 1][1] < 0)
		recur(n + 1);

	// For each element in the current row, calculate and store the maximum sum
	for (int i = 1; i <= n; i++) {
		// Maximum sum is the current element plus the maximum of the two possible
		// elements in the next row
		dp[n][i] = max(dp[n + 1][i], dp[n + 1][i + 1]) + tri[n][i];
	}
}

int main()
{
	int n;
	cin >> n;

	// Read the given triangle of integers
	for (int i = 1; i <= n; i++) {
		fill(dp[i], dp[i] + 501, -1); // Initialize the maximum sums as -1
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	// The maximum sums for the last row are the elements themselves
	for (int i = 1; i <= n; i++) {
		dp[n][i] = tri[n][i];
	}

	// If there is only one row, output its maximum sum
	if (n == 1)
		cout << dp[1][1];
	else {
		// Otherwise, calculate the maximum sum starting from the first row
		recur(1);
		cout << dp[1][1];
	}
}
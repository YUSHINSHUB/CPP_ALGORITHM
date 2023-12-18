// Commented by ChatGPT
// Summary: This program determines the number of ways to make up a total amount "k" using provided coin denominations.

#include <iostream>
using namespace std;

int main()
{
	// Input the number of coin denominations (n) and the target amount (k).
	int n, k;
	cin >> n >> k;

	// Array to store the values of the coin denominations.
	int coin[100];

	// DP (Dynamic Programming) array to store the number of ways to achieve a particular amount.
	int dp[10001];

	// Initialize the dp array with zeros for indices up to k.
	fill(dp, dp + k + 1, 0);

	// Base case: There is one way to achieve an amount of 0 (using no coins).
	dp[0] = 1;

	// Reading the values of coin denominations from the input.
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	// Nested loops to update the dp array values.
	// Outer loop iterates over each coin denomination.
	for (int j = 0; j < n; j++) {
		// Inner loop iterates for each value up to the target amount 'k'.
		for (int i = 1; i <= k; i++) {
			// If the current amount can be achieved using the current coin denomination:
			if (coin[j] <= i) {
				// Increment the current dp value by the value of (current amount - coin denomination).
				dp[i] += dp[i - coin[j]];
			}
		}
	}

	// Output the number of ways to achieve the target amount 'k'.
	cout << dp[k];
}
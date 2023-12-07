//Commented by ChatGPT
//Summary: This program calculates the Padovan sequence using dynamic programming with memoization and prints the nth element for each test case.


#include <iostream>
using namespace std;

// Declare an array 'visited' to keep track of whether the corresponding 'pad'
	// value has been computed.
bool visited[101];
// Declare an array 'pad' to store the computed Padovan sequence values as long
// integers.
long long pad[101];

// The 'dp' function calculates the nth element of the Padovan sequence using
// dynamic programming with memoization.
long long dp(int n) {
	// If the nth element has been computed, return the stored value.
	if (visited[n] == true) {
		return pad[n];
	}
	else {
		// Otherwise, calculate the nth element using the recurrence relation and store
		// the result in the 'pad' array.
		pad[n] = dp(n - 2) + dp(n - 3);
		visited[n] = true;
		return pad[n];
	}
}

int main()
{
	// Initialize the 'visited' array to false.
	fill(visited, visited + 101, false);
	// Read the number of test cases.
	int t;
	cin >> t;

	// Initialize the base cases of the Padovan sequence.
	pad[1] = 1;
	pad[2] = 1;
	pad[3] = 1;
	visited[1] = true;
	visited[2] = true;
	visited[3] = true;

	// Process each test case.
	for (int i = 0; i < t; i++) {
		// Read the input value 'n'.
		int n;
		cin >> n;

		// Write the nth element of the Padovan sequence to the output.
		cout << dp(n) << "\n";
	}
}
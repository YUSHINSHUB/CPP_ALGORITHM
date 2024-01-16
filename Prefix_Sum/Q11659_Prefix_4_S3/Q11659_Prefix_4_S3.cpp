//Commented by ChatGPT
//This program reads a sequence of integers and for each query, it calculates the sum of a subsequence of the sequence and prints it. 
//The program uses an optimized approach by computing the prefix sum of the entire sequence.


#include <iostream>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// Number of elements in the sequence
	int n;
	// Number of queries
	int m;

	cin >> n >> m;

	// Create an array to store the sequence of integers
	int num[100001];
	// Create an array to store the prefix sum of the sequence
	int psum[100001];
	// Initialize the prefix sum at index 0 to be 0
	psum[0] = 0;

	// Read the sequence of integers and store it in the array num
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		// Update the prefix sum array by adding the current element to the prefix sum
		// of the previous elements
		psum[i] = psum[i - 1] + num[i];
	}

	// Process each query
	for (int i = 0; i < m; i++) {
		// Read the start and end index of the subsequence
		int a, b;
		cin >> a >> b;

		// Calculate the sum of the subsequence using the prefix sum array
		cout << psum[b] - psum[a - 1] << "\n";
	}
}
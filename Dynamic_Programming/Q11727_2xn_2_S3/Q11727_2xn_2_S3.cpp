//Commented by ChatGPT
//This program calculates the nth term of a sequence using dynamic programming. 
//The program uses memoization to store previously calculated values of the sequence to avoid redundant calculations.

#include <iostream>
using namespace std;

// Create an array to store the memoized values of the sequence
int mem[1001];

// Dynamic programming function to calculate the nth term of the sequence
int dp(int a) {
	// If the value is already calculated and stored in mem[], return it
	if (mem[a] > 0)
		return mem[a];
	else {
		// Otherwise, calculate the nth term using the recurrence relation
		// The nth term is the sum of the (n-1)th term and 2 times the (n-2)th term
		// The result is stored in mem[] and returned
		mem[a] = (dp(a - 1) + (dp(a - 2) * 2)) % 10007;
		return mem[a];
	}
}

int main()
{
	// Read the value of n (term to calculate)
	int n;
	cin >> n;

	// Initialize the base cases of the sequence
	mem[0] = 1;
	mem[1] = 1;

	// Write the nth term of the sequence to the output
	cout << dp(n);
}
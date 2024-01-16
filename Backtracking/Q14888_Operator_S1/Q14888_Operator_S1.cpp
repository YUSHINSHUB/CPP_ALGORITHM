/*
Commented by ChatGPT
Summary: This program performs operations on an array of numbers.
The program reads an array of numbers and a set of operations, then uses recursion to
calculate the highest and lowest possible outcomes using the available operations.
*/

#include <iostream>
#include <climits>
using namespace std;

static int n; // Number of elements
static int num[12]; // Array of numbers
static int op[4]; // Array to hold the count of each operation
static int hig = INT_MIN; // Maximum possible result
static int low = INT_MAX; // Minimum possible result

// Recursive function to calculate the highest and lowest possible outcomes
void bt(int cur, int idx) {
	if (idx == n) { // If all numbers have been processed
		hig = max(hig, cur);
		low = min(low, cur);
	}
	else {
		for (int i = 0; i < 4; i++) { // Loop through the operations
			if (op[i] > 0) { // If operation count is greater than 0
				op[i]--; // Decrement operation count
				switch (i) { // Perform operation based on the index
				case 0:
					bt(cur + num[idx], idx + 1); // Addition
					break;
				case 1:
					bt(cur - num[idx], idx + 1); // Subtraction
					break;
				case 2:
					bt(cur * num[idx], idx + 1); // Multiplication
					break;
				case 3:
					bt(cur / num[idx], idx + 1); // Division
					break;
				}
				op[i]++; // Increment operation count
			}
		}
	}

	return;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) // Store the numbers
		cin >> num[i];

	for (int i = 0; i < 4; i++) // Store the operation counts
		cin >> op[i];

	bt(num[0], 1); // Start the recursive function

	cout << hig << "\n" << low; // Output the highest and lowest possible results

}
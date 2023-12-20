/*
Commented by ChatGPT
Summary: This program solves the Tower of Hanoi problem using recursion.
Given the number of disks (n), it calculates the minimum number of moves required to solve the problem and prints the moves step-by-step.
*/

#include <iostream>
#include <math.h>

using namespace std;

// Recursive function to solve the Tower of Hanoi problem
void hanoi(int n, int s, int m, int e) {
	if (n == 1) { // Base case: if only one disk, move it from source to destination
		cout << s << " " << e << "\n";
		return;
	}

	// Move n-1 disks from source to auxiliary peg, using destination peg as
	// auxiliary
	hanoi(n - 1, s, e, m);

	// Move the nth disk from source to destination peg
	cout << s << " " << e << "\n";

	// Move the n-1 disks from auxiliary peg to destination peg, using source peg as
	// auxiliary
	hanoi(n - 1, m, s, e);
}

int main()
{
	int n;
	cin >> n;

	// Print the minimum number of moves required to solve the problem
	cout << (int)pow(2, n) - 1 << "\n";

	// Print the moves step-by-step
	hanoi(n, 1, 2, 3);
}
// Commented by ChatGPT
// Summary: A C++ program that determines the minimum number of operations needed to convert 'n' to 'm' using the operations: adding 1, subtracting 1, or doubling the current number. It uses a dynamic programming approach.

#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

int main()
{
	// Reading input values 'n' and 'm'
	int n, m;
	cin >> n >> m;

	// If 'n' is greater than or equal to 'm', simply output their difference
	if (n >= m)
		cout << n - m;
	else {

		// Initialize an array 'search' with default high values
		int search[100002];
		fill(search, search + m + 2, INT_MAX - 1);

		// Set initial value for index 0
		search[0] = n;

		// Compute initial values for array starting from 'n'
		for (int i = n; i >= 1; i--) {
			search[i] = n - i;
			for (int j = i * 2; j <= m + 1; j *= 2) {
				// Update the value at index 'j' if it's greater than current 'i'
				if (search[j] > search[i]) search[j] = search[i];
				else break;
			}
		}

		// Update values in the 'search' array for all numbers greater than 'n' and up to 'm'
		for (int i = n + 1; i <= m; i++) {
			// If 'i' is odd, compute the minimum operations for that number
			if (i % 2 == 1)
				search[i] = min(search[i], min(search[i + 1] + 1,
					min(search[i - 1] + 1, min(search[i / 2] + 1, search[i / 2 + 1] + 1))));
			else
				// If 'i' is even, compute the minimum operations for that number
				search[i] = min(search[i],
					min(search[i + 1] + 1, min(search[i - 1] + 1, search[i / 2])));

			// Update values in the 'search' array for multiples of 'i' up to 'm'
			for (int j = i * 2; j <= m + 1; j *= 2) {
				if (search[j] > search[i]) search[j] = search[i];
				else break;
			}
		}

		// Output the minimum number of operations needed to transform 'n' to 'm'
		cout << search[m];
	}
}
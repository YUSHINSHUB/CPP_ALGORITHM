/*
Commented by ChatGPT
Summary: This program identifies and counts occurrences of a specific pattern (IO...OI) in an input
string. The number of 'O's in the pattern is specified by the input 'n'.
*/

#include <iostream>

using namespace std;

int main()
{
	int res = 0; // Stores the total number of matched patterns.
	int n; // Reading the number of 'O's in the pattern.
	cin >> n;

	int cnt = 0; // Counter variable to track the pattern.
	n *= 2;
	n++; // Incrementing n to match the number of 'I's and 'O's in the pattern.

	int m; // Reading the length of the string to be checked.
	cin >> m;

	string s; // Reading the string to be checked.
	cin >> s;

	// Looping through the string.
	for (int i = 0; i < m; i++) {
		if (cnt % 2 == 0 && s[i] == 'I') { // Checking for 'I' at even indices.
			cnt++;
			if (cnt == n) { // If the count equals n, we found a pattern.
				res++;
				cnt -= 2;
			}
		}
		else if (cnt % 2 == 1 && s[i] == 'O') { // Checking for 'O' at odd indices.
			cnt++;
		}
		else if (s[i] == 'I') {
			cnt = 1;
		}
		else {
			cnt = 0;
		}
	}

	cout << res;
}
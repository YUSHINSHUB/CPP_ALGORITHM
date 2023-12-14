/*
Commented by ChatGPT
This code is designed to simulate the formation and counting of various towns in a 2D
grid.
The code uses recursion to traverse the grid and increment the town count.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static int town[27][27];
static int cur;

// Recursion function to traverse the grid
void recur(int x, int y) {

	cur++; // Increase current position count
	town[x][y] = 0; // Visited position in town is marked as 0

	// If there's a town in the adjacent cells, recursive call is made
	if (town[x + 1][y] == 1)
		recur(x + 1, y);
	if (town[x][y + 1] == 1)
		recur(x, y + 1);
	if (town[x - 1][y] == 1)
		recur(x - 1, y);
	if (town[x][y - 1] == 1)
		recur(x, y - 1);

	return;

}

int main()
{
	int n;
	cin >> n;// Size of the grid
	int t = 0; // Total towns count
	vector<int> cnt; // List to store the number of towns

	cin.ignore();
	string in;

	// Fill the 2D grid with input values
	for (int i = 1; i <= n; i++) {
		getline(cin, in);
		for (int j = 1; j <= n; j++) {
			town[i][j] = in[j - 1] - '0';
		}
	}

	// Traversing the grid to find and count towns
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (town[i][j] == 1) { // If a town is found
				t++; // Increment town count
				cur = 0; // Reset current position count
				recur(i, j); // Call the recursion function
				cnt.push_back(cur); // Add the current town count to the list
			}
		}
	}

	// Sort the towns count list
	sort(cnt.begin(), cnt.end());

	// Write the total towns count to the output
	cout << t << "\n";

	// Write each town's count to the output
	for (int i = 0; i < t; i++)
		cout << cnt[i] << "\n";
}
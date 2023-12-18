#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<vector<int>> st(2, vector<int>(n));

		// Read the scores of the stickers in the first row
		for (int j = 0; j < n; j++) {
			cin >> st[0][j];
		}

		// Read the scores of the stickers in the second row
		for (int j = 0; j < n; j++) {
			cin >> st[1][j];
		}

		// Special case handling for the first column

		if (n > 1) {
			// The score of the second sticker in the first column is increased by the score
			// of the first sticker in the second column
			st[0][1] += st[1][0];
			// Similarly, the score of the second sticker in the second column is increased
			// by the score of the first sticker in the first column
			st[1][1] += st[0][0];
		}

		// Calculate the maximum score for each subsequent column
		for (int j = 2; j < n; j++) {
			// The maximum score of a sticker is either the sum of its score and the maximum
			// score of the sticker in the previous column of the other row,
			// or the sum of its score and the maximum score of the sticker in the second
			// previous column of the other row
			st[0][j] = max(st[1][j - 1] + st[0][j], st[1][j - 2] + st[0][j]);
			st[1][j] = max(st[0][j - 1] + st[1][j], st[0][j - 2] + st[1][j]);
		}

		// Output the maximum score
		cout << max(st[0][n - 1], st[1][n - 1]) << "\n";
	}
}
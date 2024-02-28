/*
commented by ChatGPT
This C++ code calculates the total amount of rainwater trapped between towers of varying heights on a 2D plane.
The program first reads the dimensions of the plane and the heights of the towers from the input.
It then fills a grid representing the plane with the tower heights, marking cells with towers as '1'. Next, it iterates through each row of the grid to calculate trapped rainwater by identifying enclosed spaces between towers.
The total trapped water is summed up and printed as the output.
이 C++ 코드는 2D 평면에서 다양한 높이의 탑 사이에 갇힌 총 비의 양을 계산합니다. 프로그램은 먼저 입력에서 평면의 차원과 탑의 높이를 읽습니다.
그런 다음 탑이 있는 셀을 '1'로 표시하여 평면을 나타내는 그리드를 탑 높이로 채웁니다. 다음으로, 각 행의 그리드를 반복하여 탑 사이에 둘러싸인 공간을 식별함으로써 갇힌 비를 계산합니다.
총 갇힌 물의 양이 합산되어 출력으로 인쇄됩니다.
*/

#include <iostream>

using namespace std;

int main()
{
	int res = 0; // Variable to store the total amount of trapped rainwater
	int grid[500][500]; // 2D array to represent the height grid of the towers
	int H, W; // Variables to store the height and width of the grid

	cin >> H >> W; // Reading the dimensions of the grid from input

	// Initializing the grid with zeros
	for (int i = 0; i < H; i++)
		fill(grid[i], grid[i] + W, 0);

	// Filling the grid with the heights of the towers
	for (int i = 0; i < W; i++) {
		int cur; // Variable to store the current tower height
		cin >> cur; // Reading the current tower height
		for (int j = 0; j < cur; j++) {
			grid[j][i] = 1; // Marking the cells with towers as '1'
		}
	}

	// Calculating trapped rainwater for each row
	for (int i = 0; i < H; i++) {
		int idx = 0; // Starting index for searching towers
		// Move to the first tower in the row
		while (grid[i][idx] == 0) {
			idx++;
			if (idx == W) // If no tower is found, move to the next row
				break;
		}
		int temp = 0; // Temporary variable to count trapped water between towers
		for (int j = idx + 1; j < W; j++) {
			if (grid[i][j] == 0) // Increment temporary count if no tower is found
				temp++;
			if (grid[i][j] == 1) { // If a tower is found, add the count to the result and reset temporary count
				res += temp;
				temp = 0;
			}
		}
	}

	cout << res; // Printing the total amount of trapped rainwater
}
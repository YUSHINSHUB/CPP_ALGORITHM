/*
commented by ChatGPT
This C++ code is designed to find the largest square of '1's in a binary matrix.
The program first reads the dimensions of the matrix (N rows and M columns), and then the matrix itself, line by line.
It uses dynamic programming to compute the cumulative sums of the matrix elements, facilitating the efficient calculation of the sum of sub-matrices.
The primary goal is to identify the side length of the largest square composed entirely of '1's and calculate its area.
The algorithm iteratively checks each cell that contains a '1' to determine if it can be the top-left corner of such a square, progressively checking larger squares until the maximum possible size for that starting point is found.
이 C++ 코드는 이진 행렬에서 '1'로 이루어진 가장 큰 정사각형을 찾기 위해 설계되었습니다. 프로그램은 먼저 행렬의 차원(N행 M열)을 읽고, 그 다음에 행렬 자체를 한 줄씩 읽습니다.
동적 프로그래밍을 사용하여 행렬 요소의 누적 합을 계산함으로써, 부분 행렬의 합을 효율적으로 계산할 수 있습니다.
주요 목표는 전적으로 '1'로 구성된 가장 큰 정사각형의 변 길이를 식별하고 그 면적을 계산하는 것입니다.
알고리즘은 각 셀이 '1'을 포함하고 있는지 확인하여, 그것이 해당 정사각형의 좌상단 모서리가 될 수 있는지 반복적으로 확인합니다.
시작점에 대해 가능한 최대 크기가 발검될 때까지 점차적으로 더 큰 정사각형을 확인합니다.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, M; // N: Rows, M: Columns
	int sum[1001][1001]; // Cumulative sum matrix
	int grid[1001][1001]; // Input binary matrix

	int res = 0; // To store the side length of the largest square

	cin >> N >> M;

	// Initialize the first row and column of grid and sum matrices
	fill(grid[0], grid[0] + M + 1, 0);
	fill(sum[0], sum[0] + M + 1, 0);
	for (int i = 1; i <= N; i++) {
		fill(grid[i], grid[i] + M + 1, 0);
		fill(sum[i], sum[i] + M + 1, 0);
		string in;
		cin >> in; // Read each row of the binary matrix
		for (int j = 1; j <= M; j++) {
			grid[i][j] = in[j - 1] - '0'; // Convert character to integer
		}
	}

	// Calculate cumulative sum for each cell
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + grid[i][j];
		}
	}

	// Find the largest square of '1's
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (grid[i][j] == 1) { // Start with cells that contain '1'
				int idx = 1; // Initial size of the square
				// Check for larger squares
				while (i + idx <= N && j + idx <= M &&
					sum[i + idx][j + idx] - sum[i - 1][j + idx] - sum[i + idx][j - 1] + sum[i - 1][j - 1] == (idx + 1) * (idx + 1)) {
					idx++; // Increase the size of the square
				}
				res = max(res, idx); // Update the size of the largest square found
			}
		}
	}

	cout << (res * res); // Print the area of the largest square
}
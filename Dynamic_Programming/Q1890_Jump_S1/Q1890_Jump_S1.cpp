/*
commented by ChatGPT
This C++ code implements a dynamic programming approach to solve a board game challenge.
The game is played on an N x N grid, with each cell containing a number that represents the maximum steps that can be moved either right or down from that cell.
The objective is to calculate the total number of ways to reach the bottom-right corner of the grid from the top-left corner.
이 C++ 코드는 보드 게임 도전을 해결하기 위한 동적 프로그래밍 접근 방식을 구현합니다.
이 게임은 N x N 그리드에서 진행되며, 각 셀에는 해당 셀에서 오른쪽이나 아래로 이동할 수 있는 최대 스텝 수가 표시됩니다.
목표는 그리드의 왼쪽 상단 모서리에서 오른쪽 하단 모서리까지 도달할 수 있는 총 방법 수를 계산하는 것입니다.
*/

#include <iostream>
using namespace std;

int N; // Size of the board
int board[100][100]; // 2D array representing the board
long long mem[100][100]; // 2D array for memoization to store number of ways to reach each cell

// Recursive function for dynamic programming
long long dp(int y, int x) {

	// If the value is already computed, return it
	if (mem[y][x] >= 0)
		return mem[y][x];
	// Base case: if current cell value is 0, no way to move forward
	else if (board[y][x] == 0) {
		mem[y][x] = 0;
		return 0;
	}
	// If moving right or down goes out of the board, set ways to 0
	else if (y + board[y][x] >= N && x + board[y][x] >= N)
		mem[y][x] = 0;
	// If moving down goes out of the board, only move right
	else if (y + board[y][x] >= N)
		mem[y][x] = dp(y, x + board[y][x]);
	// If moving right goes out of the board, only move down
	else if (x + board[y][x] >= N)
		mem[y][x] = dp(y + board[y][x], x);
	// Otherwise, sum up ways of moving right and down
	else
		mem[y][x] = dp(y, x + board[y][x]) + dp(y + board[y][x], x);

	return mem[y][x]; // Return the computed number of ways for the current cell
}

int main()
{
	cin >> N; // Reading the size of the board
	for (int i = 0; i < N; i++) {
		fill(mem[i], mem[i] + N, -1); // Initializing memoization array with -1 to indicate uncomputed cells
		for (int j = 0; j < N; j++)
			cin >> board[i][j]; // Filling the board with input values
	}
	mem[N - 1][N - 1] = 1; // Base case: There is 1 way to be at the bottom-right cell

	cout << dp(0, 0); // Outputting the total number of ways to reach bottom-right cell from top-left
}
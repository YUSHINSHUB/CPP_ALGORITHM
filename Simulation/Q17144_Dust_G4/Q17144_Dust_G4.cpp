/*
commented by ChatGPT
This C++ code simulates an air purifying process in a room represented by a 2D array.
The program is designed to diffuse particles in the air, then circulate the air through two air purifiers placed in the room.
The diffusion spreads particles to adjacent cells, and the air circulation moves air vertically up or down, passing through the purifiers.
The program iteratively performs these actions for a specified number of times (T), and ultimately calculates the total amount of particles left in the room after the purification process.
This solution takes into account edge cases, such as not moving particles into the cells where the air purifiers are located (marked as -1 in the array).

이 C++ 코드는 2D 배열로 표현된 방에서 공기 정화 과정을 시뮬레이션합니다.
프로그램은 공기 중 입자를 확산시킨 다음, 방에 배치된 두 개의 공기 정화기를 통해 공기를 순환시키도록 설계되었습니다.
확산은 입자를 인접 셀로 퍼뜨리며, 공기 순환은 공기를 상하로 움직여 정화기를 통과시킵니다.
프로그램은 지정된 횟수(T) 동안 이러한 작업을 반복적으로 수행하고, 정화 과정 후 방에 남아 있는 입자의 총량을 계산합니다.
이 솔루션은 공기 정화기가 위치한 셀(배열에서 -1로 표시됨)로 입자를 이동시키지 않는 등의 경계 케이스를 고려합니다.
*/

#include <iostream>
using namespace std;

int R, C, T; // Room dimensions (R x C) and number of cycles (T)
int grid[50][50]; // 2D grid representing the room
int temp[50][50]; // Temporary grid for processing
int up = -1; // Row index of the upper air purifier
int down = -1; // Row index of the lower air purifier
int ny[] = { 1, -1, 0, -1 }; // Y-axis movement for diffusion
int nx[] = { 0, -1, 2, -1 }; // X-axis movement for diffusion

// Function to simulate the diffusion of particles
void diffusion() {
	for (int i = 0; i < R; i++)
		fill(temp[i], temp[i] + C, 0); // Reset temporary grid
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] >= 5) { // Only cells with 5 or more particles diffuse
				int y = i;
				int x = j;
				for (int k = 0; k < 4; k++) { // Spread to adjacent cells
					y += ny[k];
					x += nx[k];
					if (y < 0 || x < 0 || y >= R || x >= C)
						continue; // Skip invalid cells
					else if (grid[y][x] == -1)
						continue; // Skip air purifier cells
					temp[y][x] += grid[i][j] / 5; // Add particles to adjacent cell
					temp[i][j] -= grid[i][j] / 5; // Remove particles from original cell
				}
			}
		}
	}
	// Update grid with diffusion results
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			grid[i][j] += temp[i][j];
		}
	}
}

// Function to simulate air circulation through the upper air purifier
void circ_up() {
	for (int i = 0; i < R; i++)
		fill(temp[i], temp[i] + C, 0); // Reset temporary grid

	// Move air along the predefined path
	for (int i = 2; i < C; i++) {
		temp[up][i] = grid[up][i - 1];
	}
	for (int i = up - 1; i >= 0; i--) {
		temp[i][C - 1] = grid[i + 1][C - 1];
	}
	for (int i = C - 2; i >= 0; i--) {
		temp[0][i] = grid[0][i + 1];
	}
	for (int i = 1; i < up; i++) {
		temp[i][0] = grid[i - 1][0];
	}
	temp[up][0] = -1; // Preserve air purifier

	// Update grid with circulation results
	for (int i = 0; i < C; i++) {
		grid[0][i] = temp[0][i];
		grid[up][i] = temp[up][i];
	}
	for (int i = 0; i <= up; i++) {
		grid[i][0] = temp[i][0];
		grid[i][C - 1] = temp[i][C - 1];
	}
}

// Function to simulate air circulation through the lower air purifier
void circ_down() {
	for (int i = 0; i < R; i++)
		fill(temp[i], temp[i] + C, 0); // Reset temporary grid

	// Move air along the predefined path
	for (int i = 2; i < C; i++) {
		temp[down][i] = grid[down][i - 1];
	}
	for (int i = down + 1; i < R; i++) {
		temp[i][C - 1] = grid[i - 1][C - 1];
	}
	for (int i = C - 2; i >= 0; i--) {
		temp[R - 1][i] = grid[R - 1][i + 1];
	}
	for (int i = R - 2; i > down; i--) {
		temp[i][0] = grid[i + 1][0];
	}
	temp[down][0] = -1; // Preserve air purifier

	// Update grid with circulation results
	for (int i = 0; i < C; i++) {
		grid[R - 1][i] = temp[R - 1][i];
		grid[down][i] = temp[down][i];
	}
	for (int i = down; i < R; i++) {
		grid[i][0] = temp[i][0];
		grid[i][C - 1] = temp[i][C - 1];
	}
}

// Function to execute the air purification process and return total particles
int execute() {
	int res = 0; // Resultant total particles
	for (int i = 0; i < T; i++) {
		diffusion(); // Diffuse particles
		circ_up(); // Circulate air upward
		circ_down(); // Circulate air downward
	}
	// Calculate remaining particles
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] > 0)
				res += grid[i][j];
		}
	}
	return res; // Return total particles
}

int main() {
	ios_base::sync_with_stdio(0); // Optimize C++ I/O operations
	cin.tie(0);
	cout.tie(0);

	// Read room dimensions and cycles
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == -1 && up == -1)
				up = i; // Identify upper purifier
			else if (grid[i][j] == -1)
				down = i; // Identify lower purifier
		}
	}

	// Execute purification and output result
	cout << execute();
}
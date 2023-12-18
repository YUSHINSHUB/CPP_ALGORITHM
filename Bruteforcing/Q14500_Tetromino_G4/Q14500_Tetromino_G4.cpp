/*
commented by ChatGPT
이 C++ 코드는 주어진 n x m 크기의 2D 배열에서 4개의 연속된 원소로 구성된 테트로미노의 최대 합을 찾습니다.
This C++ code finds the maximum sum of a tetromino, composed of four consecutive elements, in a given n x m 2D array.
*/

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m; // 사용자로부터 2D 배열의 크기를 입력받습니다. (Reads the dimensions of the 2D array from the user.)
	int res = 0;
	int grp[501][501];
	int ver6[3][2]; // 세로 방향 테트로미노를 저장하기 위한 배열 (Array for storing vertical tetrominoes)
	int hor6[2][3]; // 가로 방향 테트로미노를 저장하기 위한 배열 (Array for storing horizontal tetrominoes)

	// 2D 배열의 각 원소 값을 사용자로부터 입력받습니다.
	// Reads each element value of the 2D array from the user.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grp[i][j];
		}
	}

	// 각 테트로미노의 모양에 따라 배열에서 4개의 연속된 원소의 합을 계산합니다.
	// Calculates the sum of four consecutive elements in the array based on each tetromino shape.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 세로 4개 연속 원소의 합
			// Sum of 4 consecutive elements in vertical direction
			if (i >= 3) {
				res = max(res, grp[i][j] + grp[i - 1][j] + grp[i - 2][j] + grp[i - 3][j]);
			}

			// 가로 4개 연속 원소의 합
			// Sum of 4 consecutive elements in horizontal direction
			if (j >= 3) {
				res = max(res, grp[i][j] + grp[i][j - 1] + grp[i][j - 2] + grp[i][j - 3]);
			}

			// 사각형 테트로미노의 합
			// Sum of square tetromino
			if (i >= 1 && j >= 1) {
				res = max(res, grp[i][j] + grp[i - 1][j] + grp[i][j - 1] + grp[i - 1][j - 1]);
			}

			// L, J, T 모양 테트로미노의 합을 계산 (세로)
			// Calculate the sum for L, J, T shaped tetrominoes (Vertical)
			if (i >= 2 && j >= 1) {
				int ver = 0;
				for (int k = i; k >= i - 2; k--) {
					for (int l = j; l >= j - 1; l--) {
						ver += grp[k][l];
						ver6[i - k][j - l] = grp[k][l];
					}
				}
				// 각 모양에 따른 최대값 계산
				// Compute max value for each shape
				res = max(res, ver - ver6[0][1] - ver6[1][1]);
				res = max(res, ver - ver6[1][1] - ver6[2][1]);
				res = max(res, ver - ver6[0][0] - ver6[1][0]);
				res = max(res, ver - ver6[1][0] - ver6[2][0]);
				res = max(res, ver - ver6[0][0] - ver6[2][1]);
				res = max(res, ver - ver6[2][0] - ver6[0][1]);
				res = max(res, ver - ver6[0][0] - ver6[2][0]);
				res = max(res, ver - ver6[0][1] - ver6[2][1]);
			}

			// L, J, T 모양 테트로미노의 합을 계산 (가로)
			// Calculate the sum for L, J, T shaped tetrominoes (Horizontal)
			if (j >= 2 && i >= 1) {
				int hor = 0;
				for (int k = i; k >= i - 1; k--) {
					for (int l = j; l >= j - 2; l--) {
						hor += grp[k][l];
						hor6[i - k][j - l] = grp[k][l];
					}
				}
				// 각 모양에 따른 최대값 계산
				// Compute max value for each shape
				res = max(res, hor - hor6[1][0] - hor6[1][1]);
				res = max(res, hor - hor6[1][1] - hor6[1][2]);
				res = max(res, hor - hor6[0][0] - hor6[0][1]);
				res = max(res, hor - hor6[0][1] - hor6[0][2]);
				res = max(res, hor - hor6[0][0] - hor6[1][2]);
				res = max(res, hor - hor6[0][2] - hor6[1][0]);
				res = max(res, hor - hor6[0][0] - hor6[0][2]);
				res = max(res, hor - hor6[1][0] - hor6[1][2]);
			}
		}
	}

	// 계산된 테트로미노의 최대 합을 출력합니다.
	// Outputs the calculated maximum sum of the tetromino.
	cout << res;
}
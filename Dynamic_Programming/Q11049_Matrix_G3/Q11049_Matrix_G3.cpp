
/*
commented by ChatGPT
This C++ code is designed to solve a matrix chain multiplication problem using dynamic programming.
The program aims to find the minimum number of multiplications needed to multiply a chain of matrices. It uses a bottom-up approach to build the solution.
The matrices are represented by their dimensions stored in the array mat, and the mem array is used for memoization to store the minimum cost of multiplying matrices from i to j.

이 C++ 코드는 동적 프로그래밍을 사용하여 행렬 체인 곱셈 문제를 해결하기 위해 설계되었습니다. 프로그램은 행렬 체인을 곱하는 데 필요한 최소 곱셈 횟수를 찾는 것을 목표로 합니다.
바텀업 접근 방식을 사용하여 해결책을 구축합니다. mat 배열에 저장된 행렬의 크기로 행렬을 나타내며, mem 배열은 i부터 j까지의 행렬을 곱하는 최소 비용을 저장하기 위해 메모이제이션에 사용됩니다.
*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int mat[501]; // Array to store the dimensions of matrices
int mem[500][500]; // 2D array for memoization

// Function to compute minimum multiplications needed to multiply matrices from 'start' to 'end'
static int dp(int start, int end) {
	// Check if the value is already computed
	if (mem[start][end] < INT_MAX)
		return mem[start][end];

	// Calculate the minimum number of multiplications needed
	for (int i = start; i < end; i++) {
		mem[start][end] = min(mem[start][end],
			dp(start, i) + dp(i + 1, end) + (mat[start] * mat[i + 1] * mat[end + 1]));
	}

	return mem[start][end];
}

int main() {
	int N; // Number of matrices

	cin >> N;

	// Input matrix dimensions
	for (int i = 0; i < N; i++) {
		cin >> mat[i] >> mat[i + 1];
		fill(mem[i], mem[i] + N, INT_MAX); // Initialize memoization array
		mem[i][i] = 0; // Cost of multiplying one matrix is zero
	}

	// Output the minimum number of multiplications needed
	cout << dp(0, N - 1);

	return 0;
}






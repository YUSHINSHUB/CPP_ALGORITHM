/*
commented by ChatGPT
This C++ code implements a dynamic programming solution to compute the number of non-decreasing sequences of digits (from 0 to 9) of a specified length.
The program uses a memoization technique to store intermediate results, thereby optimizing the process of calculating the total number of valid sequences.
이 C++ 코드는 지정된 길이의 숫자(0부터 9까지)의 비감소 수열의 수를 계산하기 위한 동적 프로그래밍 솔루션을 구현합니다.
프로그램은 중간 결과를 저장하기 위한 메모이제이션 기술을 사용하여 유효한 수열의 총 수를 계산하는 과정을 최적화합니다.
*/

#include <iostream>

using namespace std;

int N; // Length of the sequence to be formed
int res = 0; // Variable to store the final result
long long mem[1002][10]; // 2D array for memoization to store results for subproblems

// Recursive function for dynamic programming
static long long dp(int idx, int start) {

	// If the value is already computed, return it
	if (mem[idx][start] > 0) {
		return mem[idx][start];
	}

	mem[idx][start] = 0; // Initialize the memoization value
	// Iterate over all possible starting digits for the sequence
	for (int i = start; i <= 9; i++) {
		mem[idx][start] += dp(idx - 1, i); // Add the number of sequences of length idx-1 starting with digit i
		mem[idx][start] %= 10007; // Take modulo to avoid overflow
	}

	return mem[idx][start]; // Return the computed value
}

int main()
{
	cin >> N; // Read the length of the sequence

	// Initialize base case for sequences of length 1
	for (int i = 0; i <= 9; i++) {
		mem[1][i] = 1;
	}
	// Fill remaining memoization array with -1 to indicate uncomputed values
	for (int i = 2; i <= N + 1; i++)
		fill(mem[i], mem[i] + 10, -1);

	cout << dp(N + 1, 0); // Output the result of the number of sequences of length N
}
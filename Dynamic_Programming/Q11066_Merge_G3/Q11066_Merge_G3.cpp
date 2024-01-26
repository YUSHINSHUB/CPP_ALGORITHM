/*
commented by ChatGPT
This C++ code solves the problem of finding the minimum cost to concatenate a sequence of chapters into one book. It employs dynamic programming for efficient computation.
The chapter array stores the number of pages in each chapter. The mem 2D array is used for memoization to avoid redundant calculations.
The function dp computes the minimum cost to concatenate chapters between indices start and end.
It iteratively calculates the total number of pages and uses recursion to find the optimal concatenation cost, storing intermediate results in mem.

이 C++ 코드는 여러 챕터를 하나의 책으로 합치는 최소 비용을 찾는 문제를 해결합니다. 효율적인 계산을 위해 동적 프로그래밍을 사용합니다. chapter 배열은 각 챕터의 페이지 수를 저장합니다.
mem 2차원 배열은 중복 계산을 방지하기 위한 메모이제이션에 사용됩니다. dp 함수는 인덱스 start부터 end까지의 챕터를 합치는 최소 비용을 계산합니다.
총 페이지 수를 반복적으로 계산하고, 재귀를 사용하여 최적의 합치기 비용을 찾아 mem에 중간 결과를 저장합니다.
*/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int chapter[500]; // Array to store the number of pages in each chapter
long long mem[500][500]; // 2D array for memoization

// Function to compute the minimum cost of concatenating chapters from 'start' to 'end'
long long dp(int start, int end) {
	// Check if the value is already computed
	if (mem[start][end] < LLONG_MAX)
		return mem[start][end];

	// Calculate total pages from 'start' to 'end'
	long val = 0;
	for (int i = start; i <= end; i++)
		val += chapter[i];

	// Calculate the minimum cost of concatenation
	for (int i = start; i < end; i++) {
		mem[start][end] = min(mem[start][end], dp(start, i) + dp(i + 1, end) + val);
	}

	return mem[start][end];
}

int main() {
	int T, N; // Number of test cases (T) and number of chapters (N)

	cin >> T;

	for (int cs = 0; cs < T; cs++) {

		cin >> N;

		// Input chapter pages and initialize memoization array
		for (int i = 0; i < N; i++) {
			cin >> chapter[i];
			fill(mem[i], mem[i] + N, LLONG_MAX);
		}

		// Initialize base cases for memoization
		for (int i = 0; i < N; i++) {
			mem[i][i] = 0;
			if (i > 0)
				mem[i - 1][i] = chapter[i - 1] + chapter[i];
		}
		cout << dp(0, N - 1) << "\n";

	}
}
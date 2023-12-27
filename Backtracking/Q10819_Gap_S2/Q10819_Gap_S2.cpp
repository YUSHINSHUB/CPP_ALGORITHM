
/*
commented by ChatGPT
This C++ code is designed to find the maximum sum of absolute differences between consecutive elements in a sequence.
It uses backtracking to explore all possible permutations of the sequence and calculates the sum of absolute differences for each permutation, keeping track of the maximum sum.
이 C++ 코드는 주어진 시퀀스에서 연속하는 요소들 사이의 절대 차이의 합이 최대가 되는 값을 찾기 위해 설계되었습니다.
백트래킹을 사용하여 가능한 모든 순열을 탐색하고 각 순열에 대한 절대 차이의 합을 계산하여 찾아낸 최대 합을 추적합니다.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int res = 0; // Stores the maximum sum of absolute differences (절대 차이의 최대 합을 저장)
int N; // Size of the sequence (시퀀스의 크기)
int grid[8]; // Array to store the elements of the sequence (시퀀스의 요소를 저장하는 배열)
bool visited[8]; // Tracks which elements have been used in the current permutation (현재 순열에서 사용된 요소를 추적)
vector<int> pick; // Current permutation of elements (현재 요소의 순열)

static void bt() { // Backtracking function to explore permutations (순열을 탐색하기 위한 백트래킹 함수)

	if (pick.size() == N) { // If a complete permutation is formed (완전한 순열이 형성된 경우)
		int sum = 0;
		for (int i = 1; i < N; i++)
			sum += abs(pick[i - 1] - pick[i]); // Calculate sum of absolute differences (절대 차이의 합을 계산)
		res = max(sum, res); // Update the maximum sum found (찾아낸 최대 합을 업데이트)
	}
	else {
		for (int i = 0; i < N; i++) { // Iterate through all elements (모든 요소를 순회)
			if (visited[i]) // Skip if the element is already used in this permutation (이 순열에서 이미 사용된 요소는 건너뜀)
				continue;
			visited[i] = true;
			pick.push_back(grid[i]); // Add element to the current permutation (현재 순열에 요소 추가)
			bt(); // Recurse to build the permutation further (순열을 더 구축하기 위해 재귀 호출)
			visited[i] = false; // Backtrack (백트래킹)
			pick.pop_back(); // Remove the last element added to the permutation (순열에 추가된 마지막 요소 제거)
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); // Fast I/O optimization (빠른 입출력 최적화)
	cin.tie(0); // Untie cin from cout (cin을 cout에서 분리)
	cout.tie(0); // Untie cout from cin (cout을 cin에서 분리)

	cin >> N; // Read the size of the sequence (시퀀스 크기 읽기)
	fill(visited, visited + N, false); // Initialize all elements of visited to false (visited의 모든 요소를 false로 초기화)
	for (int i = 0; i < N; i++)
		cin >> grid[i]; // Read the elements of the sequence (시퀀스 요소 읽기)
	bt(); // Start backtracking (백트래킹 시작)

	cout << res; // Output the maximum sum found (찾아낸 최대 합 출력)
}
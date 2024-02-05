/*
commented by ChatGPT
This C++ code implements a solution to find the minimum number of operations needed to reduce a given number X to 1. The allowed operations are division by 3, division by 2, or subtraction by 1.
It uses a depth-first search (DFS) approach combined with memoization to efficiently find the solution, avoiding recalculating the same states.
The sequence of operations leading to the solution is also reconstructed and printed.
이 C++ 코드는 주어진 수 X를 1로 줄이기 위해 필요한 최소 연산 횟수를 찾는 솔루션을 구현합니다. 허용되는 연산은 3으로 나누기, 2로 나누기, 또는 1을 빼기입니다.
깊이 우선 탐색(DFS) 접근 방식과 메모이제이션을 결합하여 효율적으로 솔루션을 찾으며, 동일한 상태를 재계산하는 것을 피합니다. 또한, 솔루션으로 이어지는 연산의 순서를 재구성하여 출력합니다.
*/

#include <iostream>
#include <vector>
using namespace std;

static int visited[1000001]; // Tracks the minimum steps required to reach each number
static vector<int> seq; // Stores the sequence of numbers leading to the minimal operation count
static int X; // The target number to reduce to 1

// Recursive function to calculate minimum operations using DFS and memoization
static void dp(int cur, int idx) {
	if (cur == 1) { // Base case: if current number is 1, mark the step count
		visited[1] = idx;
		return;
	}
	// Pruning: if current step count is not better or if we've already found a better solution, skip
	if (visited[cur] <= idx || idx >= visited[1])
		return;

	visited[cur] = idx; // Update the step count for the current number
	// Recursive calls for each operation, depending on divisibility
	if (cur % 6 == 0) { // Number is divisible by both 2 and 3
		dp(cur / 3, idx + 1);
		dp(cur / 2, idx + 1);
		dp(cur - 1, idx + 1);
	}
	else if (cur % 3 == 0) { // Number is divisible by 3 only
		dp(cur / 3, idx + 1);
		dp(cur - 1, idx + 1);
	}
	else if (cur % 2 == 0) { // Number is divisible by 2 only
		dp(cur / 2, idx + 1);
		dp(cur - 1, idx + 1);
	}
	else { // Number is not divisible by 2 or 3
		dp(cur - 1, idx + 1);
	}
}

// Function to trace back the sequence of operations leading to 1 from X
static void find(int cur) {
	seq.push_back(cur); // Add current number to the sequence
	if (cur == X) // If current number is the starting number, end the trace
		return;

	// Determine the preceding number in the sequence based on the operation that was performed
	if (visited[cur + 1] == visited[cur] - 1)
		find(cur + 1);
	else if (visited[cur * 2] == visited[cur] - 1)
		find(cur * 2);
	else if (visited[cur * 3] == visited[cur] - 1)
		find(cur * 3);
}


int main() {
	fill(visited, visited + 1000001, 1000001); // Initialize visited array with a large number

	cin >> X; // Input the number to be reduced
	dp(X, 0); // Start the DFS to find minimum operations

	cout << visited[1] << "\n"; // Print the minimum number of operations
	find(1); // Trace back the sequence of operations
	for (int i = seq.size() - 1; i >= 0; i--) // Print the sequence in reverse
		cout << seq[i] << " ";
}

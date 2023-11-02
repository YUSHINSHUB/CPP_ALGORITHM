/*
commented by ChatGPT
This C++ code generates all non-decreasing sequences of length M from 1 to N using backtracking.
The sequences are printed with each element separated by a space.
이 C++ 코드는 백트래킹을 사용하여 1부터 N까지의 숫자로 만들 수 있는 모든 비감소하는 길이 M의 순열을 생성합니다.
각 요소는 공백으로 구분하여 출력됩니다.
*/

#include <iostream>
#include <deque>

using namespace std;

int N; // The range of numbers to use for sequences
int M; // The length of each sequence
deque<int> out; // A deque to store and manipulate the current sequence

// Backtracking method to generate all non-decreasing sequences
static void bt(int idx, int cur) {
	if (idx == M) { // Base case: if the current sequence length is M
		for (int i = 1; i <= M; i++) { // Iterate through the sequence
			int temp = out.front(); // Get the first element of the deque
			out.pop_front(); // Remove the first element
			cout << temp << " "; // Print the element followed by a space
			out.push_back(temp); // Add the element back to the end of the deque
		}
		cout << "\n"; // After printing a sequence, insert a newline character
		return; // Return to explore other possibilities
	}

	for (int i = cur; i <= N; i++) { // Iterate from the current number to N
		out.push_back(i); // Add the current number to the end of the deque
		bt(idx + 1, i); // Recursively call bt() to add the next number, ensuring non-decreasing order
		out.pop_back(); // Remove the last element to backtrack
	}

}

int main()
{
	cin >> N >> M; // Read N and M from input
	bt(0, 1); // Start the backtracking process with index 0 and current number 1
}

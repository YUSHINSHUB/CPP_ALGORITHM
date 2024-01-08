/*
commented by ChatGPT
This C++ code is designed to find the longest increasing subsequence in an array. 
It first calculates the lengths of the longest subsequences ending at each element using dynamic programming. 
Then it backtracks from the end of the longest subsequence to construct the actual subsequence and prints both the length and the elements of this subsequence.
이 C++ 코드는 배열에서 가장 긴 증가하는 부분 수열을 찾는 것을 목적으로 합니다. 
먼저 동적 프로그래밍을 사용하여 각 요소에서 끝나는 가장 긴 부분 수열의 길이를 계산합니다. 
그 다음에 가장 긴 부분 수열의 끝에서부터 백트래킹하여 실제 부분 수열을 구성하고, 이 부분 수열의 길이와 요소들을 출력합니다.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	// Optimizing I/O in C++
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

		int N; // Size of the array
	int A[1000]; // Array to store the input sequence
	int mem[1000]; // Array to store the length of the longest subsequence ending at each index
	int hig = 1; // Variable to track the length of the longest increasing subsequence
	int end = 0; // Variable to track the end index of the longest increasing subsequence
	vector<int> list; // Vector to store the longest increasing subsequence

	// Reading the size of the array
	cin >> N;
	fill(mem, mem + N, 1); // Initializing the mem array to 1

	// Reading and processing the input sequence
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i])
				mem[i] = max(mem[i], mem[j] + 1); // Updating the mem array
		}
		if (mem[i] > hig) { // Updating hig and end if a longer subsequence is found
			hig = mem[i];
			end = i;
		}
	}

	// Printing the length of the longest increasing subsequence
	cout << hig << "\n";

	// Backtracking to find the elements of the longest increasing subsequence
	list.push_back(A[end]);
	for (int i = end; i >= 0; i--) {
		if (mem[i] == hig - 1) {
			list.push_back(A[i]);
			hig--;
		}
	}

	// Printing the elements of the longest increasing subsequence in reverse order
	for (int i = list.size() - 1; i >= 0; i--)
		cout << list[i] << " ";
}







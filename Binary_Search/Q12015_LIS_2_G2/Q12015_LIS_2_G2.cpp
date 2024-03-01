
/*
commented by ChatGPT
This C++ code calculates the length of the longest increasing subsequence (LIS) from a given sequence of integers.
The sequence length (N) is read from standard input, followed by the sequence elements.
The algorithm utilizes a dynamic array res to keep track of the minimum ending value of an increasing subsequence of each length.
By employing binary search, it efficiently updates res with new elements or replaces existing values to extend the subsequences. Finally, it outputs the length of the LIS.

이 C++ 코드는 주어진 정수 시퀀스에서 가장 긴 증가하는 부분 수열(LIS)의 길이를 계산합니다. 시퀀스 길이(N)가 표준 입력에서 읽히고, 이어서 시퀀스 요소들이 주어집니다.
알고리즘은 각 길이의 증가하는 부분 수열의 최소 끝값을 추적하기 위해 동적 배열 res를 사용합니다.
이진 검색을 활용하여 효율적으로 res에 새 요소를 추가하거나 기존 값들을 대체하여 부분 수열을 확장합니다. 마지막으로, LIS의 길이를 출력합니다.
*/

#include <iostream>

using namespace std;

int main()
{
	int N; // Variable to store the length of the input sequence
	int sequence[1000001]; // Array to store the input sequence
	int res[1000001]; // Array to store the ends of the longest increasing subsequences
	int idx = 1; // Index for the 'res' array, initialized to 1 since we always have at least one element in LIS

	cin >> N; // Reading the length of the sequence
	fill(sequence, sequence + N + 1, 0); // Initializing the sequence array

	// Reading the sequence from input
	for (int i = 0; i < N; i++)
		cin >> sequence[i];
	res[0] = sequence[0]; // Initializing the first element of 'res' array with the first element of the input sequence

	// Loop through the sequence to find LIS
	for (int i = 1; i < N; i++) {
		if (sequence[i] > res[idx - 1]) { // If current element can extend the LIS
			res[idx] = sequence[i]; // Add it to the 'res' array
			idx++; // Increase the index (length of LIS)
			continue;
		}
		// Binary search to find the position to update in 'res'
		int low = 0;
		int high = idx;
		int mid = high / 2;

		while (low < high) {
			if (res[mid] < sequence[i]) {
				low = mid + 1;
				mid = (low + high) / 2;
			}
			else {
				high = mid;
				mid = (low + high) / 2;
			}
		}
		res[low] = sequence[i]; // Update the 'res' array with the current element at the correct position
	}

	cout << idx; // Output the length of the LIS
}





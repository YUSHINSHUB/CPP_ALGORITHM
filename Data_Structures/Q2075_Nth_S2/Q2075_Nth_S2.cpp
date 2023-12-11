/*
commented by ChatGPT
This C++ code is designed to find the N-th largest element in an N x N matrix.
The elements of the matrix are read into a one-dimensional array.
After storing all the elements, the array is sorted in descending order.
The N-th largest element (at index N-1, considering zero-based indexing) is then accessed directly from the sorted array and printed to the standard output.
이 C++ 코드는 N x N 행렬에서 N번째로 큰 요소를 찾도록 설계되었습니다. 행렬의 요소들은 일차원 배열에 저장됩니다. 모든 요소들을 저장한 후, 배열은 내림차순으로 정렬됩니다. N번째로 큰 요소(0 기반 인덱싱을 고려할 때 인덱스 N-1에 위치)는 정렬된 배열에서 직접 접근되어 표준 출력으로 출력됩니다.
*/

#include <iostream>
#include <queue>
#include <algorithm> // Include algorithm header for sort function

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, temp; // N: Size of the matrix, temp: Temporary variable to store input
	int num[2250000]; // Array to store elements of the matrix

	cin >> N; // Read the size of the matrix
	// Reading all elements of the matrix into the array
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num[i * N + j]; // Read the element and store it in the array
		}
	}

	sort(num, num + N * N, greater<int>()); // Sort the array in descending order

	cout << num[N - 1]; // Output the N-th largest element (at index N-1)
}
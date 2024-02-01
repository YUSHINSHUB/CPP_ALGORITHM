
/*
commented by ChatGPT
This C++ code is designed to read a number N, followed by N integers, and then output these integers with duplicates removed, while preserving their sorted order.
It starts by reading the integer N, which represents the number of integers to follow. Then, it uses a vector to store these integers.
The vector is sorted to group any duplicates together, facilitating their removal. The code iterates over the sorted vector, printing each unique integer and skipping subsequent duplicates.
The loop is carefully controlled to avoid going out of bounds of the vector.

이 C++ 코드는 숫자 N을 읽고 이어서 N개의 정수를 읽은 후, 중복을 제거하고 정렬된 순서를 유지하여 이 정수들을 출력하도록 설계되었습니다. 코드는 시작할 때 정수 N을 읽습니다.
N은 이어서 나오는 정수의 개수를 나타냅니다. 그런 다음 벡터를 사용하여 이 정수들을 저장합니다. 벡터는 중복을 함께 그룹화하기 위해 정렬됩니다.
코드는 정렬된 벡터를 순회하면서 각 고유한 정수를 출력하고 이어지는 중복을 건너뜁니다. 벡터의 범위를 벗어나지 않도록 루프가 신중하게 제어됩니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; // Number of integers

	cin >> N; // Read the number of integers

	vector<int> list(N); // Vector to store integers

	// Read integers into the vector
	for (int i = 0; i < N; i++)
		cin >> list[i];
	sort(list.begin(), list.end()); // Sort the vector to group duplicates together

	// Iterate through the sorted vector
	for (int i = 0; i < N; i++) {
		int out = list[i]; // Current integer
		cout << out << " "; // Output the integer
		// Skip over duplicates
		while (list[i] == out) {
			i++;
			if (i == N)
				break;
		}
		if (i == N)
			break;
		i--; // Adjust index to stay within bounds
	}
}






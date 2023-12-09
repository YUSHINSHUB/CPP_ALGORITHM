
/*
commented by ChatGPT
This C++ code implements a solution to filter a set of pairs based on specific conditions across multiple test cases.
Each test case contains pairs, and the objective is to count the number of pairs where each element of the pair is not greater than the minimum elements seen so far in each dimension.
이 C++ 코드는 여러 테스트 케이스에 걸쳐 특정 조건에 따라 쌍의 집합을 필터링하는 솔루션을 구현합니다.
각 테스트 케이스에는 쌍이 포함되어 있으며, 목표는 각 차원에서 지금까지 본 최소 요소보다 크지 않은 쌍의 수를 세는 것입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class comm {
public:
	int g1, g2;

	// Constructor for the comm class, initializing two integer values g1 and g2
	comm(int g1, int g2) {
		this->g1 = g1;
		this->g2 = g2;
	}
};

int main()
{
	int T, N; // Variables for number of test cases (T) and number of pairs (N)
	int res; // Variable to store the result for each test case
	vector<comm> list; // Vector to store pairs

	cin >> T; // Reading number of test cases

	for (int tc = 0; tc < T; tc++) { // Loop through each test case
		list.clear(); // Clearing the vector for the new test case
		cin >> N; // Reading number of pairs for current test case
		res = N; // Initializing result with the total number of pairs

		for (int i = 0; i < N; i++) { // Loop to read each pair
			int a, b;
			cin >> a >> b; // Reading the two elements of the pair
			list.push_back(comm(a, b)); // Adding new pair to the vector
		}

		// Sorting the vector of pairs based on the first element of each pair
		sort(list.begin(), list.end(), [](comm o1, comm o2)-> bool {
			return o1.g1 < o2.g1;
			});

		int low = list[0].g2; // Variable to keep track of the minimum second element seen so far

		for (int i = 1; i < N; i++) { // Loop to filter pairs based on the condition
			if (low < list[i].g2) { // If current pair's second element is greater than 'low', decrement result
				res--;
			}
			else { // Otherwise, update 'low' with the current pair's second element
				low = list[i].g2;
			}
		}

		cout << res << "\n"; // Printing the result for the current test case
	}
}
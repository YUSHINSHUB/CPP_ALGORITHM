
/*
commented by ChatGPT
This C++ code constructs Segment Trees for efficiently querying the minimum and maximum values within a specified range of an array.
It utilizes the concept of Segment Trees to pre-process the array, allowing for fast range queries.
The array elements are stored in a global array arr[], and two segment trees, mintree[] and maxtree[], are built to represent the minimum and maximum values, respectively, of segments within the array.
The create_min and create_max functions construct these trees recursively.
The get_min and get_max functions then utilize these trees to query the minimum and maximum values within a given range [a, b], reducing the time complexity compared to linear search methods.
이 C++ 코드는 배열의 지정된 범위 내에서 최소값과 최대값을 효율적으로 쿼리하기 위해 세그먼트 트리를 구축합니다. 배열을 사전 처리하여 빠른 범위 쿼리를 가능하게 하는 세그먼트 트리 개념을 활용합니다.
배열 요소는 전역 배열 arr[]에 저장되며, mintree[] 및 maxtree[]라는 두 개의 세그먼트 트리가 각각 배열 내 세그먼트의 최소값과 최대값을 나타내도록 구축됩니다.
create_min 및 create_max 함수는 이 트리들을 재귀적으로 구성합니다.
그런 다음 get_min 및 get_max 함수는 주어진 범위 [a, b] 내에서 최소값과 최대값을 쿼리하기 위해 이 트리들을 활용하여 선형 검색 방법에 비해 시간 복잡도를 줄입니다.
*/

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int N, M; // N is the number of elements, M is the number of queries
int arr[100001]; // Array to store the elements
int mintree[400001]; // Segment tree for minimum values
int maxtree[400001]; // Segment tree for maximum values
int a, b; // Variables to store the range for queries

// Function to create the segment tree for minimum values
int create_min(int node, int s, int e) {
	if (s == e) { // Base case: if the segment is a single element
		mintree[node] = arr[s];
		return arr[s];
	}
	int m = (s + e) / 2;
	// Recursively build the left and right parts of the segment tree and store the minimum
	mintree[node] = min(create_min(node * 2, s, m), create_min((node * 2) + 1, m + 1, e));
	return mintree[node];
}

// Function to create the segment tree for maximum values
int create_max(int node, int s, int e) {
	if (s == e) {
		maxtree[node] = arr[s];
		return arr[s];
	}
	int m = (s + e) / 2;
	// Recursively build the left and right parts of the segment tree and store the maximum
	maxtree[node] = max(create_max(node * 2, s, m), create_max((node * 2) + 1, m + 1, e));
	return maxtree[node];
}

// Function to query the minimum value in a given range
int get_min(int node, int s, int e) {
	if (a > e || b < s) // If the queried range is outside the current segment
		return INT_MAX;
	if (a <= s && b >= e) // If the current segment is completely within the queried range
		return mintree[node];
	int m = (s + e) / 2;
	// Recursively query the left and right parts of the segment tree and return the minimum
	return min(get_min(node * 2, s, m), get_min((node * 2) + 1, m + 1, e));
}

// Function to query the maximum value in a given range
int get_max(int node, int s, int e) {
	if (a > e || b < s)
		return INT_MIN;
	if (a <= s && b >= e)
		return maxtree[node];
	int m = (s + e) / 2;
	// Recursively query the left and right parts of the segment tree and return the maximum
	return max(get_max(node * 2, s, m), get_max((node * 2) + 1, m + 1, e));
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M; // Reading the number of elements and queries

	// Reading the elements into the array
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// Building the segment trees for minimum and maximum queries
	create_min(1, 1, N);
	create_max(1, 1, N);

	// Processing each query
	for (int i = 0; i < M; i++) {
		cin >> a >> b; // Reading the range for the query
		// Printing the minimum and maximum values in the range
		cout << get_min(1, 1, N) << " " << get_max(1, 1, N) << "\n";
	}
}
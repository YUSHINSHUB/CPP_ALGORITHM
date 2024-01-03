/*
commented by ChatGPT
This C++ code is aimed at finding the longest increasing subsequence in a sequence of pairs.
The code reads pairs of integers, storing the second elements in an array if they meet a certain condition.
It then calculates the length of the longest increasing subsequence and outputs the minimum number of elements that need to be removed from the sequence to form this subsequence.
이 C++ 코드는 쌍의 시퀀스에서 가장 긴 증가하는 부분 수열을 찾는 것을 목표로 합니다.
코드는 정수 쌍을 읽고, 특정 조건을 만족하는 경우 두 번째 요소를 배열에 저장합니다.
그런 다음 가장 긴 증가하는 부분 수열의 길이를 계산하고 이 수열을 형성하기 위해 제거해야 하는 최소 요소 수를 출력합니다.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int link[501]; // Array to store the second elements of pairs (쌍의 두 번째 요소를 저장하는 배열)
static vector<int> list; // Vector to store valid second elements (유효한 두 번째 요소를 저장하는 벡터)
static int mem[501]; // Array for dynamic programming to store lengths of increasing subsequences (증가하는 부분 수열의 길이를 저장하기 위한 동적 프로그래밍 배열)
static int inc = 1; // Increment variable (증가 변수)

int main() {
	ios_base::sync_with_stdio(0); // Fast IO optimization
	cin.tie(0); // Fast IO optimization
	cout.tie(0); // Fast IO optimization

	int a, b, n; // Variables to store input pairs and number of pairs

	fill(link, link + 501, 0); // Initialize link array with zeros (link 배열을 0으로 초기화)
	cin >> n; // Read number of pairs
	int res = 0; // Variable to store the result (결과를 저장할 변수)

	// Reading each pair and storing the second element in link array
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		link[a] = b;
	}

	// Adding valid second elements to the list
	for (int i = 1; i <= 500; i++) {
		if (link[i] > 0)
			list.push_back(link[i]);
	}

	// Calculating the length of the longest increasing subsequence
	for (int i = 0; i < n; i++) {
		int cur = list[i];
		for (int j = 0; j < cur; j++) {
			mem[cur] = max(mem[j] + 1, mem[cur]); // Updating the length of the subsequence
		}
		res = max(res, mem[cur]); // Storing the maximum length found
	}

	cout << n - res; // Outputting the minimum number of elements to be removed
}
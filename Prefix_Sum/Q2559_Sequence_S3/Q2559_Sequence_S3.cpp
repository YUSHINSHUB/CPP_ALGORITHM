/*
commented by ChatGPT
This C++ program finds the maximum sum of consecutive K elements in a given sequence. It utilizes a sliding window approach to efficiently compute the sum as it traverses through the sequence, avoiding redundant calculations.
이 C++ 프로그램은 주어진 수열에서 연속하는 K개의 요소의 최대 합을 찾습니다. 수열을 효율적으로 탐색하면서 합을 계산하기 위해 슬라이딩 윈도우 방식을 사용하며, 중복 계산을 피합니다.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

	int N, K, temp;
	int cur = 0;
	int front = 0;
	int res = 0;
	vector<int> inp;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		inp.push_back(temp);
	}

	for (int i = 0; i < K; i++) {
		cur += inp[i];
		res = cur; // Initialize result with the sum of the first K elements
	}

	for (int i = K; i < N; i++) {
		cur -= inp[front];
		cur += inp[i];
		front++;
		res = max(res, cur); // Update result with the maximum sum encountered
	}

	cout << res; // Output the final result
}

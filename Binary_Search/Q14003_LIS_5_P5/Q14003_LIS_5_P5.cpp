/*
commented by ChatGPT
This C++ code finds the length of the Longest Increasing Subsequence(LIS) in a given sequence and also reconstructs the LIS itself.
It reads the sequence length(N) and the sequence from standard input.The code uses dynamic programming with a binary search optimization to efficiently compute the LIS.
Additionally, it maintains an array(`mem`) to track the index of each element in the LIS, which is used later to reconstruct the LIS.
After computing the LIS length, the code reconstructs the LIS by tracing back through the `mem` array and outputs both the length and the LIS.

	이 C++ 코드는 주어진 시퀀스에서 가장 긴 증가하는 부분 수열(LIS)의 길이를 찾고, LIS 자체를 재구성합니다.시퀀스 길이(N)와 시퀀스를 표준 입력에서 읽습니다.
	코드는 동적 프로그래밍과 이진 검색 최적화를 사용하여 효율적으로 LIS를 계산합니다.또한, `mem` 배열을 유지하여 LIS에서 각 요소의 인덱스를 추적하고, 이를 사용하여 나중에 LIS를 재구성합니다.
	LIS 길이를 계산한 후, 코드는 `mem` 배열을 통해 추적하여 LIS를 재구성하고 길이와 LIS를 모두 출력합니다.
	*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N; // 시퀀스의 길이
	cin >> N;
	int sequence[1000001]; // 입력 시퀀스
	int mem[1000001]; // LIS에서 각 요소의 위치를 추적하는 데 사용
	int res[1000001]; // 가능한 최소의 마지막 요소를 가진 LIS를 저장
	int idx = 1; // LIS의 길이 및 res 배열의 인덱스
	vector<int> arr; // LIS를 저장하는 벡터

	fill(sequence, sequence + N + 1, 0); // 시퀀스 배열 초기화

	// 시퀀스 입력 받기
	for (int i = 0; i < N; i++)
		cin >> sequence[i];
	res[0] = sequence[0]; // 첫 번째 요소로 시작
	mem[0] = 0; // 첫 번째 요소의 위치는 0

	// LIS 계산
	for (int i = 1; i < N; i++) {
		if (sequence[i] > res[idx - 1]) {
			res[idx] = sequence[i];
			mem[i] = idx;
			idx++;
			continue;
		}
		int low = 0;
		int high = idx;
		int mid = high / 2;

		// 이진 검색으로 현재 요소를 삽입할 위치 찾기
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
		res[low] = sequence[i];
		mem[i] = low;
	}

	cout << idx << "\n"; // LIS 길이 출력
	int cur = idx - 1; // LIS 재구성을 위한 역추적 시작 위치
	// LIS 재구성
	for (int i = N - 1; i >= 0; i--) {
		if (mem[i] == cur) {
			arr.push_back(sequence[i]);
			cur--;
			if (cur < 0)
				break;
		}
	}

	// 재구성된 LIS 출력
	for (int i = idx - 1; i >= 0; i--)
		cout << arr[i] << " ";
}
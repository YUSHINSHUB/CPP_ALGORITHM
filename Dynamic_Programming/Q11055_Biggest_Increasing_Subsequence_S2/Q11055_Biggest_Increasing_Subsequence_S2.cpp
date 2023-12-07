/*
commented by ChatGPT
This C++ program calculates the maximum sum of an increasing subsequence within a given sequence of integers. 
It uses dynamic programming and memoization to efficiently determine the largest possible sum of a subsequence where each element is greater than all preceding elements in the subsequence.
이 C++ 프로그램은 주어진 정수 수열 내에서 증가하는 부분 수열의 최대 합을 계산합니다. 
프로그램은 동적 프로그래밍과 메모이제이션을 사용하여, 각 요소가 그 앞의 모든 요소보다 큰 부분 수열의 가능한 가장 큰 합을 효율적으로 결정합니다.
*/

#include <iostream>
#include <cmath> // cmath 라이브러리 포함

using namespace std;

int sequence[1001]; // 입력 수열을 저장할 배열
int mem[1001]; // 동적 프로그래밍을 위한 메모이제이션 배열
int N; // 수열의 길이

// 재귀적 동적 프로그래밍 함수 dp
static int dp(int idx) {
	if (mem[idx] > 0) // 이미 계산된 값이 있는 경우 해당 값을 반환
		return mem[idx];

	mem[idx] = sequence[idx]; // 초기 값 설정
	for (int i = idx - 1; i >= 0; i--) { // 현재 위치보다 앞에 있는 모든 요소에 대해 반복
		if (sequence[i] < sequence[idx]) { // 증가하는 부분 수열 조건 확인
			// 현재 위치에 대한 최대 합 갱신
			mem[idx] = max(dp(i) + sequence[idx], mem[idx]);
		}
	}

	return mem[idx]; // 계산된 최대 합 반환
}

int main() {
	int res = 0; // 최대 합을 저장할 변수

	cin >> N; // 사용자로부터 수열의 길이 입력 받음
	fill(mem, mem + N + 1, 0); // 메모이제이션 배열을 0으로 초기화
	for (int i = 0; i < N; i++)
		cin >> sequence[i]; // 수열 입력

	for (int i = N - 1; i >= 0; i--)
		res = max(res, dp(i)); // 모든 요소에 대해 최대 합 계산

	cout << res; // 결과 출력
}

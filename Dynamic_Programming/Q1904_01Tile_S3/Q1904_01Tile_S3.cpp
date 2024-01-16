/*
commented by ChatGPT
This C++ program calculates the N-th number in a sequence using dynamic programming and memoization. The sequence is defined such that each number is the sum of the two preceding numbers, modulo 15746. The purpose is to find the N-th number in this sequence efficiently.
이 C++ 프로그램은 동적 프로그래밍과 메모이제이션을 사용하여 수열의 N번째 숫자를 계산합니다. 이 수열은 각 숫자가 이전 두 숫자의 합(15746으로 모듈로 연산)으로 정의됩니다. 목적은 이 수열에서 N번째 숫자를 효율적으로 찾는 것입니다.
*/

#include <iostream>

using namespace std;

int mem[1000001]; // 메모이제이션을 위한 배열 선언, 1000001개의 정수를 저장할 수 있음

// 동적 프로그래밍을 위한 함수 dp
int dp(int idx) {
	// 이미 계산된 값이 있는 경우 해당 값을 반환
	if (mem[idx] >= 0) {
		return mem[idx];
	}

	// 아직 계산되지 않은 경우, 이전 두 값의 합을 계산하고 15746으로 모듈로 연산
	mem[idx] = (dp(idx - 1) + dp(idx - 2)) % 15746;

	return mem[idx]; // 계산된 값을 반환
}


int main() {
	int N; // 입력받을 정수 N 선언

	cin >> N; // 사용자로부터 N을 입력받음
	fill(mem, mem + N + 1, -1); // 메모이제이션 배열을 -1로 초기화
	mem[1] = 1; // 첫 번째 수는 1로 초기화
	if (N >= 2)
		mem[2] = 2; // 두 번째 수는 2로 초기화, N이 2 이상인 경우에만 설정

	cout << dp(N); // dp 함수를 호출하여 결과 출력

	// 프로그램이 끝나면 메모리 해제 및 종료
}

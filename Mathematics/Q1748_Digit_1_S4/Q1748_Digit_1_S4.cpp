/*
commented by ChatGPT
This C++ code calculates the total number of digits required to write down all numbers from 1 to N. It first reads an integer N from standard input and computes the number of digits (len) in N.
The code then iteratively accumulates the total number of digits required for each set of numbers (1-9, 10-99, 100-999, etc.) up to but not including the highest range that N falls into.
It then calculates the number of digits for the remaining numbers up to N and adds them to the total. If N is a single-digit number, the result is simply N itself.
이 C++ 코드는 1부터 N까지 모든 숫자를 쓰는 데 필요한 숫자의 총 개수를 계산합니다. 먼저 표준 입력에서 정수 N을 읽고, N의 자릿수(len)를 계산합니다.
코드는 그 후 각 숫자 세트(1-9, 10-99, 100-999 등)에 필요한 총 숫자 개수를 반복적으로 누적합니다. 이는 N이 속하는 가장 높은 범위를 포함하지 않습니다.
그런 다음 N까지 남아 있는 숫자에 필요한 숫자 개수를 계산하여 총합에 추가합니다. 만약 N이 한 자리 숫자라면, 결과는 단순히 N 자체입니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N, len; // N: 입력받은 숫자, len: N의 자릿수
	int pl = 9; // 각 자리수 구간의 최대값 (예: 9, 99, 999)
	int res = 0; // 결과값을 저장할 변수

	cin >> N; // N 입력 받기
	len = (int)log10(N); // N의 자릿수 계산

	// 각 자리수 구간별로 필요한 숫자 개수 계산
	for (int i = 1; i <= len; i++) {
		res += pl * i;
		pl *= 10;
	}

	// 마지막 자리수 구간의 시작 숫자 계산 (예: 100, 1000)
	pl /= 10;
	pl += (pl / 9) - 1;

	// 마지막 자리수 구간에 대한 숫자 개수 추가
	res += (len + 1) * (N - pl);

	// N이 한 자리 숫자일 경우, N을 결과값으로 설정
	if (N / 10 == 0)
		res = N;

	cout << res; // 결과 출력
}
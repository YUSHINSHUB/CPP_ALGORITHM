
/*
commented by ChatGPT
This C++ code is a dynamic programming solution for finding the longest common subsequence (LCS) of two strings. It employs a similar approach as the Java version.
The dp function computes the LCS length using memoization to avoid redundant calculations. It compares characters of both strings at current indices.
If they match, it considers the longest sequence up to that point and adds one.
If they don't match, it checks the maximum sequence length by either ignoring the current character of the first string or the second string.
The main function reads two input strings and initializes the memoization array mem to -1. The code reconstructs the LCS from the memoization table.
It iterates backwards over the strings, adding characters to a string sb when a match contributing to the LCS is found.
Finally, it reverses sb to obtain the LCS in correct order and prints its length and content.
이 C++ 코드는 두 문자열의 최장 공통 부분 수열(LCS)을 찾기 위한 동적 프로그래밍 솔루션입니다. Java 버전과 유사한 접근 방식을 사용합니다.
dp 함수는 메모이제이션을 사용하여 중복 계산을 피하면서 LCS 길이를 계산합니다. 두 문자열의 현재 인덱스에서 문자를 비교합니다. 문자가 일치하면, 그 지점까지의 가장 긴 시퀀스를 고려하고 하나를 더합니다.
일치하지 않는 경우, 첫 번째 문자열 또는 두 번째 문자열의 현재 문자를 무시하여 최대 시퀀스 길이를 확인합니다. 메인 함수는 두 입력 문자열을 읽고 메모이제이션 배열 mem을 -1로 초기화합니다.
코드는 메모이제이션 테이블에서 LCS를 재구성합니다. 문자열을 뒤에서부터 반복하며, LCS에 기여하는 일치하는 문자를 문자열 sb에 추가합니다.
마지막으로, sb를 뒤집어 올바른 순서로 LCS를 얻고 그 길이와 내용을 출력합니다.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

char str[2][1000]; // 두 문자열을 저장할 배열
int mem[1000][1000]; // 동적 프로그래밍을 위한 메모이제이션 배열

// LCS 길이를 계산하는 재귀 함수
static int dp(int idx1, int idx2) {
	if (mem[idx1][idx2] >= 0) // 이미 계산된 값이 있는 경우 해당 값을 반환
		return mem[idx1][idx2];

	if (str[0][idx1] == str[1][idx2]) { // 두 문자가 일치하는 경우
		if (idx1 == 0 || idx2 == 0)
			mem[idx1][idx2] = 1; // 첫 번째 문자일 경우 1로 초기화
		else
			mem[idx1][idx2] = dp(idx1 - 1, idx2 - 1) + 1; // 두 문자가 일치하면 이전 문자까지의 LCS에 1을 추가
	}
	else { // 두 문자가 일치하지 않는 경우
		if (idx1 == 0 && idx2 == 0)
			mem[idx1][idx2] = 0; // 두 문자열의 시작 부분이면 0으로 초기화
		else if (idx1 == 0)
			mem[idx1][idx2] = dp(idx1, idx2 - 1); // 첫 번째 문자열의 첫 문자에 도달한 경우
		else if (idx2 == 0)
			mem[idx1][idx2] = dp(idx1 - 1, idx2); // 두 번째 문자열의 첫 문자에 도달한 경우
		else
			mem[idx1][idx2] = max(dp(idx1 - 1, idx2), dp(idx1, idx2 - 1)); // 최대 LCS 길이 계산
	}

	return mem[idx1][idx2];
}

int main() {
	string in;
	string sb = ""; // LCS를 저장할 문자열
	int alen, blen;

	// 첫 번째 문자열 입력 및 저장
	cin >> in;
	alen = in.length() - 1;
	for (int i = 0; i <= alen; i++)
		str[0][i] = in[i];

	// 두 번째 문자열 입력 및 저장
	cin >> in;
	blen = in.length() - 1;
	for (int i = 0; i <= blen; i++)
		str[1][i] = in[i];

	// 메모이제이션 배열 초기화
	for (int i = 0; i < 1000; i++) {
		fill(mem[i], mem[i] + 1000, -1);
	}

	// LCS 계산 및 재구성
	if (alen != -1 && blen != -1) {
		int len = dp(alen, blen);
		while (len > 0) {
			for (int i = alen; i >= 0; i--) {
				if (mem[i][blen] == len && str[0][i] == str[1][blen]) {
					sb += str[1][blen];
					alen = i - 1;
					len--;
					break;
				}
			}
			blen--;
		}
		reverse(sb.begin(), sb.end());
		cout << sb.length() << "\n" << sb;
	}
	else {
		cout << "0";
	}
}
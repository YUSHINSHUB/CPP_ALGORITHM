/*
commented by ChatGPT
This code finds the length of the Longest Common Subsequence (LCS) between two strings.
*/

#include <iostream>
#include <math.h>
using namespace std;

// Declare a 2D array to store the characters of the two input strings.
char str[2][1001];
// Declare a 2D array to store the results of LCS for different substrings
// (Memoization).
int lcs[1001][1001];
// Declare two integers to store the lengths of the input strings.
int alen, blen;

// Recursive function to calculate the LCS using top-down dynamic programming.
int dp(int i, int j) {

	// Base condition: If any of the strings is empty, the LCS is 0.
	if (i == 0 || j == 0)
		return 0;

	// If the result is already computed for the given substring, return it.
	if (lcs[i][j] >= 0) {
		return lcs[i][j];
	}

	// If characters at current position are equal, consider them in LCS.
	if (str[0][i] == str[1][j]) {
		lcs[i][j] = dp(i - 1, j - 1) + 1;
	}
	else {
		// If characters are different, take the maximum of LCS values when ignoring
		// either character.
		lcs[i][j] = max(dp(i - 1, j), dp(i, j - 1));
	}

	return lcs[i][j];

}

int main()
{
	// Read the first string and calculate its length.
	string s;
	cin >> s;
	alen = s.length();
	// Convert the string to a character array.
	for (int i = 1; i <= alen; i++) {
		str[0][i] = s[i - 1];
		// Initialize the memoization array for this index.
		fill(lcs[i], lcs[i] + alen + 1, -1);
	}

	// Read the second string and calculate its length.
	cin >> s;
	blen = s.length();
	// Convert the string to a character array.
	for (int i = 1; i <= s.length(); i++) {
		str[1][i] = s[i - 1];
		// Initialize the memoization array for this index.
		fill(lcs[i], lcs[i] + blen + 1, -1);
	}

	// Invoke the dp function to calculate the LCS.
	cout << dp(alen, blen);

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

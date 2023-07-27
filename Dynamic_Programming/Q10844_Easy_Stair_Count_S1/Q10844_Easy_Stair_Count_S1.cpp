// //The program is a solution to a problem often referred to as "stair number calculation".
//A stair number is defined as a number that, in its decimal representation, 
//each pair of adjacent digits differ by one. 
//For example, the number 45654 is a stair number, while 45645 is not.

#include <iostream>
using namespace std;

// A 2D array to store our dynamic programming table
static int cnt[101][10];

// Dynamic programming function to calculate the counts
static void dp(int n) {
	// If the count for n-1 hasn't been calculated and n != 1, calculate it
	// recursively
	if (cnt[n - 1][0] < 0 && n != 1) {
		dp(n - 1);
	}

	// If n is not 1, calculate the count for current n using the counts from n-1
	if (n != 1) {
		for (int i = 1; i <= 8; i++)
			cnt[n][i] = (cnt[n - 1][i - 1] + cnt[n - 1][i + 1]) % 1000000000;
		// Handle the edge cases for digits 0 and 9 separately
		cnt[n][0] = cnt[n - 1][1] % 1000000000;
		cnt[n][9] = cnt[n - 1][8] % 1000000000;
	}

	return;
}


int main()
{
	int res = 0;
	// Read the input length
	int n;
	cin >> n;

	// Initialize the DP table
	for (int i = 2; i <= 100; i++) {
		fill(cnt[i], cnt[i] + 10, -1);
	}
	// Base case: there is one stair number for each single digit (except 0)
	cnt[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		cnt[1][i] = 1;
	}

	// Calculate the counts using DP
	dp(n);

	// Calculate the total count
	for (int i = 0; i <= 9; i++) {
		res += cnt[n][i];
		res %= 1000000000;
	}

	// Write the result
	cout << res;
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

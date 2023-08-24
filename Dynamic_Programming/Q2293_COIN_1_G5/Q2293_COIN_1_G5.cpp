// Commented by ChatGPT
// Summary: This program determines the number of ways to make up a total amount "k" using provided coin denominations.

#include <iostream>
using namespace std;

int main()
{
	// Input the number of coin denominations (n) and the target amount (k).
	int n, k;
	cin >> n >> k;

	// Array to store the values of the coin denominations.
	int coin[100];

	// DP (Dynamic Programming) array to store the number of ways to achieve a particular amount.
	int dp[10001];

	// Initialize the dp array with zeros for indices up to k.
	fill(dp, dp + k + 1, 0);

	// Base case: There is one way to achieve an amount of 0 (using no coins).
	dp[0] = 1;

	// Reading the values of coin denominations from the input.
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	// Nested loops to update the dp array values.
	// Outer loop iterates over each coin denomination.
	for (int j = 0; j < n; j++) {
		// Inner loop iterates for each value up to the target amount 'k'.
		for (int i = 1; i <= k; i++) {
			// If the current amount can be achieved using the current coin denomination:
			if (coin[j] <= i) {
				// Increment the current dp value by the value of (current amount - coin denomination).
				dp[i] += dp[i - coin[j]];
			}
		}
	}

	// Output the number of ways to achieve the target amount 'k'.
	cout << dp[k];
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

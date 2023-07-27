// Q2156_Tasting_Wine_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>

using namespace std;

// dp array to store the maximum volume that can be drunk for each number of
	// bottles
static int dp[10001];

// w array to store the volume of each bottle
static int w[10001];

// recursive function to calculate the maximum volume that can be drunk from n
// bottles
static int recur(int n) {

	// if dp[n] has not been calculated yet
	if (dp[n] < 0) {
		// calculate dp[n] as the maximum of three scenarios:
		// 1. Drink from n-th and (n-1)-th bottle, skip the (n-2)-th bottle
		// 2. Drink from the n-th bottle, skip the (n-1)-th and (n-2)-th bottles
		// 3. Skip the n-th bottle
		dp[n] = max(max(recur(n - 3) + w[n - 1] + w[n], recur(n - 2) + w[n]), recur(n - 1));
	}

	// return dp[n]
	return dp[n];
}

int main()
{
	// read the total number of bottles
	int n;
	cin >> n;

	// fill the dp array with -1 initially
	fill(dp, dp + n + 1, -1);

	// read the volume of each bottle
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	// no bottle, no wine to drink
	w[0] = 0;
	dp[0] = 0;

	// if there are at least two bottles, drink both
	if (n >= 2) {
		dp[2] = w[1] + w[2];
		dp[1] = w[1];
	}

	// if there is only one bottle, drink it
	else if (n == 1)
		dp[1] = w[1];

	// calculate the maximum volume of wine that can be drunk from n bottles
	int res = recur(n);

	// write the result to the standard output
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

// commented by ChatGPT
// Summary:
// A program to solve the 0-1 knapsack problem using dynamic programming. 
// The program calculates the maximum value obtainable while ensuring the 
// total weight doesn't exceed a specified limit.


#include <iostream>
#include <math.h>

using namespace std;

// 2D array storing the weight (index 0) and value (index 1) of items
int item[100][2];

// Memoization table, where mem[i][j] stores the maximum value obtainable
// using the first j items and a total weight of i
int mem[100001][100];

// n = number of items, k = weight capacity of the knapsack
int n, k;

// Dynamic programming function to compute the maximum value
int dp(int w, int idx) {

	// Return the memorized result if available
	if (mem[w][idx] >= 0) {
		return mem[w][idx];
	}

	// Check if we can include the current item in the knapsack
	if (item[idx][0] <= w)
		// Either include the current item or skip it,
		// and store the maximum of the two options
		mem[w][idx] = max(item[idx][1] + dp(w - item[idx][0], idx - 1), dp(w, idx - 1));
	else
		// Current item cannot be included, so skip it
		mem[w][idx] = dp(w, idx - 1);

	return mem[w][idx];
}

int main()
{
	cin >> n >> k;

	// Input the weight and value for each item
	for (int i = 0; i < n; i++) {
		cin >> item[i][0] >> item[i][1];
	}

	// Initialize the memoization table
	for (int i = 1; i <= k; i++) {
		fill(mem[i], mem[i] + n, -1);

		// If the total weight allows including the first item, do so
		if (i >= item[0][0])
			mem[i][0] = item[0][1];
		else
			mem[i][0] = 0;
	}

	// Base case: for total weight = 0, the maximum value is always 0
	fill(mem[0], mem[0] + n, 0);

	// Output the maximum value for weight = k using all n items
	cout << dp(k, n - 1);
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

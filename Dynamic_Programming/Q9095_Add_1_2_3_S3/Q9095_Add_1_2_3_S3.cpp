// Q9095_Add_1_2_3_S3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// Commented by ChatGPT
// Summary: This C++ program calculates the number of ways to reach the nth step using 1, 2, or 3 steps at a time.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	// Create an array 'dp' to store the number of ways to reach each step.
	int dp[11];
	// Initialize the first three elements of the array as per the base cases.
	dp[1] = 1; // 1 way to reach the 1st step (1 step)
	dp[2] = 2; // 2 ways to reach the 2nd step (1+1 or 2 steps)
	dp[3] = 4; // 4 ways to reach the 3rd step (1+1+1, 1+2, 2+1, or 3 steps)

	// Use dynamic programming to calculate the number of ways to reach each step from 4 to 10.
	for (int i = 4; i <= 10; i++) {
		// The number of ways to reach step 'i' is the sum of the number of ways to reach steps 'i-1', 'i-2', and 'i-3'.
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	// Read the number of test cases (t) from the input.
	int t;
	cin >> t;

	// Process each test case.
	for (int i = 0; i < t; i++) {
		// Read the step number (temp) for this test case.
		int temp;
		cin >> temp;
		// Write the number of ways to reach the given step (dp[temp]) to the output.
		cout << dp[temp] << "\n";
	}
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

//Commented by ChatGPT
//Summary: This program calculates the Padovan sequence using dynamic programming with memoization and prints the nth element for each test case.


#include <iostream>
using namespace std;

// Declare an array 'visited' to keep track of whether the corresponding 'pad'
	// value has been computed.
bool visited[101];
// Declare an array 'pad' to store the computed Padovan sequence values as long
// integers.
long long pad[101];

// The 'dp' function calculates the nth element of the Padovan sequence using
// dynamic programming with memoization.
long long dp(int n) {
	// If the nth element has been computed, return the stored value.
	if (visited[n] == true) {
		return pad[n];
	}
	else {
		// Otherwise, calculate the nth element using the recurrence relation and store
		// the result in the 'pad' array.
		pad[n] = dp(n - 2) + dp(n - 3);
		visited[n] = true;
		return pad[n];
	}
}

int main()
{
	// Initialize the 'visited' array to false.
	fill(visited, visited + 101, false);
	// Read the number of test cases.
	int t;
	cin >> t;

	// Initialize the base cases of the Padovan sequence.
	pad[1] = 1;
	pad[2] = 1;
	pad[3] = 1;
	visited[1] = true;
	visited[2] = true;
	visited[3] = true;

	// Process each test case.
	for (int i = 0; i < t; i++) {
		// Read the input value 'n'.
		int n;
		cin >> n;

		// Write the nth element of the Padovan sequence to the output.
		cout << dp(n) << "\n";
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

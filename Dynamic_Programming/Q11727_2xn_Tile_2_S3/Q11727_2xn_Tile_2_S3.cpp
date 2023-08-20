//Commented by ChatGPT
//This program calculates the nth term of a sequence using dynamic programming. 
//The program uses memoization to store previously calculated values of the sequence to avoid redundant calculations.

#include <iostream>
using namespace std;

// Create an array to store the memoized values of the sequence
int mem[1001];

// Dynamic programming function to calculate the nth term of the sequence
int dp(int a) {
	// If the value is already calculated and stored in mem[], return it
	if (mem[a] > 0)
		return mem[a];
	else {
		// Otherwise, calculate the nth term using the recurrence relation
		// The nth term is the sum of the (n-1)th term and 2 times the (n-2)th term
		// The result is stored in mem[] and returned
		mem[a] = (dp(a - 1) + (dp(a - 2) * 2)) % 10007;
		return mem[a];
	}
}

int main()
{
	// Read the value of n (term to calculate)
	int n;
	cin >> n;

	// Initialize the base cases of the sequence
	mem[0] = 1;
	mem[1] = 1;

	// Write the nth term of the sequence to the output
	cout << dp(n);
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

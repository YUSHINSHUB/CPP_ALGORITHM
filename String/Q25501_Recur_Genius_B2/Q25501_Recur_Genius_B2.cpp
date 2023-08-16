// Q25501_Recur_Genius_B2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
Commented by ChatGPT
Summary: This C++ program checks if each string in a list of strings is a palindrome using a recursive approach.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int cnt; // Declare a global variable cnt to track the number of recursive calls

// Recursive function to check if a string is a palindrome
int recursion(const char* s, int l, int r) {
	cnt++; // Increment the cnt variable
	if (l >= r) // If left pointer is greater than or equal to the right pointer, return 1
		return 1;
	else if (s[l] != s[r]) // If the characters at left and right pointers are not equal, return 0
		return 0;
	else
		return recursion(s, l + 1, r - 1); // Otherwise, continue checking with the next characters
}

// Function that calls the recursive function and returns 1 if the string is a palindrome and 0 otherwise
int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}


int main() {
	int n; // Declare an integer n to store the number of strings
	cin >> n; // Read the number of strings

	for (int i = 0; i < n; i++) { // Loop through each string
		cnt = 0; // Reset cnt to 0
		char inp[1001]; // Declare a char array inp to store the input string
		cin >> inp; // Read the input string
		cout << isPalindrome(inp) << " " << cnt << "\n"; // Output the result and the number of recursive calls
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

// commented by ChatGPT
// Summary: It prints 0 for strings already palindromic, 1 if making them palindromic requires a single character removal, and 2 otherwise.

#include <iostream>
using namespace std;

int main()
{
	// Number of test cases.
	int t;
	cin >> t;

	// Iterate through each test case.
	for (int i = 0; i < t; i++) {

		// Initial result is set to "0\n" indicating the string might be a palindrome.
		string res = "0\n";

		// Read the string for this test case.
		string s;
		cin >> s;

		int beg = 0;               // Starting index of the string.
		int end = s.length() - 1;  // Ending index of the string.
		int sbeg = -1;             // Saved starting index for potential backtracking.
		int send = -1;             // Saved ending index for potential backtracking.

		// Iterate through the string from both ends.
		while (beg < end) {
			if (s[beg] != s[end]) { // When characters at the start and end are not the same.
				if (res == "0\n") {
					if (s[beg + 1] == s[end] && s[beg] == s[end - 1]) {
						// Two potential removals. Save current indices for future backtracking.
						sbeg = beg;
						send = end;
						res = "1\n";
						beg++;
					}
					else if (s[beg + 1] == s[end]) {
						// Palindrome possible by removing the character from the beginning.
						res = "1\n";
						beg++;
					}
					else if (s[beg] == s[end - 1]) {
						// Palindrome possible by removing the character from the end.
						res = "1\n";
						end--;
					}
					else {
						// Making a palindrome isn't possible by removing just one character.
						res = "2\n";
						break;
					}
				}
				else {
					if (sbeg != -1) {
						// Backtrack to explore the other possible removal.
						beg = sbeg;
						end = send - 1;
						sbeg = -1;
					}
					else {
						// Making a palindrome isn't possible by removing just one character.
						res = "2\n";
						break;
					}
				}
			}
			beg++;  // Move to the next character from the beginning.
			end--;  // Move to the next character from the end.
		}

		// Print the result for the current test case.
		cout << res;
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

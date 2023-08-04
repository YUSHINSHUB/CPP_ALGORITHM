/*
Commented by ChatGPT
Summary: This program identifies and counts occurrences of a specific pattern (IO...OI) in an input
string. The number of 'O's in the pattern is specified by the input 'n'.
*/

#include <iostream>

using namespace std;

int main()
{
	int res = 0; // Stores the total number of matched patterns.
	int n; // Reading the number of 'O's in the pattern.
	cin >> n;

	int cnt = 0; // Counter variable to track the pattern.
	n *= 2;
	n++; // Incrementing n to match the number of 'I's and 'O's in the pattern.

	int m; // Reading the length of the string to be checked.
	cin >> m;

	string s; // Reading the string to be checked.
	cin >> s;

	// Looping through the string.
	for (int i = 0; i < m; i++) {
		if (cnt % 2 == 0 && s[i] == 'I') { // Checking for 'I' at even indices.
			cnt++;
			if (cnt == n) { // If the count equals n, we found a pattern.
				res++;
				cnt -= 2;
			}
		}
		else if (cnt % 2 == 1 && s[i] == 'O') { // Checking for 'O' at odd indices.
			cnt++;
		}
		else if (s[i] == 'I') {
			cnt = 1;
		}
		else {
			cnt = 0;
		}
	}

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

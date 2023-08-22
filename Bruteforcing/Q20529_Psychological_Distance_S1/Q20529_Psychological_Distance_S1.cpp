//Commented by ChatGPT
//Summary: This program reads input test cases containing strings and determines the minimum number of character replacements needed for three strings (from each test case) to become identical.

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

int main()
{
	// Read the number of test cases
	int t;
	cin >> t;

	// Process each test case
	for (int i = 0; i < t; i++) {

		// Read the input size
		int n;
		cin >> n;

		// Read the input strings into an array
		vector<string> inp(n);
		for (int i = 0; i < n; i++) cin >> inp[i];

		// If the input size is 33 or greater, write 0 to output and continue to next
		// test case
		if (n >= 33) {
			cout << "0\n";
			continue;
		}

		int cnt = 0; // Counter for the number of character replacements
		int res = INT_MAX; // Result for the minimum number of character replacements

		// Compare each combination of three strings from the input
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					cnt = 0; // Reset counter for character replacements

					// Compare characters in positions 0 to 3 of the three strings
					for (int m = 0; m < 4; m++) {
						// If the characters are not equal, increment the counter for replacements
						if (inp[j][m] != inp[k][m])
							cnt++;
						if (inp[j][m] != inp[l][m])
							cnt++;
						if (inp[k][m] != inp[l][m])
							cnt++;
					}

					// Update the result with the minimum number of replacements found
					res = min(res, cnt);
				}
			}
		}

		// Write the result to the output
		cout << res << "\n";

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

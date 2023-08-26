/*
commented by ChatGPT
Summary: This code reads an input string representing a sequence of numbers.
It calculates the number of ways the sequence can be decoded into alphabets where '1' is 'A', '2' is 'B', ..., '26' is 'Z'.

For instance:
"111" can be decoded as "AAA", "KA", or "AK", so the output is 3.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Read input string of numbers.
	string s;
	cin >> s;

	int len = s.length();

	// Variables 'y' and 'n' will be used to store intermediate decoding counts.
	int y = 0, n = 0;
	int res = 0; // 'res' will store the final count of possible decodings.

	// Boolean flag to detect invalid number sequences in the string.
	bool pass = false;

	// If the sequence starts with '0', it's invalid.
	if (s[0] == '0')
		cout << "0";
	else if (len == 1) // If only one number, there's only one way to decode.
		cout << "1";
	else {
		int temp = stoi(s.substr(0, 2));

		// Sequences like 30, 40, 50... are invalid as they don't map to any alphabet.
		if (temp % 10 == 0 && temp >= 30) {
			pass = true;
			res = 0;
		}

		if (!pass) {
			// For numbers <= 26, consider multiple possible decodings.
			if (temp <= 26) {
				res = 2;
				y = 1;
				n = 1;

				// Numbers 10 and 20 have a unique decoding (J and T respectively).
				if (temp == 10 || temp == 20) {
					res = 1;
					y = 1;
					n = 0;
				}
			}
			else { // Numbers > 26 can only be decoded in one way.
				res = 1;
				y = 0;
				n = 1;
			}

			// Iterate through the sequence to count possible decodings.
			for (int i = 1; i < s.length() - 1; i++) {
				temp = stoi(s.substr(i, 2));

				// Invalid sequences like 30, 40, 50 or 00 are checked.
				if ((temp % 10 == 0 && temp >= 30) || temp == 0) {
					pass = true;
					res = 0;
					break;
				}

				// For numbers between 10 and 26, consider multiple decodings.
				if (temp <= 26 && temp >= 10) {
					if (temp == 10 || temp == 20) {
						res = ((res + 1000000) - y) % 1000000; // Adjusting count to ensure it's non-negative.
						y = res;
						n = 0;
					}
					else {
						y = n;
						n = res;
						res = (y + n) % 1000000; // Count the decodings modulo 1000000 to handle large values.
					}
				}
				else {
					y = 0;
					n = res;
				}
			}
		}

		// If the result is zero and the sequence was not flagged as invalid, set result
		// to 1.
		if (res == 0 && !pass)
			res = 1;

		// Write the final result.
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

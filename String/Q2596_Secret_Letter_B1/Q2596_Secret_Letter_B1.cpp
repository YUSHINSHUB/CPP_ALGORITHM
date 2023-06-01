// Q2596_Secret_Letter_B1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	int idx = 0;
	string out = "";
	bool pass = false;

	string word[] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };

	for (int i = 0; i < n; i++) {
		pass = false;

		int cnt[8];
		fill_n(cnt, 8, 0);
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 8; k++) {
				if (s[6 * i + j] != word[k][j]) {
					cnt[k]++;
				}
			}
		}
		for (int j = 0; j < 8; j++) {
			if (cnt[j] == 0) {
				pass = true;
				if (j == 0)
					out.append("A");
				else if (j == 1)
					out.append("B");
				else if (j == 2)
					out.append("C");
				else if (j == 3)
					out.append("D");
				else if (j == 4)
					out.append("E");
				else if (j == 5)
					out.append("F");
				else if (j == 6)
					out.append("G");
				else
					out.append("H");
				break;
			}
		}

		if (!pass) {
			for (int j = 0; j < 8; j++) {
				if (cnt[j] == 1) {
					if (pass == true) {
						out = to_string(i + 1);
						break;
					}
					else {
						pass = true;
						idx = j;
					}
				}
			}
		}
		else continue;

		if (!pass) {
			out = to_string(i + 1);
			break;
		}
		else {
			if (idx == 0)
				out.append("A");
			else if (idx == 1)
				out.append("B");
			else if (idx == 2)
				out.append("C");
			else if (idx == 3)
				out.append("D");
			else if (idx == 4)
				out.append("E");
			else if (idx == 5)
				out.append("F");
			else if (idx == 6)
				out.append("G");
			else
				out.append("H");
			continue;
		}

	}

	cout << out;

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

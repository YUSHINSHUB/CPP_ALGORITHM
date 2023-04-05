// Q1254_Make_Palindrome_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;


int main() {

	string in;
	cin >> in;
	int str = 0;
	if (in.length() != 0) str = in.length() / 2;
	int cnt = 1;
	bool p1 = false;
	bool p2 = false;
	int pls = 0;
	int res = in.length();


	if (in.length() == 1 || in.length() == 0) pls = 0;
	else {
		for (int i = str; i < in.length(); i++) {
			p1 = false;
			p2 = false;

			if (i != in.length() - 1) {

				cnt = 1;

				while (true) {
					if (i + cnt > in.length() - 1 || i - cnt < 0) break;
					if (in[i + cnt] != in[i - cnt]) {
						p1 = true;
						break;
					}
					cnt++;
				}

			}
			else p1 = false;

			cnt = 0;

			if (in.length() % 2 == 0 || i > str) {

				while (true) {
					if (i + cnt > in.length() - 1 || i - 1 - cnt < 0) break;
					if (in[i + cnt] != in[i - 1 - cnt]) {
						p2 = true;
						break;
					}
					cnt++;
				}

			}
			else p2 = true;

			if (p1 == false && i == str && in.length() % 2 == 1) {
				pls = 0;
				break;
			}
			else if (p2 == false) {
				pls = (i - 1) - (in.length() - i - 1);
				break;
			}
			else if (i == in.length() - 1 || p1 == false) {
				pls = i - (in.length() - i - 1);
				break;
			}


		}

	}

	res += pls;

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

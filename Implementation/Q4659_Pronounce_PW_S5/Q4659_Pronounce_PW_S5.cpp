// Q4659_Pronounce_PW_S5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{

	string pass = "";
	string vowel = "aeiou";

	while (true) {

		cin >> pass;
		if (pass == "end")
			break;

		bool b1 = false, b2 = true, b3 = true;

		if (pass.length() == 1) {
			if (vowel.find(pass[0]) != string::npos)
				b1 = true;
		}
		else if (pass.length() == 2) {
			if (vowel.find(pass[0]) != string::npos || vowel.find(pass[1]) != string::npos)
				b1 = true;
			if (pass[0] == pass[1] && pass[0] != 'e' && pass[0] != 'o') {
				b3 = false;
			}
		}
		else {
			if (vowel.find(pass[0]) != string::npos || vowel.find(pass[1]) != string::npos)
				b1 = true;
			if (pass[0] == pass[1] && pass[0] != 'e' && pass[0] != 'o') {
				b3 = false;
			}

			if (b3) {
				for (int i = 2; i < pass.length(); i++) {

					if (vowel.find(pass[i]) != string::npos)
						b1 = true;

					if (vowel.find(pass[i]) != string::npos && vowel.find(pass[i - 1]) != string::npos
						&& vowel.find(pass[i - 2]) != string::npos) {
						b2 = false;
						break;
					}
					else if (vowel.find(pass[i]) == string::npos && vowel.find(pass[i - 1]) == string::npos
						&& vowel.find(pass[i - 2]) == string::npos) {
						b2 = false;
						break;
					}

					if (pass[i] == pass[i - 1] && pass[i] != 'e' && pass[i] != 'o') {
						b3 = false;
						break;
					}

				}
			}
		}

		if (b1 && b2 && b3)
			cout << "<" << pass << "> is acceptable.\n";
		else
			cout << "<" << pass << "> is not acceptable.\n";

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

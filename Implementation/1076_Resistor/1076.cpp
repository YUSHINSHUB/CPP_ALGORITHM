// 1076.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {

	string res = "";
	int cnt = 0;

	string inp[3];
	cin >> inp[0] >> inp[1] >> inp[2];

	while (cnt <= 2) {
		if (inp[cnt] == "black") {
			if (cnt == 2) {
			}
			else {
				res += "0";
			}
		}
		else if (inp[cnt] == "brown") {
			if (cnt == 2) {
				res += "0";
			}
			else {
				res += "1";
			}
		}
		else if (inp[cnt] == "red") {
			if (cnt == 2) {
				res += "00";
			}
			else {
				res += "2";
			}
		}
		else if (inp[cnt] == "orange") {
			if (cnt == 2) {
				res += "000";
			}
			else {
				res += "3";
			}
		}
		else if (inp[cnt] == "yellow") {
			if (cnt == 2) {
				res += "0000";
			}
			else {
				res += "4";
			}
		}
		else if (inp[cnt] == "green") {
			if (cnt == 2) {
				res += "00000";
			}
			else {
				res += "5";
			}
		}
		else if (inp[cnt] == "blue") {
			if (cnt == 2) {
				res += "000000";
			}
			else {
				res += "6";
			}
		}
		else if (inp[cnt] == "violet") {
			if (cnt == 2) {
				res += "0000000";
			}
			else {
				res += "7";
			}
		}
		else if (inp[cnt] == "grey") {
			if (cnt == 2) {
				res += "00000000";
			}
			else {
				res += "8";
			}
		}
		else if (inp[cnt] == "white") {
			if (cnt == 2) {
				res += "000000000";
			}
			else {
				res += "9";
			}
		}
		cnt++;
	}

	while (res[0] == '0') {
		if (res.length() == 1) {
			break;
		}
		string temp = res;
		for (int i = 1; i < temp.length(); i++) {
			temp[i - 1] = temp[i];
		}
		res = "";
		for (int i = 0; i < temp.length() - 1; i++) {
			res += temp[i];
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

// 1212_OctalToBinary.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string n;
	cin >> n;
	int temp;
	string temp1;
	string res = "";

	for (int i = 0; i < n.length(); i++) {
		temp = n[i] - '0';

		switch (temp) {
		case 0:
			temp1 = "0";
			break;
		case 1:
			temp1 = "1";
			break;
		case 2:
			temp1 = "10";
			break;
		case 3:
			temp1 = "11";
			break;
		case 4:
			temp1 = "100";
			break;
		case 5:
			temp1 = "101";
			break;
		case 6:
			temp1 = "110";
			break;
		case 7:
			temp1 = "111";
			break;
		}
		//C++에는 자바의 toBinaryString같은 기능이 따로 없다. 하지만 8진수 -> 2진수 변환은
		// 각 자리별로 8가지 케이스밖에 존재하지 않기 때문에 Switch-Case문으로도 충분히 구성할 수 있다.

		if (i != 0) {
			//첫자리에 0이 들어가면 안되기 때문에 i가 1일 경우에는 앞에 0을 붙이지 않고 그대로 넣어준다.
			switch (temp1.length()) {
			case 1:
				res += "00" + temp1;
				break;
			case 2:
				res += "0" + temp1;
				break;
			default:
				res += temp1;
			}
		}
		else {
			res += temp1;
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

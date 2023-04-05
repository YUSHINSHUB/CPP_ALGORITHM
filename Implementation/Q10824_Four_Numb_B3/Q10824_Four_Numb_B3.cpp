// Q10824_Four_Numb_B3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	string in[5];

	cin >> in[0] >> in[1] >> in[2] >> in[3];

	string n1 = in[0] + in[1];
	string n2 = in[2] + in[3];

	string res = "";

	for (int i = 0; i < max(n1.length(), n2.length()) + 1; i++) {
		res += '0';
	}

	int l1 = n1.length() - 1;
	int l2 = n2.length() - 1;
	int pos = 0;

	while (l1 >= 0 && l2 >= 0) {
		res[pos] += (n1[l1] - 48) + (n2[l2] - 48);
		if (res[pos] > '9') {
			res[pos] -= 10;
			res[pos + 1] ++;
			if (res[pos + 1] > '9') {
				res[pos + 1] -= 10;
				res[pos + 2]++;
			}
		}
		pos++;
		l1--;
		l2--;
	}

	while (l1 >= 0) {
		res[pos] += (n1[l1] - 48);
		if (res[pos] > '9') {
			res[pos] -= 10;
			res[pos + 1] ++;
			if (res[pos + 1] > '9') {
				res[pos + 1] -= 10;
				res[pos + 2]++;
			}
		}
		pos++;
		l1--;
	}

	while (l2 >= 0) {
		res[pos] += (n2[l2] - 48);
		if (res[pos] > '9') {
			res[pos] -= 10;
			res[pos + 1] ++;
			if (res[pos + 1] > '9') {
				res[pos + 1] -= 10;
				res[pos + 2]++;
			}
		}
		pos++;
		l2--;
	}

	pos = res.length() - 1;
	while (res[pos] == '0') {
		pos--;
	}

	for (int i = pos; i >= 0; i--) {
		cout << res[i];
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

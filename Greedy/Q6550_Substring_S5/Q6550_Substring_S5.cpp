// Q6550_Substring_S5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool get(int idx, string s, string t) {

	int cnt = 1;
	for (int i = idx + 1; i < t.length(); i++) {
		if (cnt >= s.length()) {
			break;
		}
		if (t[i] == s[cnt]) {
			cnt++;
		}
	}

	if (cnt >= s.length())
		return true;
	else
		return false;
}

int main()
{
	string inp;

	while (getline(cin, inp)) {

		istringstream iss(inp);

		vector<string> v;

		string temp;

		char delimiter = ' ';

		while (getline(iss, temp, delimiter)) {
			v.push_back(temp);
		}

		string s = v[0];
		string t = v[1];

		bool res = false;

		for (int i = 0; i < t.length(); i++) {
			if (t[i] == s[0]) {
				if (get(i, s, t)) {
					res = true;
					break;
				}
			}
		}

		if (res)
			cout << "Yes\n";
		else
			cout << "No\n";

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

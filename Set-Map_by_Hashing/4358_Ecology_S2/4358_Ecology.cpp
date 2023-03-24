// 4358_Ecology.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {

	vector<string>trees(1000001);
	string in;
	int cnt = 0;
	map<string, int> hm;

	while (getline(cin, in)) {
		if (in == "b") break;
		trees[cnt] = in;
		hm.insert(pair<string, int>(in, 0));
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		hm[trees[i]]++;
	}

	set<string> hs(begin(trees), end(trees));
	hs.erase("");
	trees.assign(begin(hs), end(hs));

	sort(begin(trees), end(trees), [](string o1, string o2) -> bool {
		for (int i = 0; i < min(o1.length(), o2.length()); i++) {
			if (o1[i] != o2[i]) return o1[i] < o2[i];
		}
		return o1.length() < o2.length();
		});

	cout << fixed;
	cout.precision(4);

	for (int i = 0; i < hs.size(); i++) {
		double res = (double)hm[trees[i]] / cnt * 100;
		cout << trees[i] << " " << res << "\n";
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

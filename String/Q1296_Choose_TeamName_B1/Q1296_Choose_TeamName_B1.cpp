// Q1296_Choose_TeamName_B1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string y;
	int n;
	cin >> y >> n;

	vector<pair<string, int>> pl(n);
	map<string, int> rate;

	for (int i = 0; i < n; i++) {
		int lc = 0, oc = 0, vc = 0, ec = 0;
		cin >> pl[i].first;
		string temp = pl[i].first;

		for (int j = 0; j < y.length(); j++) {
			if (y[j] == 'L') lc++;
			else if (y[j] == 'O') oc++;
			else if (y[j] == 'V') vc++;
			else if (y[j] == 'E') ec++;
		}

		for (int j = 0; j < temp.length(); j++) {
			if (temp[j] == 'L') lc++;
			else if (temp[j] == 'O') oc++;
			else if (temp[j] == 'V') vc++;
			else if (temp[j] == 'E') ec++;
		}

		int res = (lc + oc) * (lc + vc) * (lc + ec) * (oc + vc) * (oc + ec) * (vc + ec);
		res %= 100;
		pl[i].second = res;
	}

	sort(pl.begin(), pl.end(), [](pair<string, int> o1, pair<string, int> o2) {
		if (o1.second != o2.second) return o1.second > o2.second;
		else return o1.first < o2.first;
		});

	cout << pl[0].first;
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

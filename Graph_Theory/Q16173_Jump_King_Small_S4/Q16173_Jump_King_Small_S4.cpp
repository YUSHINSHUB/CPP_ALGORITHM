// Q16173_Jump_King_Small_S4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class bef {
	int pos;
	int dis;

public:
	bef(int pos, int dis) {
		this->pos = pos;
		this->dis = dis;
	}

	int getpos() {
		return pos;
	}

	int getdis() {
		return dis;
	}

};

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> visited(n, vector<int>(n));
	vector<vector<int>> grp(n, vector<int>(n));
	stack<bef> before;

	for (int i = 0; i < n; i++)
		fill(visited[i].begin(), visited[i].end(), 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grp[i][j];
		}
	}

	int y = 0;
	int x = 0;
	string res = "";

	while (true) {
		if (grp[y][x] == -1) {
			res = "HaruHaru";
			break;
		}

		if (x + grp[y][x] < n && visited[y][x + grp[y][x]] == 0 && grp[y][x] != 0) {
			before.push(bef(1, grp[y][x]));
			x += grp[y][x];
			continue;
		}

		if (y + grp[y][x] < n && visited[y + grp[y][x]][x] == 0 && grp[y][x] != 0) {
			before.push(bef(2, grp[y][x]));
			y += grp[y][x];
			continue;
		}

		if (!before.empty()) {
			visited[y][x] = 1;
			bef temp = before.top();
			before.pop();
			if (temp.getpos() == 1) {
				x -= temp.getdis();
			}
			else {
				y -= temp.getdis();
			}
		}
		else {
			res = "Hing";
			break;
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

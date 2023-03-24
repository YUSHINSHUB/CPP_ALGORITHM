// 16956_Wolf_and_Sheep.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class pos {

public:
	vector<char>p;

	pos(int x) {
		this->p = vector<char>(x);
	}

	void change(int x, char ch) {
		this->p[x] = ch;
	}

};
queue<int> xq;
queue<int> yq;

static int bx[] = { -1, 2, -1, 0 };
static int by[] = { 0, 0, -1, 2 };

pos bfs(int r, int c, pos po) {
	while (!xq.empty()) {
		int x = xq.front();
		int y = yq.front();
		xq.pop();
		yq.pop();
		bool chk = true;

		for (int i = 0; i < 4; i++) {
			x += bx[i];
			y += by[i];
			if (x >= 0 && x < c && y >= 0 && y < r) {
				if (po.p[y * c + x] == 'S') {
					po = pos(1);
					po.change(0, 'X');
					return po;
				}
				else if (po.p[y * c + x] == '.') {
					po.change(y * c + x, 'D');
				}
			}
			if (chk == false) break;
		}
	}
	return po;
}

int main() {

	int r, c;
	// r은 y축 c는 x축 길이
	cin >> r >> c;

	pos po(r * c + 1);

	string s;

	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int z = 0; z < c; z++) {
			po.p[i * c + z] = s[z];
			if (s[z] == 'W') {
				xq.push(z);
				yq.push(i);
			}
		}
	}
	po = bfs(r, c, po);
	if (po.p[0] == 'X') {
		cout << "0";
	}
	else {
		cout << "1\n";
		for (int i = 0; i < r; i++) {
			for (int z = 0; z < c; z++) {
				cout << po.p[i * c + z];
			}
			cout << "\n";
		}
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

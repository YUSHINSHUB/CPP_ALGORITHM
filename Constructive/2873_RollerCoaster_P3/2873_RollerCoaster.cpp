// 2873_RollerCoaster.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

	int r, c;
	cin >> r >> c;
	vector<vector<int>> line(r, vector<int>(c));

	string b1 = "";
	string b2 = "";

	for (int i = 0; i < r; i++) {
		for (int z = 0; z < c; z++) {
			cin >> line[i][z];
		}
	}

	// 가로줄 혹은 세로줄의 개수가 홀수일 경우 모든칸을 다 지날 수 있다.
	if (r % 2 == 1) {

		for (int i = 0; i < r; i++) {
			for (int z = 0; z < c - 1; z++) {
				b1.append("R");
			}
			i++;
			if (i >= r)
				break;
			else {
				b1.append("D");
			}
			for (int z = 0; z < c - 1; z++) {
				b1.append("L");
			}
			b1.append("D");
		}

	}
	else if (c % 2 == 1) {

		for (int i = 0; i < c; i++) {
			for (int z = 0; z < r - 1; z++) {
				b1.append("D");
			}
			i++;
			if (i == c)
				break;
			else {
				b1.append("R");
			}
			for (int z = 0; z < r - 1; z++) {
				b1.append("U");
			}
			b1.append("R");
		}

		// 가로줄, 세로줄 개수가 모두 짝수일 경우
	}
	else {
		int mi = 1001;
		int xpos = 0;
		int ypos = 0;
		int ra = 0;
		int rb = r - 1;
		int ct = 0;

		// 세로줄을 두줄단위로 나누어서 건너뛸 칸의 이전(b1), 이후(b2)로 나누어 입력한다.
		for (int i = 0; i < r; i += 2) {
			for (int z = 1; z < c; z += 2) {
				mi = min(mi, line[i][z]);
				if (line[i][z] == min(mi, line[i][z])) {
					ypos = i;
					xpos = z;
				}
			}
		}

		for (int i = 1; i < r; i += 2) {
			for (int z = 0; z < c; z += 2) {
				mi = min(mi, line[i][z]);
				if (line[i][z] == min(mi, line[i][z])) {
					ypos = i;
					xpos = z;
				}
			}
		}

		// 칸의 배치가 흑 백 일 경우 건너뛸 칸은 무조건 백색칸 중에 있기 때문에 위와 같은 방식으로 건너뛸 지점을 결정한다.
		//		      백 흑

		while (ra / 2 < ypos / 2 || rb / 2 > ypos / 2) {
			if (ra / 2 < ypos / 2) {
				for (int i = 0; i < c - 1; i++)
					b1.append("R");
				b1.append("D");
				for (int i = 0; i < c - 1; i++)
					b1.append("L");
				b1.append("D");
				ra += 2;
			}

			if (rb / 2 > ypos / 2) {
				for (int i = 0; i < c - 1; i++)
					b2.append("R");
				b2.append("D");
				for (int i = 0; i < c - 1; i++)
					b2.append("L");
				b2.append("D");
				rb -= 2;
			}
		}

		while (ct / 2 < xpos / 2) {
			b1.append("DRUR");
			ct += 2;
		}

		// 1 2 인 경우에 3을 건너뛰는 경우
		// 3 4
		if (xpos % 2 == 0) {
			b1.append("RD");
		}
		else { // 1 2 인 경우에 2를 건너뛰는 경우
			  // 3 4
			b1.append("DR");
		}
		ct += 1;

		while (ct < c - 1) {
			b1.append("RURD");
			ct += 2;
		}

	}
	reverse(b2.begin(), b2.end());
	cout << b1 << b2;

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

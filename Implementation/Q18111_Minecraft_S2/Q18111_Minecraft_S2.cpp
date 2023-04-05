// Q18111_Minecraft_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> pos(n, vector<int>(m));
	int maxf = 0;

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < m; z++) {
			cin >> pos[i][z];
			if (pos[i][z] > maxf) maxf = pos[i][z];
		}
	}

	vector<int> res(maxf + 1);
	int floor = 0;
	int temp = 0;
	int lotime = 2000000000;
	int pfl = 0;

	while (floor <= maxf) {
		temp = b;
		for (int i = 0; i < n; i++) {
			for (int z = 0; z < m; z++) {
				if (pos[i][z] > floor) {
					res[floor] += (pos[i][z] - floor) * 2;
					temp += pos[i][z] - floor;
				}
				else if (pos[i][z] < floor) {
					res[floor] += floor - pos[i][z];
					temp -= floor - pos[i][z];
				}
			}
		}
		if (temp >= 0 && res[floor] <= lotime) {
			lotime = res[floor];
			pfl = floor;
		}
		floor++;
	}

	cout << lotime << " " << pfl;

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

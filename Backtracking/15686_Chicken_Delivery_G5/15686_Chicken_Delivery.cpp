// 15686_Chicken_Delivery.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

#define MAX 3000;

static int n;
static int m;
static vector<pair<int, int>> chp;
static vector<pair<int, int>> hop;
//x좌표 y좌표가 필요하기 때문에 pair을 타입으로 하는 vector을 선언하였다.
static bool pick[13];
static int res;

static void bt(int sidx, int cnt) {
	int sum = 0;
	int temp = 0;
	int minim = MAX;
	if (cnt == m) {
		for (int z = 0; z < hop.size(); z++) {
			minim = MAX;
			for (int i = 0; i < chp.size(); i++) {
				if (pick[i]) {
					temp = abs(hop[z].second - chp[i].second) + abs(hop[z].first - chp[i].first);
					minim = min(temp, minim);
				}
			}
			sum += minim;
		}
		res = min(sum, res);
		return;
	}
	else {
		for (int i = sidx; i < chp.size(); i++) {
			if (!pick[i]) {
				pick[i] = true;
				bt(i + 1, cnt + 1);
				pick[i] = false;
			}
		}
	}
}

int main() {

	cin >> n >> m;
	res = 3000;
	int chc = 0;
	int hom = 0;
	int temp = 0;

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < n; z++) {
			cin >> temp;
			if (temp == 1) {
				hop.push_back(pair<int, int>(z, i));
				hom++;
			}
			else if (temp == 2) {
				chp.push_back(pair<int, int>(z, i));
				chc++;
			}
		}
	}

	bt(0, 0);

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

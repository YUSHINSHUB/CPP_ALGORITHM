// Q14889_Start_Link_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

static int n;
static int res = INT_MAX;
static int par[20][20];
static bool visited[20];

static void bt(int idx, int cnt) {
	if (cnt == n / 2) {
		int s = 0, l = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i] && visited[j])
					s += par[j][i];
				else if (!visited[i] && !visited[j])
					l += par[j][i];
			}
		}
		res = min(res, abs(s - l));
	}
	else {
		for (int i = idx; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				bt(i + 1, cnt + 1);
				visited[i] = false;
			}
		}
	}
}


int main()
{

	cin >> n;
	fill(visited, visited + n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> par[i][j];
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

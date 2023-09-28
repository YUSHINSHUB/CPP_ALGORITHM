// Q10971_TSP_2_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <climits>

using namespace std;


static int n;
static int res = INT_MAX;
static int tsp[10][10];
static bool visited[10];

static void bt(int cnt, int sum, int st, int bef) {
	if (cnt == n) {
		if (tsp[bef][st] == 0)
			return;
		else {
			sum += tsp[bef][st];
			res = min(res, sum);
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			// 해당 문제는 선택한 인덱스들의 순서가 바뀌면 결과도 바뀌기 때문에 모든 경우를 확인하기 위해
			// i를 0부터 시작한다.
			if (!visited[i]) {
				int temp = st;
				if (temp < 0)
					temp = i;
				else if (tsp[bef][i] == 0)
					continue;
				else
					sum += tsp[bef][i];
				visited[i] = true;
				bt(cnt + 1, sum, temp, i);
				visited[i] = false;
				if (bef >= 0)
					sum -= tsp[bef][i];
			}
		}
	}
}


int main()
{
	cin >> n;
	fill(visited, visited + n, false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tsp[i][j];
		}
	}

	bt(0, 0, -1, -1);

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

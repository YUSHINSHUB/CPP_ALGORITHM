// Q2110_Install_Router_G4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


static int get(int dist, vector<int>& home, int n) {

	int cur = 0;
	int temp = 1;

	for (int i = 1; i < n; i++) {
		if (home[i] - home[cur] >= dist) {
			cur = i;
			temp++;
		}
	}

	return temp;
}

int main()
{
	int n, c;
	cin >> n >> c;

	vector<int> home(n);

	for (int i = 0; i < n; i++) {
		cin >> home[i];
	}

	sort(home.begin(), home.end());

	int lo = 1; // 공유기 사이 최소거리의 최소값은 1로 잡는다.
	int hi = home[n - 1] - home[0] + 1; // 공유기 사이 최소거리의 최댓값 
	int md = (lo + hi) / 2; // 공유기 사이 최소거리의 중간값

	while (true) {

		if (get(md, home, n) < c) {
			//md만큼 거리를 최소거리로 두었을 때 공유기를 설치할 수 있는 집의 수가 c보다 적을 경우 거리를 줄여서 설치 가능한 집의 수를 늘려야 한다.
			hi = md;
			md = (hi + lo) / 2;
		}
		else {
			lo = md + 1;
			md = (hi + lo) / 2;
		}

		if (lo == hi) break;

	}

	cout << lo - 1;

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

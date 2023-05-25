
// Q11070_Pythagorean_Expectation_B1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> team(n, vector<int>(2));

		for (int j = 0; j < m; j++) {
			
			int a, b, c, d;
			cin >> a >> b >> c >> d;

			team[a - 1][0] += c;
			team[a - 1][1] += d;
			team[b - 1][0] += d;
			team[b - 1][1] += c;
		}

		vector<double> pe(n);

		for (int j = 0; j < n; j++) {
			if (team[j][0] == 0 && team[j][1] == 0) pe[j] = 0;
			else pe[j] = (pow(team[j][0], 2)) / (pow(team[j][0], 2) + pow(team[j][1], 2));
		}
		sort(pe.begin(), pe.end());

		cout << (int)(pe[n - 1] * 1000) << "\n" << (int)(pe[0] * 1000) << "\n";
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

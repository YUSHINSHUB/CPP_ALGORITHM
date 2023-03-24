// 1149_RGB_Street.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int dp[3001];

int recur(vector<int> fee, int cnt) {

	while (cnt >= 0) {
		dp[cnt * 3] = fee[cnt * 3] + min(dp[(cnt + 1) * 3 + 1], dp[(cnt + 1) * 3 + 2]);
		dp[cnt * 3 + 1] = fee[cnt * 3 + 1] + min(dp[(cnt + 1) * 3 + 0], dp[(cnt + 1) * 3 + 2]);
		dp[cnt * 3 + 2] = fee[cnt * 3 + 2] + min(dp[(cnt + 1) * 3 + 0], dp[(cnt + 1) * 3 + 1]);
		cnt--;
	}

	return min(dp[0], min(dp[1], dp[2]));

}

int main() {

	int n;
	cin >> n;
	vector<int> fee(n * 3);

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < 3; z++) {
			cin >> fee[i * 3 + z];
		}
	}

	dp[(n - 1) * 3 + 0] = fee[(n - 1) * 3 + 0];
	dp[(n - 1) * 3 + 1] = fee[(n - 1) * 3 + 1];
	dp[(n - 1) * 3 + 2] = fee[(n - 1) * 3 + 2];

	int cnt = (n - 2);

	int res = recur(fee, cnt);

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

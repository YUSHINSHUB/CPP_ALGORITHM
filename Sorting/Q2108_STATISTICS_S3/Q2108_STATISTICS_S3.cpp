// Q2108_STATISTICS_S3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

bool t(int a) {
	return true;
}

int main() {

	int n;
	cin >> n;

	vector<int> nums(n);
	int hap = 0;
	int hig = INT_MIN;
	int low = INT_MAX;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		hap += nums[i];
		hig = max(nums[i], hig);
		low = min(nums[i], low);
	}

	int hidx = 0;
	map<int, int> m;
	vector<int> hnum;

	for (int i = 0; i < n; i++) {
		if (m.find(nums[i]) != m.end()) m[nums[i]]++;
		else m.insert(pair<int, int>(nums[i], 1));

		if (m[nums[i]] > hidx) {
			hidx++;
			hnum.clear();
			hnum.push_back(nums[i]);
		}
		else if (m[nums[i]] == hidx) hnum.push_back(nums[i]);

	}

	int vcnt = count_if(hnum.begin(), hnum.end(), t);

	sort(nums.begin(), nums.end());
	sort(hnum.begin(), hnum.end());

	double a = (double)hap / (double)n;
	if (a > 0) a = floor(a + 0.5);
	else if (a < 0) a = ceil(a - 0.5);
	if (a == 0) cout << 0 << "\n";
	else cout << a << "\n";
	cout << nums[(n / 2)] << "\n";

	if (vcnt == 1) cout << hnum[0];
	else cout << hnum[1];

	cout << "\n" << hig - low;

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

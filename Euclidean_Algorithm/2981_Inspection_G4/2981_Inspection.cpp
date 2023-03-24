// 2981_Inspection.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int>cards(n);
	vector<int> nums(n - 1);

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	sort(cards.begin(), cards.end());

	for (int i = 1; i < n; i++) {
		nums[i - 1] = cards[i] - cards[i - 1];
	}

	// A, B, C가 있다. A = Ma + r, B = Mb + r일 떄 A와 B의 M과 r이 일치해야 하므로 
	// A - B = M(a-b)가 된다. A, B를 각각 M으로 나눈 몫인 a, b는 몇이든 상관이 없으므로 M은 A-B의 약수가 된다는 것에 집중한다.
	// 같은 논리로 M은 B-C의 약수도 된다. 즉 A-B. B-C의 공약수라는 뜻이며 최대공약수의 약수라는 것과 같은 말이 된다.
	// 6, 34, 38을 대입해 보면 28, 4의 최대 공약수인 4의 약수가 답이므로 2, 4라는 결과가 도출된다.

	sort(nums.begin(), nums.end());

	bool out = true;

	int gdc = 0;

	for (int j = nums[0]; j >= 0; j--) {
		out = true;
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] % j != 0) {
				out = false;
				break;
			}
		}
		if (out) {
			gdc = j;
			break;
		}
	}

	for (int i = 2; i < sqrt(gdc); i++) {
		if (gdc % i == 0) cout << i << " ";
	}

	for (int i = (int)sqrt(gdc); i >= 1; i--) {
		if (gdc % i == 0) cout << gdc / i << " ";
	}

	//위의 방법으로 약수찾는 반복회수를 극단적으로 줄일 수 있다.

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

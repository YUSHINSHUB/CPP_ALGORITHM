// Q1837_Create_PW_B3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


static int mod(string num, int a) {
	int result = 0;

	// 큰 수의 모듈러 연산 구현
	for (int i = 0; i < num.size(); i++)
		result = (result * 10 + (int)num[i] - '0') % a;

	return result;
}

int main()
{
	string n;
	int k;
	bool pass = false;

	cin >> n >> k;

	vector<int> chk(k);
	fill(chk.begin(), chk.end(), 0);
	chk[1] = 1;
	for (int i = 4; i < k; i += 2)
		chk[i] = 1;
	for (int i = 3; i < k; i += 2) {
		if (chk[i] == 0) {
			for (int j = i * 2; j < k; j += i)
				chk[j] = 1;
		}
	}
	// 0은 소수, 1은 소수 아님 (에라토스테네스의 체)

	for (int i = 2; i < k; i++) {
		if (chk[i] == 0) {
			if (mod(n, i) == 0) {
				cout << "BAD " << i;
				pass = true;
				break;
			}
		}
	}

	if (!pass)
		cout << "GOOD";
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

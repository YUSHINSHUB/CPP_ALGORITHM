// Q2755_GPA_B1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{

	int n;
	cin >> n;
	double sum = 0;
	int cls = 0;
	string s;
	int scr;
	string grd;

	for (int i = 0; i < n; i++) {
		cin >> s >> scr >> grd;
		if (grd ==("A+")) {
			sum += scr * 4.3;
		}
		else if (grd ==("A0")) {
			sum += scr * 4.0;
		}
		else if (grd ==("A-")) {
			sum += scr * 3.7;
		}
		else if (grd ==("B+")) {
			sum += scr * 3.3;
		}
		else if (grd ==("B0")) {
			sum += scr * 3.0;
		}
		else if (grd ==("B-")) {
			sum += scr * 2.7;
		}
		else if (grd ==("C+")) {
			sum += scr * 2.3;
		}
		else if (grd ==("C0")) {
			sum += scr * 2.0;
		}
		else if (grd ==("C-")) {
			sum += scr * 1.7;
		}
		else if (grd ==("D+")) {
			sum += scr * 1.3;
		}
		else if (grd ==("D0")) {
			sum += scr * 1.0;
		}
		else if (grd ==("D-")) {
			sum += scr * 0.7;
		}

		cls += scr;
	}

	sum /= cls;
	sum = round(sum * 100) / 100.0;
	sum += 0.000000000001;
	//예를들어 3.5의 경우 더 큰 범위를 표현하기 위해 3.499999999999 이 될 수 있다. 이 경우 반올림한 값에 오차가 생기게 된다.
	// 그러므로 0.000000000001을 더하여 부동소수점의 오차를 해결한다.

	cout.precision(2);
	cout << fixed << sum;
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

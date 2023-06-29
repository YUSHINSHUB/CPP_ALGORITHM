// Q25206_GRADE_S5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	double sum = 0;
	double per = 0;
	double temp;
	string grd;
	string s;
	int idx = 20;

	for (int i = 0; i < 20; i++) {

		cin >> s >> temp >> grd;

		if (grd != "P")
			per += temp;

		if (grd == "A0") {
			temp /= 4.5;
			temp *= 4;
		}
		else if (grd == "B+") {
			temp /= 4.5;
			temp *= 3.5;
		}
		else if (grd == "B0") {
			temp /= 4.5;
			temp *= 3;
		}
		else if (grd == "C+") {
			temp /= 4.5;
			temp *= 2.5;
		}
		else if (grd == "C0") {
			temp /= 4.5;
			temp *= 2;
		}
		else if (grd == "D+") {
			temp /= 4.5;
			temp *= 1.5;
		}
		else if (grd == "D0") {
			temp /= 4.5;
			temp *= 1;
		}
		else if (grd == "F" || grd == "P") {
			temp = 0;
		}

		sum += temp;

	}

	per = 4.5 / per;
	per *= sum;
	cout << per;
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

// Q2456_Im_Class_Leader_B1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{

	int n;
	cin >> n;

	int scr[3][3] = { 0 };

	int a, b, c;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		scr[0][0] += a;
		scr[1][0] += b;
		scr[2][0] += c;

		switch (a) {
		case 3:
			scr[0][1]++;
			break;
		case 2:
			scr[0][2]++;
			break;
		default:
			break;
		}

		switch (b) {
		case 3:
			scr[1][1]++;
			break;
		case 2:
			scr[1][2]++;
			break;
		default:
			break;
		}

		switch (c) {
		case 3:
			scr[2][1]++;
			break;
		case 2:
			scr[2][2]++;
			break;
		default:
			break;
		}

	}

	int res = 1;
	int out = 1;
	int hig = scr[0][0];

	for (int i = 1; i < 3; i++) {
		if (hig < scr[i][0]) {
			res = i + 1;
			out = i + 1;
			hig = scr[i][0];
		}
		else if (hig == scr[i][0]) {
			if (scr[res - 1][1] != scr[i][1]) {
				if (scr[res - 1][1] < scr[i][1]) {
					res = i + 1;
					out = i + 1;
				}
			}
			else if (scr[res - 1][2] != scr[i][2]) {
				if (scr[res - 1][2] < scr[i][2]) {
					res = i + 1;
					out = i + 1;
				}
			}
			else {
				out = 0;
			}
		}
	}

	cout << out << " " << hig;

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

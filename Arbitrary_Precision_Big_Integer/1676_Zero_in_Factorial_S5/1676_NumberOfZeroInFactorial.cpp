﻿// 1676_NumberOfZeroInFactorial.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	bool bp = true;

	char fac[3001];
	char ft[3001];

	int cnt = 0;

	int index = 0;
	int index2;

	int temp = 0;
	int tindex = 1;
	int tcount = 0;

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			fac[0] = '1';
		}
		else {

			index2 = index;

			for (int z = 0; z <= index; z++) {
				ft[z] = '0';
			}
			for (int z = 0; z <= index2; z++) {

				temp = ((fac[z] - '0') * i);
				while (temp / tindex != 0) {
					tindex *= 10;
					if (z + tcount > index) {
						index++;
						fac[index] = '0';
						ft[index] = '0';
					}
					ft[z + tcount] += temp % tindex / (tindex / 10);
					tcount++;
				}
				tindex = 1;
				tcount = 0;

			}

			for (int z = 0; z <= index; z++) {
				fac[z] = ft[z];
				ft[z] = '0';
				//자리별 연산을 fac[]로 바로 수행할 경우 뒷자리의 연산값이 10을 넘겨 앞자리로 넘어갔을 때
				// 더해진 앞자리의 값에 곱셈을 수행하므로 옳바른 팩토리얼 결과값이 나오지 않는다.
				// 더해진 값이 아니라 원래의 값에 곱셈을 수행해야 하므로 임시로 사용할 ft[]를 선언하여 !i의 값을
				// 임시로 담아둔 후 각 요소를 fac[]에 대입해주는 방식을 채택하였다.
			}
			//C++에서는 아스키코드를 활용할떄 127을 넘어가면 이상한 값이 들어가기 떄문에 넘지 않도록 각 자리별로 연산하는
			// 로직을 구성하였다.

			bp = true;
			while (bp == true) {
				bp = false;
				for (int x = 0; x <= index; x++) {
					if (fac[x] > '9') {
						bp = true;
						if (x == index) {
							index++;
							fac[x + 1] = '0';
							while (fac[x] > '9') {
								fac[x + 1] += 1;
								fac[x] -= 10;
							}
							break;
						}
						else {
							fac[x + 1] += 1;
							fac[x] -= 10;
							break;
						}
					}
				}
			}

		}
	}

	if (n != 0) {
		for (int i = 0; i <= index; i++) {
			if (fac[i] != '0') {
				break;
			}
			cnt++;
		}
	}

	cout << cnt;


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

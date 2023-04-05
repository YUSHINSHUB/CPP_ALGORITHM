// Q15841_Virus_Outbreak_B2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

	int temp;
	string fi[491];
	fi[0] = "0";
	fi[1] = "1";
	fi[2] = "1";
	int gap = 0;

	for (int i = 3; i <= 490; i++) {
		fi[i] = "";
		for (int z = 0; z <= fi[i - 1].length(); z++) {
			fi[i] += "0";
		}
		gap = fi[i - 1].length() - fi[i - 2].length();

		for (int z = fi[i - 1].length() - 1; z >= gap; z--) {
			fi[i][z + 1] += (fi[i - 2][z - gap] - 48) + (fi[i - 1][z] - 48);
			if (fi[i][z + 1] > '9') {
				fi[i][z + 1] -= 10;
				fi[i][z]++;
			}
		}

		if (gap == 1) {
			fi[i][1] += (int)(fi[i - 1][0] - 48);
			if (fi[i][1] > '9') {
				fi[i][1] -= 10;
				fi[i][0]++;
			}
		}

		if (fi[i][0] == '0') {
			string t = "";
			for (int z = 1; z < fi[i].length(); z++) {
				t += fi[i][z];
			}
			fi[i] = t;
		}
	}
	while (true) {
		cin >> temp;
		if (temp == -1) {
			break;
		}
		cout << "Hour " << temp << ": " << fi[temp] << " cow(s) affected\n";
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

// 10797_TenPartSystem.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main() {


	char day1[2];
	char* day2 = &day1[0];
	char cnums1[1001];
	char* cnums2;

	cin.getline(day1, 2);
	//포인터 day2가 day1을 가리키도록 선언했기 때문에 day1의 값을 바꾸면 day2의 값도 바꿀 수 있다.
	//한줄은 날짜를, 한줄은 차량번호를 입력받기 위해 cin.getline()을 사용한다. 
	// 그냥 cin을 사용할 경우 공백단위로 입력받기 때문에 안된다.

	int viol = 0;

	cin.getline(cnums1, 1000);

	cnums2 = strtok(cnums1, " ");
	//cnums1을 공백단위로 토큰화하여 cnums2에 담아준다.
	// char *strtok( char* str, const char* delimiters ) 

	while (cnums2 != NULL) {
		if (cnums2[0] == day2[0]) {
			viol++;
		}
		cnums2 = strtok(NULL, " ");
		//다음 토큰으로 넘어갈 때에는 strtok(NULL, " ")을 사용해준다.
	}



	cout << viol;

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

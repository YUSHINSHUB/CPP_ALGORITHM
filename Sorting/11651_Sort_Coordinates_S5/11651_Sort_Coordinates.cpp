// 11651_Sort_Coordinates.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
	int x;
	int y;
};


int main() {

	int t;
	cin >> t;

	vector<pos> ca(t);

	for (int i = 0; i < t; i++) {
		cin >> ca[i].x >> ca[i].y;
	}

	stable_sort(ca.begin(), ca.end(), [](pos o1, pos o2) -> bool {
		//C++의 람다함수에서는 반환받을 값의 type을 지정해 주어야 한다.
		if (o1.y == o2.y) {
			return o1.x < o2.x;
		}
		else {
			return o1.y < o2.y;
		}
		});
	//C++에서는 o1<o2인지의 여부를 true/false로 반환받기 떄문에 java와는 반대로 양수일 때 o1, o2순으로 정렬된다.


	for (int i = 0; i < t; i++) {
		printf("%d %d\n", ca[i].x, ca[i].y);
		//표준형 cout는 시간이 초과되기 때문에 printf로 출력하였다.
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

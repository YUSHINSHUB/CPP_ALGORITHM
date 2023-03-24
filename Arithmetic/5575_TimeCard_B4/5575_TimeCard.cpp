// 5575_TimeCard.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct myInt {
	// C++의 Struct는 Class의 하위기능이지만 사용법은 유사하다
	int sh, sm, ss;
	int eh, em, es;

	int st;
	int et;

	void getTime() {
		st = (sh * 3600) + (sm * 60) + ss;
		et = (eh * 3600) + (em * 60) + es - st;
	}

	myInt(int a, int b, int c, int d, int e, int f) {
		sh = a; sm = b; ss = c;
		eh = d; em = e; es = f;
	}

};

int main() {

	int aa, ab, ac, ad, ae, af;
	int ba, bb, bc, bd, be, bf;
	int ca, cb, cc, cd, ce, cf;

	cin >> aa >> ab >> ac >> ad >> ae >> af;
	cin >> ba >> bb >> bc >> bd >> be >> bf;
	cin >> ca >> cb >> cc >> cd >> ce >> cf;

	myInt a = myInt(aa, ab, ac, ad, ae, af);
	myInt b = myInt(ba, bb, bc, bd, be, bf);
	myInt c = myInt(ca, cb, cc, cd, ce, cf);

	a.getTime(); b.getTime(); c.getTime();

	cout << a.et / 3600 << " " << (a.et % 3600) / 60 << " " << a.et % 60 << endl;
	cout << b.et / 3600 << " " << (b.et % 3600) / 60 << " " << b.et % 60 << endl;
	cout << c.et / 3600 << " " << (c.et % 3600) / 60 << " " << c.et % 60;

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

// 10757_AplusB_BigNumber.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{

	string a;
	string b;
	string res = "";
	int frt = 0;

	cin >> a >> b;


	if (a.length() > b.length()) {
		string x = a;
		a = b;
		b = x;
	}

	int gap = b.length() - a.length();

	for (int i = 1; i <= a.length(); i++) {
		int x = (a[a.length() - i] - '0') + (b[a.length() - i + gap] - '0') + frt;
		string str = to_string(x);
		res.push_back(str[str.length() - 1]);
		//일의자리부터 순차적으로 구하여 res에 push_back 해준다. 
		if (str.length() != 1) {
			frt = str[0] - '0';
			//각 자리의 합산값이 10이 넘을경우 뒷자리만 push해주고 앞자리는 frt에 담아서 다음 반복회차로 넘겨준다.
		}
		else {
			frt = 0;
		}
	}


	for (int i = 1; i <= gap; i++) {
		int x = (b[gap - i] - '0') + frt;
		string str = to_string(x);
		res.push_back(str[str.length() - 1]);
		if (str.length() != 1) {
			frt = str[0] - '0';
		}
		else {
			frt = 0;
		}
	} //a와 b의 자릿수가 다를 경우 a의 자릿수만큼 연산한 후 더 자릿수가 긴 b의 앞자리들이 남기때문에 마저 연산해준다.

	if (frt != 0) {
		res.push_back(to_string(frt)[0]);
	}
	// a와 b의 자릿수가 같을 경우 최종적으로 앞자리가 남을 수 있기 때문에 남은 frt값을 push해준다.

	for (int i = 1; i <= res.length(); i++) {
		cout << res[res.length() - i];
	}
	//push_back은 문자열의 뒤에 push해주기 때문에 반복문을 사용하여 뒤부터 출력해준다.
	
	

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

/*
commented by ChatGPT
This C++ code calculates the time difference between two given times in a 24-hour format.
It reads two time inputs in HH:MM:SS format, calculates the difference, and outputs it in the same format.
If the start and end times are the same, it outputs 24:00:00, representing a full day.
The code handles scenarios where the end time is the next day or when subtracting smaller units (seconds, minutes) results in negative values by adjusting the larger units (minutes, hours) accordingly.

이 C++ 코드는 24시간 형식으로 주어진 두 시간 사이의 시간 차이를 계산합니다.
HH:MM:SS 형식의 두 시간 입력을 받아 차이를 계산하고 동일한 형식으로 출력합니다.
시작 시간과 종료 시간이 동일한 경우, 하루 전체를 나타내는 24:00:00을 출력합니다.
코드는 종료 시간이 다음 날인 경우나 더 작은 단위(초, 분)를 빼서 음수가 되는 경우를 처리하여, 더 큰 단위(분, 시)를 적절히 조정합니다.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int sh, sm, ss; // 시작 시간의 시, 분, 초
	int eh, em, es; // 종료 시간의 시, 분, 초
	string inp;

	// 시작 시간 입력 받기
	getline(cin, inp);
	sh = stoi(inp.substr(0, 2));
	sm = stoi(inp.substr(3, 2));
	ss = stoi(inp.substr(6, 2));

	// 종료 시간 입력 받기
	getline(cin, inp);
	eh = stoi(inp.substr(0, 2));
	em = stoi(inp.substr(3, 2));
	es = stoi(inp.substr(6, 2));

	// 시작 시간과 종료 시간이 동일한 경우 24시간으로 설정
	if (eh == sh && em == sm && es == ss) {
		eh = 24;
		em = 0;
		es = 0;
	}
	else {
		// 시간 차이 계산
		eh -= sh;
		em -= sm;
		es -= ss;

		// 초 계산 시 음수가 되는 경우 분에서 조정
		if (es < 0) {
			em--;
			es += 60;
		}

		// 분 계산 시 음수가 되는 경우 시에서 조정
		if (em < 0) {
			eh--;
			em += 60;
		}

		// 시 계산 시 음수가 되는 경우 24시간에서 조정
		if (eh < 0) {
			eh += 24;
		}
	}

	// 결과 출력
	cout.width(2);
	cout.fill('0');
	cout << eh << ":";
	cout.width(2);
	cout.fill('0');
	cout << em << ":";
	cout.width(2);
	cout.fill('0');
	cout << es;
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

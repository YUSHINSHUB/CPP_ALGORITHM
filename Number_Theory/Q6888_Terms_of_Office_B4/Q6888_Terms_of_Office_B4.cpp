/*
commented by ChatGPT
This C++ program prints the years within a given range where "all positions change."
This is typically associated with a cycle or tradition that repeats every 60 years.
이 C++ 프로그램은 주어진 범위 내에서 "모든 위치가 변경되는" 연도를 출력합니다.
이것은 일반적으로 60년마다 반복되는 주기나 전통과 관련이 있습니다.
*/

#include <iostream>

using namespace std;

int main()
{
	// Declare the starting and ending year variables (시작 연도와 끝 연도 변수 선언)
	int X, Y;
	// Read the starting year from user input (사용자 입력으로부터 시작 연도를 읽음)
	cin >> X;
	// Read the ending year from user input (사용자 입력으로부터 끝 연도를 읽음)
	cin >> Y;

	// Loop from the starting year to the ending year (시작 연도부터 끝 연도까지 반복)
	while (X <= Y) {
		// Output the years when all positions change to the console (모든 위치가 변경되는 연도를 콘솔에 출력)
		cout << "All positions change in year " << X << "\n";
		// Increase the year by 60 to get to the next occurrence (다음 발생으로 이동하기 위해 연도를 60 증가)
		X += 60;
	}

	// The program does not explicitly return a value, but returns 0 by default to signal successful completion (프로그램은 명시적으로 값을 반환하지 않지만, 성공적인 완료를 신호하기 위해 기본적으로 0을 반환)
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

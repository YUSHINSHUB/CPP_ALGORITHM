/*
commented by ChatGPT
This C++ program reads three input strings and calculates the longest consecutive character sequence in each string. 
It iterates through each character in a string, compares it with the previous character, and counts the length of the consecutive sequence. 
If a different character is encountered, the count resets. 
The program outputs the maximum count of any repeating character for each input string.
이 C++ 프로그램은 세 개의 입력 문자열을 읽고 각 문자열에서 가장 긴 연속 문자 시퀀스를 계산합니다. 
문자열의 각 문자를 순회하면서 이전 문자와 비교하고 연속 시퀀스의 길이를 계산합니다. 
다른 문자가 나타나면 카운트가 초기화됩니다. 
프로그램은 각 입력 문자열에 대해 반복되는 문자의 최대 개수를 출력합니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	string in;
	for (int i = 0; i < 3; i++) { // 각 줄에 대하여 실행
		cin >> in; // 한 줄을 입력 받음
		int idx = 1; // 연속된 문자의 현재 길이를 나타내는 변수
		int res = 1; // 최대 연속 문자 길이를 저장하는 변수

		for (int j = 1; j < 8; j++) { // 문자열의 각 문자를 순회
			if (in[j] == in[j - 1]) { // 현재 문자가 이전 문자와 같다면
				idx++; // 연속 길이 증가
				res = max(res, idx); // 최대값 갱신
			}
			else {
				idx = 1; // 다른 문자가 나오면 연속 길이를 1로 초기화
			}
		}
		cout << res << "\n"; // 가장 긴 연속 길이를 출력
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

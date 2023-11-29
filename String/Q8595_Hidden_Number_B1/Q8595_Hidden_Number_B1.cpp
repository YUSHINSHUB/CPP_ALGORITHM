/*
commented by ChatGPT
This C++ code reads an input string and calculates the sum of all the numbers present in the string.
It iterates through each character of the string, checking if it's a digit.
If a digit is found, it's appended to a temporary string.
When a non-digit character is encountered or the end of the string is reached, the code converts the collected digits into an integer and adds it to the total sum.
Finally, the code outputs the total sum of all numbers found in the string.
이 C++ 코드는 입력 문자열을 읽고 문자열에 있는 모든 숫자의 합을 계산합니다.
문자열의 각 문자를 순회하면서 숫자인지 확인합니다.
숫자가 발견되면 임시 문자열에 추가됩니다.
숫자가 아닌 문자를 만나거나 문자열의 끝에 도달하면, 코드는 모아둔 숫자들을 정수로 변환하여 총 합에 더합니다.
마지막으로 코드는 문자열에서 찾은 모든 숫자의 총 합을 출력합니다.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n; // 입력 문자열의 길이를 읽음
	string s;
	cin >> s; // 입력 문자열을 읽음
	string sb = ""; // 숫자를 저장할 임시 문자열
	long long res = 0; // 숫자의 합을 저장할 변수

	for (int i = 0; i < n; i++) { // 문자열의 각 문자에 대해 반복
		if (s[i] >= '0' && s[i] <= '9') { // 현재 문자가 숫자라면
			sb += s[i]; // 임시 문자열에 추가
		}
		else if (sb != "") { // 숫자가 아니고, 임시 문자열에 숫자가 저장되어 있으면
			res += stoi(sb); // 문자열을 정수로 변환하여 res에 더함
			sb = ""; // 임시 문자열 초기화
		}
	}

	// 마지막 숫자 처리
	if (sb != "") {
		res += stoi(sb); // 마지막으로 저장된 숫자를 합계에 더함
	}

	cout << res; // 결과 출력
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

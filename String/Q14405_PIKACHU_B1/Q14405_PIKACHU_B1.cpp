/*
commented by ChatGPT
This C++ code checks whether a given string follows a specific pattern or not.
The input string can only contain sequences of "pi", "ka", or "chu". The program iterates over each character of the string, checking if it forms a valid sequence as per the given pattern.
If any sequence does not match "pi", "ka", or "chu", or if the string ends prematurely, the program outputs "NO".
If the entire string follows the pattern, it outputs "YES".
이 C++ 코드는 주어진 문자열이 특정 패턴을 따르는지 확인합니다.
입력 문자열에는 "pi", "ka", "chu"의 연속만 포함될 수 있습니다.
프로그램은 문자열의 각 문자를 순회하면서 주어진 패턴에 따라 유효한 시퀀스를 형성하는지 확인합니다.
어떤 시퀀스도 "pi", "ka", "chu"와 일치하지 않거나 문자열이 조기에 끝나면 프로그램은 "NO"를 출력합니다.
전체 문자열이 패턴을 따르면 "YES"를 출력합니다.
*/

#include <iostream>

using namespace std;

int main()
{
	string in;
	string res = "YES"; // 결과를 "YES"로 초기화

	cin >> in;

	for (int i = 0; i < in.length(); i++) { // 문자열의 각 문자에 대해 반복

		// 마지막 문자일 경우 "NO"로 설정하고 반복문 종료
		if (i == in.length() - 1) {
			res = "NO";
			break;
		}

		// "pi" 시퀀스 검사
		if (in[i] == 'p') {
			if (in[i + 1] == 'i')
				i++; // "pi"가 맞으면 다음 문자로 넘어감
			else {
				res = "NO"; // "pi"가 아니면 "NO"로 설정하고 반복문 종료
				break;
			}
		}
		// "ka" 시퀀스 검사
		else if (in[i] == 'k') {
			if (in[i + 1] == 'a')
				i++; // "ka"가 맞으면 다음 문자로 넘어감
			else {
				res = "NO"; // "ka"가 아니면 "NO"로 설정하고 반복문 종료
				break;
			}
		}
		// "chu" 시퀀스 검사
		else if (in[i] == 'c') {
			if (i == in.length() - 2) {
				res = "NO"; // 문자열이 "ch"로 끝나면 "NO"로 설정하고 반복문 종료
				break;
			}
			else if (in[i + 1] == 'h' && in[i + 2] == 'u')
				i += 2; // "chu"가 맞으면 두 문자를 넘어감
			else {
				res = "NO"; // "chu"가 아니면 "NO"로 설정하고 반복문 종료
				break;
			}
		}
		// 위 세 경우 모두 해당하지 않으면 "NO"로 설정하고 반복문 종료
		else {
			res = "NO";
			break;
		}

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

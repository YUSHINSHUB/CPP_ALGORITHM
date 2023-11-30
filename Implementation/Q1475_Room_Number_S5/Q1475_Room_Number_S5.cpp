/*
commented by ChatGPT
This C++ code calculates the minimum number of sets required to represent a given room number, considering each set contains digits from 0 to 9.
It treats '6' and '9' as interchangeable digits.
The program iterates over the input room number string and counts the occurrence of each digit.
For all digits except '6' and '9', the count is doubled.
For '6' and '9', it increments a shared count.
The maximum count among all digits, considering the interchangeability of '6' and '9', determines the minimum number of sets required.
The program accounts for odd counts by adding an extra set for the remaining digit.
이 C++ 코드는 각 세트에 0부터 9까지의 숫자가 포함된다고 가정할 때 주어진 방 번호를 나타내는 데 필요한 최소 세트 수를 계산합니다.
'6'과 '9' 숫자는 서로 바꿔 사용할 수 있다고 처리합니다.
프로그램은 입력된 방 번호 문자열을 순회하며 각 숫자의 발생 횟수를 계산하고, '6'과 '9'를 제외한 모든 숫자에 대해서는 그 수를 두 배로 셉니다.
'6'과 '9'의 경우 같은 카운트를 증가시킵니다.
'6'과 '9'의 상호 교환 가능성을 고려한 모든 숫자 중 가장 많은 카운트가 최소 세트 수를 결정합니다.
홀수 카운트의 경우 남은 숫자에 대해 추가 세트가 필요합니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	string in; // 입력받을 방 번호 문자열
	int cnt[9]; // 각 숫자의 카운트를 저장할 배열
	int hig = 0; // 필요한 세트의 최대 수

	cin >> in; // 방 번호 입력 받음
	fill(cnt, cnt + 9, 0); // 카운트 배열 초기화

	for (int i = 0; i < in.length(); i++) { // 방 번호의 각 숫자에 대해 반복
		if (in[i] == '6' || in[i] == '9') { // '6' 또는 '9'인 경우
			cnt[6]++; // '6'의 카운트를 증가시킴 (6과 9는 서로 교환 가능)
			hig = max(hig, cnt[6]); // 필요한 세트의 최대 수 갱신
		}
		else { // 그 외 숫자인 경우
			cnt[in[i] - '0'] += 2; // 해당 숫자의 카운트를 2 증가시킴
			hig = max(hig, cnt[in[i] - '0']); // 필요한 세트의 최대 수 갱신
		}
	}

	// 최대 카운트가 홀수인 경우 하나의 세트를 추가로 필요로 함
	if (hig % 2 == 1)
		hig = hig / 2 + 1;
	else
		hig /= 2; // 짝수인 경우 그대로 반으로 나눔

	cout << hig; // 결과 출력
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

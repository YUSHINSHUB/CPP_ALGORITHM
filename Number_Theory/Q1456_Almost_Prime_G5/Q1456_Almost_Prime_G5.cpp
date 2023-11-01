/*
commented by ChatGPT
This C++ code determines the count of "almost prime" numbers between two given numbers A and B. An "almost prime" number is defined as a number that can be expressed as the power of a prime number with the exponent at least 2.
이 C++ 코드는 주어진 두 숫자 A와 B 사이에 있는 "거의 소수"의 개수를 결정합니다. "거의 소수"란 지수가 최소 2 이상인 소수의 거듭제곱으로 표현될 수 있는 숫자를 의미합니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// A와 B를 입력받음
	long long A, B;
	cin >> A >> B;

	// B의 제곱근을 계산하고 1을 더하여 배열의 크기를 결정함
	int sq = (int)sqrt(B) + 1;
	int era[10000001]; // 에라토스테네스의 체를 위한 배열
	int res = 0; // 거의 소수의 개수를 세기 위한 변수

	// 에라토스테네스의 체를 사용하기 위해 배열을 0으로 초기화
	fill(era, era + sq, 0);
	era[0] = 1; // 0은 소수가 아님을 표시
	era[1] = 1; // 1은 소수가 아님을 표시

	// 2부터 시작하여 체를 걸러 소수를 찾음
	for (int i = 2; i < sq; i++) {
		if (era[i] == 0) { // 소수인 경우
			for (int j = i * 2; j < sq; j += i) {
				era[j] = 1; // 소수의 배수는 소수가 아님을 표시
			}
		}
	}

	// 거의 소수를 찾기 위한 반복문
	for (long long i = 2; i < sq; i++) {
		if (era[(int)i] == 0) { // 소수인 경우
			long long temp = i * i; // 소수의 제곱부터 시작
			while (true) {
				if (temp >= A) { // A 이상이면 카운트 증가
					res++;
				}
				if (temp > B / i) // B를 넘어서는 순간 반복문 종료
					break;
				temp *= i; // 다음 거듭제곱을 계산
			}
		}
	}

	// 결과 출력
	cout << res;
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

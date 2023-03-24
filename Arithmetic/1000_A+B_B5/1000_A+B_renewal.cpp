// 1000_A+B_renewal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
//#include <stdio.h>
// C++에서는 iostream 헤더에 정의되어 있는 cin, cout가 표준 입출력이다.

int main() {

	int a = 0;
	int b = 0;

	std::cin >> a >> b;
	//cin에서는 공백을 기준으로 여러개의 값을 입력 받을 수 있다.

	std::cout << a + b;

}
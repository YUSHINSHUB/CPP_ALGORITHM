/*
commented by ChatGPT
This C++ code calculates the final price after applying discounts based on the quantity of items purchased (N) and the original price (P).
The program applies different levels of discounts for various purchase quantities: 20 items or more, 15 items or more, 10 items or more, and 5 items or more.
The discounts include a percentage off the original price, a fixed amount off, or both. The code ensures that the final price does not go below zero.

이 C++ 코드는 구매한 항목 수(N)와 원래 가격(P)에 따라 할인된 최종 가격을 계산합니다.
프로그램은 다양한 구매 수량에 대해 다른 수준의 할인을 적용합니다: 20개 이상, 15개 이상, 10개 이상, 5개 이상.
할인에는 원래 가격에 대한 백분율 할인, 일정 금액 할인 또는 둘 다 포함됩니다.
이 코드는 최종 가격이 0보다 낮아지지 않도록 보장합니다.
*/

#include <iostream>

using namespace std;

int main()
{
	int N, P; // N: 구매한 항목 수, P: 원래 가격
	int res; // 결과 할인 가격

	cin >> N >> P; // 구매한 항목 수와 원래 가격 입력 받기
	res = P; // 할인 전 가격으로 초기화

	// 할인 조건에 따라 할인된 가격 계산
	if (N >= 20) {
		res = min(res, (P / 4) * 3); // 25% 할인
		res = min(res, P - 2000); // 2000원 할인
		res = min(res, (P / 10) * 9); // 10% 할인
	}
	else if (N >= 15) {
		res = min(res, P - 2000); // 2000원 할인
		res = min(res, (P / 10) * 9); // 10% 할인
	}
	else if (N >= 10) {
		res = min(res, (P / 10) * 9); // 10% 할인
		res = min(res, P - 500); // 500원 할인
	}
	else if (N >= 5) {
		res -= 500; // 500원 할인
	}

	if (res < 0) // 할인 가격이 음수가 되지 않도록 보장
		res = 0;

	cout << res; // 결과 출력
}
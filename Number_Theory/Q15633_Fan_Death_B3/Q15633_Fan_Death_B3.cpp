/*
commented by ChatGPT
This C++ program calculates the sum of all positive divisors of a given number, multiplies it by 5, and then subtracts 24.
The result is then printed to the standard output.
이 C++ 프로그램은 주어진 수의 모든 양의 약수의 합을 계산하고, 그것에 5를 곱한 다음 24를 빼서 결과를 표준 출력에 출력합니다.
*/

#include <iostream>
#include <cmath> // Include cmath for the sqrt function (sqrt 함수를 사용하기 위해 cmath 포함)

using namespace std;

int main() {

	// Declare the variable to store the input number (입력 숫자를 저장할 변수 선언)
	int n;
	cin >> n; // Read the input number from the user (사용자로부터 입력 숫자를 읽음)
	// Initialize the result variable (결과 변수 초기화)
	int res = 0;

	// Loop over all possible divisors up to the square root of n (n의 제곱근까지 모든 가능한 약수에 대해 반복)
	for (int i = 1; i <= sqrt(n); i++) {
		// If i is a divisor of n (i가 n의 약수인 경우)
		if (n % i == 0) {
			// Add the divisor to the result (약수를 결과에 추가)
			res += i;
			// Add the quotient to the result unless it's the same as the divisor (약수와 같지 않은 경우 몫을 결과에 추가)
			res += n / i;
			// If the divisor and quotient are the same, subtract it once as it was added twice (약수와 몫이 같은 경우, 두 번 추가된 것을 한 번 빼줌)
			if (i == n / i)
				res -= i;
		}
	}

	// Calculate the final result by multiplying by 5 and subtracting 24 (최종 결과를 5를 곱하고 24를 빼서 계산)
	cout << res * 5 - 24;

	// Since we are using cout, there's no need to flush as it's automatically flushed at program end or with '\n' (cout을 사용하기 때문에 프로그램 끝나거나 '\n'을 만났을 때 자동으로 flush되므로 flush할 필요 없음)
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

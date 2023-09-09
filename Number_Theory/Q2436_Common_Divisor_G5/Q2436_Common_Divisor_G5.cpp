/*
commented by ChatGPT
Summary: A program to determine two numbers whose GCD is 'a' and LCM is the product of 'a' and 'b', where these numbers are within the range of 'a' to the square root of 'a*b'.
*/

#include <iostream>
#include <cmath> // Needed for the sqrt function.
using namespace std;

// Recursive function to calculate the GCD (Greatest Common Divisor) of two numbers.
int check(long long a, long long b) {
	int m = (int)(a % b);
	if (m == 0)
		return (int)b;

	return check(b, m);
}

int main()
{
	int a, b;
	cin >> a >> b;

	// Calculate the product of 'a' and 'b', which will be used as LCM in the logic.
	long long mul = (long long)a * (long long)b;

	// Initialize the variables to store the resulting numbers.
	long long res1 = 0, res2 = 0;

	/*
	Loop over numbers starting from 'a' to the square root of 'mul' incrementing by 'a'.
	For each number, if it's a divisor of 'mul' (factor of LCM) and the GCD of the number and the corresponding divisor of 'mul' is 'a',
	then update the variables 'res1' and 'res2' with the required values.
	*/

	for (int i = a; i <= sqrt(mul); i += a) {
		if (mul % i == 0 && check(mul / i, i) == a) {
			res1 = i;
			res2 = mul / i;
		}
	}

	// Output the resulting numbers.
	cout << res1 << " " << res2;
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

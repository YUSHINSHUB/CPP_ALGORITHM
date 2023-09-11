/*
   commented by ChatGPT
   Summary: The C++ program reads a series of number triplets, calculates the squared value
   of the largest number and the squared sum of the other two, then prints the results.
*/

#include <iostream>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	// Declaration of necessary variables
	int n;
	long long a, b, c, res;

	// Read the number of test cases from standard input
	cin >> n;

	// Loop through each test case
	for (int i = 0; i < n; i++) {
		// Read values of a, b, and c from standard input
		cin >> a >> b >> c;

		// Compute the largest number among a, b, and c
		long long big = max(a, max(b, c));

		// Calculate the sum of a, b, and c, then subtract the largest number from this sum
		long long sum = a + b + c;
		sum -= big;

		// Calculate the result as the square of the largest number added to the square of the sum
		res = (big * big) + (sum * sum);

		// Print the result to standard output
		cout << res << "\n";
	}

	return 0; // Optionally, include a return statement to denote successful program completion
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

// Commented by ChatGPT
// Summary: This C++ program calculates the minimum number of coins needed to make a given amount 'k' using a list of 'n' coin denominations.

#include <iostream>
#include <vector>
using namespace std;

int main() {

	// Improve the efficiency of input and output streams.
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// Declare and input 'n' (the number of coin denominations) and 'k' (the target amount).
	int n;
	int k;
	cin >> n >> k;

	// Declare a vector to store the coin denominations.
	vector<int> coin(n);

	// Declare variables for output and summation.
	int out = 0;
	int sum = 0;

	// Input the coin denominations and store them in the 'coin' vector.
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	// Iterate over the coin denominations in reverse order.
	for (int i = n - 1; i >= 0; i--) {
		// Increment the output counter by the quotient of 'k' and the current coin denomination.
		out += k / coin[i];
		// Update the value of 'k' with the remainder.
		k %= coin[i];
	}

	// Output the final result, which is the minimum number of coins needed to make the target amount.
	cout << out;

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

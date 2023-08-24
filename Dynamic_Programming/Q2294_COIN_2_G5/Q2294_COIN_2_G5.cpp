//Commented by ChatGPT
//Summary: This code determines the minimum number of coins needed to make up the total value 'k' given 'n' coin denominations.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	// `n` represents the number of coin denominations and `k` is the desired total
		// value.
	int n, k;
	// Array to hold the coin denominations.
	int coin[100];
	// Memory table to store the minimum coins required for each value up to `k`.
	int mem[110001];

	// Splitting the input line to get `n` and `k` values.
	cin >> n >> k;

	// Initialize the memory table to -1, indicating value is not yet computed.
	fill(mem, mem + 110001, -1);

	// Read each coin denomination from input.
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		// Directly mark that the specific denomination can be achieved using one coin.
		mem[coin[i]] = 1;
	}

	// Populate the memoization table using a bottom-up approach.
	for (int i = 1; i <= k; i++) {
		// If current value `i` can be achieved using the coins read.
		if (mem[i] > 0) {
			// Check for each coin denomination.
			for (int j = 0; j < n; j++) {
				// If the combination value hasn't been seen before, mark it as achievable.
				if (mem[i + coin[j]] < 0)
					mem[i + coin[j]] = mem[i] + 1;
				// If the combination value was seen before, update to the minimum coins
				// required.
				else
					mem[i + coin[j]] = min(mem[i + coin[j]], mem[i] + 1);
			}
		}
	}

	// Output the minimum coins required for the total value `k`.
	cout << mem[k];

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

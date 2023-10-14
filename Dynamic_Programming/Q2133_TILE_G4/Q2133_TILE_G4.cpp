/*
commented by ChatGPT
이 C++ 코드는 3xN 크기의 벽을 2x1, 1x2 크기의 타일로 채우는 경우의 수를 계산합니다.
동적 프로그래밍을 사용하여 효율적으로 문제를 해결합니다.
This C++ code calculates the number of ways to fill a 3xN sized wall using 2x1 and 1x2 sized tiles.
It efficiently solves the problem using dynamic programming.
*/

#include <iostream>

using namespace std;

int dp[31]; // 메모이제이션을 위한 배열 (Array for memoization)
bool visited[31]; // 해당 인덱스의 계산 여부를 확인하기 위한 배열 (Array to check if the calculation for an index is done or not)

static int recur(int idx) {

	// 이미 계산된 idx 값일 경우 바로 반환 (If the value for idx is already calculated, return it)
	if (visited[idx])
		return dp[idx];
	else {
		visited[idx] = true;
		// 타일링 방법 계산 (Calculate tiling ways)
		dp[idx] = recur(idx - 2) * 3;
		for (int i = idx - 4; i >= 0; i -= 2) {
			dp[idx] += recur(i) * 2;
		}
		return dp[idx];
	}
}

int main()
{
	int n;
	cin >> n; // 사용자로부터 벽의 크기 N을 입력받습니다. (Input the size of the wall N from the user)
	dp[0] = 1; // 기본값 설정 (Set the base value)
	visited[0] = true;

	// n이 홀수일 경우 타일로 채울 수 없으므로 0 출력 (If n is odd, output 0 since it's not possible to fill with tiles)
	if (n % 2 != 0)
		cout << "0";
	else
		cout << recur(n);  // 3xN 크기 벽을 타일로 채우는 방법의 수 출력 (Output the number of ways to fill the 3xN wall with tiles)
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

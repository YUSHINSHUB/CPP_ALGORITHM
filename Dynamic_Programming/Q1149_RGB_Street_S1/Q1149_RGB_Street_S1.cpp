//The objective of this problem is to color all houses such that no two adjacent houses have the same color with 
//the minimum total cost. 
//The problem is solved using dynamic programming, 
//where we calculate and store the minimum cost of painting each house in the dp array. 
//This information is then utilized in computing the minimum cost for the other houses. 
//The program reads the number of houses and the cost of painting each house with each color from the user, 
//calculates the minimum cost of painting all houses with the defined conditions, and then prints this minimum 
//cost.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int dp[3001];

// Recursive function to find the minimum cost of painting the houses
int recur(vector<int> fee, int cnt) {

	// The loop will run until it reaches the first house
	while (cnt >= 0) {
		// For each house, calculate and store the minimum cost when painted with a specific color
		// The cost is the sum of the painting cost of the current house and the minimum cost of painting the next house with a different color
		dp[cnt * 3] = fee[cnt * 3] + min(dp[(cnt + 1) * 3 + 1], dp[(cnt + 1) * 3 + 2]);
		dp[cnt * 3 + 1] = fee[cnt * 3 + 1] + min(dp[(cnt + 1) * 3 + 0], dp[(cnt + 1) * 3 + 2]);
		dp[cnt * 3 + 2] = fee[cnt * 3 + 2] + min(dp[(cnt + 1) * 3 + 0], dp[(cnt + 1) * 3 + 1]);
		cnt--;
	}

	// Return the minimum cost among the costs of painting the first house with three different colors
	return min(dp[0], min(dp[1], dp[2]));

}

int main() {

	int n;
	cin >> n;
	vector<int> fee(n * 3);

	// Input the cost of painting each house with three different colors
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < 3; z++) {
			cin >> fee[i * 3 + z];
		}
	}

	// Initialize the minimum cost of painting the last house with three different colors
	dp[(n - 1) * 3 + 0] = fee[(n - 1) * 3 + 0];
	dp[(n - 1) * 3 + 1] = fee[(n - 1) * 3 + 1];
	dp[(n - 1) * 3 + 2] = fee[(n - 1) * 3 + 2];

	int cnt = (n - 2);

	int res = recur(fee, cnt);

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

// Q9465_STICKER_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<vector<int>> st(2, vector<int>(n));

		// Read the scores of the stickers in the first row
		for (int j = 0; j < n; j++) {
			cin >> st[0][j];
		}

		// Read the scores of the stickers in the second row
		for (int j = 0; j < n; j++) {
			cin >> st[1][j];
		}

		// Special case handling for the first column

		if (n > 1) {
			// The score of the second sticker in the first column is increased by the score
			// of the first sticker in the second column
			st[0][1] += st[1][0];
			// Similarly, the score of the second sticker in the second column is increased
			// by the score of the first sticker in the first column
			st[1][1] += st[0][0];
		}

		// Calculate the maximum score for each subsequent column
		for (int j = 2; j < n; j++) {
			// The maximum score of a sticker is either the sum of its score and the maximum
			// score of the sticker in the previous column of the other row,
			// or the sum of its score and the maximum score of the sticker in the second
			// previous column of the other row
			st[0][j] = max(st[1][j - 1] + st[0][j], st[1][j - 2] + st[0][j]);
			st[1][j] = max(st[0][j - 1] + st[1][j], st[0][j - 2] + st[1][j]);
		}

		// Output the maximum score
		cout << max(st[0][n - 1], st[1][n - 1]) << "\n";
	}
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

/*
commented by ChatGPT
This C++ code aims to solve the classic N-Queens problem, which seeks to place N chess queens on an NxN chessboard so that no two queens threaten each other. 
The result, res, will contain the number of distinct solutions to the problem.
이 C++ 코드는 클래식한 N-Queens 문제를 해결하기 위한 것입니다. 
N-Queens 문제는 NxN 체스판에 N개의 체스 퀸을 서로 위협하지 않게 배치하는 문제입니다. 
결과값인 res는 이 문제의 서로 다른 해결 방법의 수를 담고 있습니다.
*/

#include <iostream>

using namespace std;

static int board[15][15]; // 체스판을 나타내는 2차원 배열. 1은 퀸이 위치한 셀을 나타내고 0은 빈 셀을 나타냅니다.
static int N; // 체스판의 크기를 나타내는 변수입니다.
static int res = 0; // 서로 다른 해결 방법의 수를 저장하는 변수입니다.

// Backtracking 함수. 현재 idx 행에서 퀸을 배치해야 합니다.
static void bt(int idx) {
	bool pass = false; // 현재 셀에 퀸을 배치할 수 있는지를 판단하는 변수입니다.

	// 모든 행에 퀸이 배치되면 결과 값을 1 증가시킵니다.
	if (idx == N) {
		res++;
		return;
	}

	for (int j = 0; j < N; j++) {
		pass = false;

		// 현재 행에서 좌측에 다른 퀸이 있는지 확인합니다.
		for (int k = j - 1; k >= 0; k--) {
			if (board[idx][k] == 1) {
				pass = true;
				break;
			}
		}

		if (pass)
			continue;

		// 상단에 다른 퀸이 있는지 확인합니다.
		for (int k = idx - 1; k >= 0; k--) {
			if (board[k][j] == 1) {
				pass = true;
				break;
			}
		}

		if (pass)
			continue;

		// 좌측 대각선에 다른 퀸이 있는지 확인합니다.
		int yt = idx - 1;
		int xt = j - 1;

		while (yt >= 0 && xt >= 0) {
			if (board[yt][xt] == 1) {
				pass = true;
				break;
			}
			yt--;
			xt--;
		}

		if (pass)
			continue;

		// 우측 대각선에 다른 퀸이 있는지 확인합니다.
		yt = idx - 1;
		xt = j + 1;

		while (yt >= 0 && xt < N) {
			if (board[yt][xt] == 1) {
				pass = true;
				break;
			}
			yt--;
			xt++;
		}

		if (pass)
			continue;

		// 현재 셀에 퀸을 배치하고 다음 행으로 진행합니다.
		board[idx][j] = 1;
		bt(idx + 1);
		board[idx][j] = 0;  // Backtrack: 퀸 배치를 취소합니다.

	}
}

int main()
{
	cin >> N; // 체스판의 크기를 입력 받습니다.

	bt(0);     // 첫 번째 행부터 퀸 배치를 시작합니다.

	cout << res;  // 결과 값을 출력합니다.
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

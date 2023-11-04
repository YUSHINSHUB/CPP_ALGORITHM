/*
commented by ChatGPT
This C++ code implements a backtracking algorithm to solve a Sudoku puzzle. 
The goal is to fill a 9x9 grid so that each column, each row, and each of the nine 3x3 sub-grids contain all of the digits from 1 to 9.
이 C++ 코드는 스도쿠 퍼즐을 해결하기 위한 백트래킹 알고리즘을 구현합니다. 
목표는 각 열, 각 행, 그리고 3x3 부분 그리드 각각이 1부터 9까지의 모든 숫자를 포함하도록 9x9 그리드를 채우는 것입니다.
*/

#include <iostream>
using namespace std;

int board[9][9]; // 스도쿠 보드
int cnt = 0; // 채워야 할 셀의 수
int y[9][10]; // 행에 숫자를 놓을 수 있는지 여부를 확인하는 배열
int x[9][10]; // 열에 숫자를 놓을 수 있는지 여부를 확인하는 배열
int area[3][3][10]; // 3x3 서브그리드에 숫자를 놓을 수 있는지 여부를 확인하는 배열
bool fin = false; // 솔루션이 완성되었는지 여부를 나타내는 플래그

// 스도쿠를 해결하는 백트래킹 함수
static void bt(int yidx, int idx) {

	if (idx == cnt) { // 모든 셀이 채워지면 보드를 출력하고 종료
		fin = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		return;
	}

	// 주어진 행 인덱스부터 각 셀을 채우기 시작
	for (int i = yidx; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) { // 셀이 비어있으면
				// 1부터 9까지의 각 숫자를 시도
				for (int k = 1; k <= 9; k++) {
					// 숫자를 놓을 수 있는지 확인
					if (y[i][k] == 0 && x[j][k] == 0 && area[i / 3][j / 3][k] == 0) {
						// 숫자를 놓고, 행, 열, 서브그리드를 체크
						board[i][j] = k;
						y[i][k] = 1;
						x[j][k] = 1;
						area[i / 3][j / 3][k] = 1;
						// 다음 셀로 계속
						bt(i, idx + 1);
						if (fin) return; // 솔루션이 완성되면 더 이상의 재귀를 중단
						// 백트래킹: 체크 해제 및 셀을 비움
						y[i][k] = 0;
						x[j][k] = 0;
						area[i / 3][j / 3][k] = 0;
						board[i][j] = 0;
					}
				}
				return; // 다음 숫자를 시도하거나 더 백트래킹
			}
		}
	}

}

int main()
{
	// 체크 배열을 0으로 초기화
	for (int i = 0; i < 9; i++) {
		fill(y[i], y[i] + 10, 0);
		fill(x[i], x[i] + 10, 0);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			fill(area[i][j], area[i][j] + 10, 0);
	}

	// 입력으로부터 초기 보드 상태를 읽어들이고, 숫자들이 있는 셀을 체크 배열에 표시
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) cnt++; // 채워야 할 셀의 수를 카운트
			y[i][board[i][j]] = 1;
			x[j][board[i][j]] = 1;
			area[i / 3][j / 3][board[i][j]] = 1;
		}
	}

	bt(0, 0); // 백트래킹 시작
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

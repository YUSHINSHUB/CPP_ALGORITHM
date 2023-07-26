// Q2615_OMOK_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;


int main() {

	int board[19][19];
	string res = "";

	for (int i = 0; i < 19; i++) {
		for (int z = 0; z < 19; z++) {
			cin >> board[i][z];
		}
	}

	int cnt = 0;

	for (int i = 0; i < 19; i++) {
		for (int z = 0; z < 19; z++) {
			if (board[z][i] != 0) {
				int t = board[z][i];
				//가로검사
				if (i == 14 && board[z][13] != t) {
					cnt = 1;
					for (int x = 1; x <= 4; x++) {
						if (board[z][i + x] == t) {
							cnt++;
						}
						else break;
					}
				}
				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}
				//세로검사
				if (z == 14 && board[13][i] != t) {
					cnt = 1;
					for (int x = 1; x <= 4; x++) {
						if (board[z + x][i] == t) {
							cnt++;
						}
						else break;
					}
				}
				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}
				//대각검사
				if ((z <= 14 && i == 14) || (z == 14 && i <= 14)) {
					if (i == 0 || z == 0) {
						cnt = 1;
						for (int x = 1; x <= 4; x++) {
							if (board[z + x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
					else if (board[z - 1][i - 1] != t) {
						cnt = 1;
						for (int x = 1; x <= 4; x++) {
							if (board[z + x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
				}


				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}
				//가로검사
				if (i < 14) {
					if (i == 0) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
					else if (board[z][i - 1] != t) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}

				}
				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}

				//세로검사
				if (z < 14) {
					if (z == 0) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z + x][i] == t) {
								cnt++;
							}
							else break;
						}
					}
					else if (board[z - 1][i] != t) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z + x][i] == t) {
								cnt++;
							}
							else break;
						}
					}
				}
				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}
				//대각검사
				if (z < 14 && i < 14) {
					if (z == 0 || i == 0) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z + x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
					else if (board[z - 1][i - 1] != t) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z + x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
				}

				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}
				//대각검사
				if ((z == 4 && i <= 14) || (z >= 4 && i == 14)) {
					if (i == 0 || z == 18) {
						cnt = 1;
						for (int x = 1; x <= 4; x++) {
							if (board[z - x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
					else if (board[z + 1][i - 1] != t) {
						cnt = 1;
						for (int x = 1; x <= 4; x++) {
							if (board[z - x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
				}

				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}
				//대각검사 (윗방향 오른쪽)
				if (z > 4 && i < 14) {
					if (i == 0 || z == 18) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z - x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
					else if (board[z + 1][i - 1] != t) {
						cnt = 1;
						for (int x = 1; x <= 5; x++) {
							if (board[z - x][i + x] == t) {
								cnt++;
							}
							else break;
						}
					}
				}

				if (cnt == 5) {
					res = to_string(t) + "\n" + to_string(z + 1) + " " + to_string(i + 1);
					break;
				}
			}
		}
		if (cnt == 5) {
			break;
		}
	}

	if (cnt == 5) {
		cout << res;
	}
	else {
		cout << "0";
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

// Q14890_Ramp_G3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{


	int N, L;
	int res = 0;
	int grid[100][100];
	bool chk[100][2];

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		fill(chk[i], chk[i] + 2, false);
		int cur = grid[i][0];
		int cnt = 0;
		bool pass = true;
		bool prev = true;
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == cur)
				cnt++;
			else {
				if (grid[i][j] == cur - 1) {
					if (!prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur--;
					prev = false;
				}
				else if (grid[i][j] == cur + 1) {
					if (!prev && cnt < L * 2) {
						pass = false;
						break;
					}
					if (prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur++;
					prev = true;
				}
				else {
					pass = false;
					break;
				}
			}
		}
		if ((prev == false && cnt >= L && pass) || (prev && pass)) {
			chk[i][0] = true;
			res++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (chk[i][0])
			continue;
		int cur = grid[i][N - 1];
		int cnt = 0;
		bool pass = true;
		bool prev = true;
		for (int j = N - 1; j >= 0; j--) {
			if (grid[i][j] == cur)
				cnt++;
			else {
				if (grid[i][j] == cur - 1) {
					if (!prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur--;
					prev = false;
				}
				else if (grid[i][j] == cur + 1) {
					if (!prev && cnt < L * 2) {
						pass = false;
						break;
					}
					if (prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur++;
					prev = true;
				}
				else {
					pass = false;
					break;
				}
			}
		}

		if ((prev == false && cnt >= L && pass) || (prev && pass)) {
			chk[i][0] = true;
			res++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (chk[i][1])
			continue;
		int cur = grid[0][i];
		int cnt = 0;
		bool pass = true;
		bool prev = true;
		for (int j = 0; j < N; j++) {
			if (grid[j][i] == cur)
				cnt++;
			else {
				if (grid[j][i] == cur - 1) {
					if (!prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur--;
					prev = false;
				}
				else if (grid[j][i] == cur + 1) {
					if (!prev && cnt < L * 2) {
						pass = false;
						break;
					}
					if (prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur++;
					prev = true;
				}
				else {
					pass = false;
					break;
				}
			}
		}

		if ((prev == false && cnt >= L && pass) || (prev && pass)) {
			chk[i][1] = true;
			res++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (chk[i][1])
			continue;
		int cur = grid[0][i];
		int cnt = 0;
		bool pass = true;
		bool prev = true;
		for (int j = N - 1; j >= 0; j--) {
			if (grid[j][i] == cur)
				cnt++;
			else {
				if (grid[j][i] == cur - 1) {
					if (!prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur--;
					prev = false;
				}
				else if (grid[j][i] == cur + 1) {
					if (!prev && cnt < L * 2) {
						pass = false;
						break;
					}
					if (prev && cnt < L) {
						pass = false;
						break;
					}
					cnt = 1;
					cur++;
					prev = true;
				}
				else {
					pass = false;
					break;
				}
			}
		}

		if ((prev == false && cnt >= L && pass) || (prev && pass)) {
			chk[i][1] = true;
			res++;
		}
	}

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

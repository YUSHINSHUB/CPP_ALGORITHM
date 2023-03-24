// 10830_Square_of_Matrix.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int tr10830[6][6];
vector<vector<int>> res10830(6, std::vector<int>(6));

static void calc10830(vector<vector<int>> mat, vector<vector<int>> t, int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp = 0;
			for (int k = 0; k < n; k++) {
				temp += (t[i][k] * mat[k][j]) % 1000;
			}
			tr10830[i][j] = temp;
		}
	}
}

int main() {

	int n;
	long long b;

	cin >> n >> b;

	vector<vector<int>> mat(n, vector<int>(n));
	vector<vector<int>> t(n, vector<int>(n));
	vector<vector<int>> tt(n, vector<int>(n));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			res10830[i][j] = mat[i][j];
			t[i][j] = mat[i][j];
			tt[i][j] = mat[i][j];
		}
	}

	if (b == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << mat[i][j] % 1000 << " ";
			cout << "\n";
		}
	}
	else {

		int cnt = 0;

		cnt = (int)(log(b) / log(2));
		b -= pow(2, cnt);

		for (int i = 0; i < cnt; i++) {
			calc10830(t, tt, n);
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					t[j][k] = tr10830[j][k];
					tt[j][k] = tr10830[j][k];
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res10830[j][k] = tr10830[j][k];
			}
		}

		while (b > 1) {
			cnt = (int)(log(b) / log(2));
			b -= pow(2, cnt);

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					t[j][k] = mat[j][k];
					tt[j][k] = mat[j][k];
				}
			}

			for (int i = 0; i < cnt; i++) {
				calc10830(t, tt, n);
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						t[j][k] = tr10830[j][k];
						tt[j][k] = tr10830[j][k];
					}
				}
			}

			calc10830(t, res10830, n);

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res10830[j][k] = tr10830[j][k];
				}
			}
		}

		if (b == 1) {
			calc10830(mat, res10830, n);
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res10830[j][k] = tr10830[j][k];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << res10830[i][j] % 1000 << " ";
			cout << "\n";
		}

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

// Q12100_2048_Easy_G2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> pick;
static int grid[20][20];
static int temp[20][20];
static int N;
static int res = 0;

static void bt() {

	if (pick.size() == 5) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				temp[i][j] = grid[i][j];
		}

		for (int tc = 0; tc < 5; tc++) {

			int pos = pick[tc];

			switch (pos) {
			case 1:

				for (int i = 0; i < N; i++) {
					for (int j = 1; j < N; j++) {
						if (temp[j][i] > 0) {
							int t = temp[j][i];
							temp[j][i] = 0;
							while (temp[j][i] == 0) {
								j--;
								if (j < 0) {
									j++;
									break;
								}
							}
							if (temp[j][i] > 0)
								j++;
							temp[j][i] = t;
						}
					}
				}

				for (int i = 0; i < N; i++) {
					for (int j = 1; j < N; j++) {
						if (temp[j][i] == 0)
							break;
						if (temp[j][i] == temp[j - 1][i]) {
							temp[j - 1][i] *= 2;
							temp[j][i] = 0;
							for (int k = j + 1; k < N; k++) {
								if (temp[k][i] == 0)
									break;
								temp[k - 1][i] = temp[k][i];
								temp[k][i] = 0;
							}
						}
					}
				}

				break;
			case 2:

				for (int i = 0; i < N; i++) {
					for (int j = 1; j < N; j++) {
						if (temp[i][j] > 0) {
							int t = temp[i][j];
							temp[i][j] = 0;
							while (temp[i][j] == 0) {
								j--;
								if (j < 0) {
									j++;
									break;
								}
							}
							if (temp[i][j] > 0)
								j++;
							temp[i][j] = t;
						}
					}
				}

				for (int i = 0; i < N; i++) {
					for (int j = 1; j < N; j++) {
						if (temp[i][j] == 0)
							break;
						if (temp[i][j] == temp[i][j - 1]) {
							temp[i][j - 1] *= 2;
							temp[i][j] = 0;
							for (int k = j + 1; k < N; k++) {
								if (temp[i][k] == 0)
									break;
								temp[i][k - 1] = temp[i][k];
								temp[i][k] = 0;
							}
						}
					}
				}

				break;
			case 3:

				for (int i = 0; i < N; i++) {
					for (int j = N - 2; j >= 0; j--) {
						if (temp[i][j] > 0) {
							int t = temp[i][j];
							temp[i][j] = 0;
							while (temp[i][j] == 0) {
								j++;
								if (j >= N) {
									j--;
									break;
								}
							}
							if (temp[i][j] > 0)
								j--;
							temp[i][j] = t;
						}
					}
				}

				for (int i = 0; i < N; i++) {
					for (int j = N - 2; j >= 0; j--) {
						if (temp[i][j] == 0)
							break;
						if (temp[i][j] == temp[i][j + 1]) {
							temp[i][j + 1] *= 2;
							temp[i][j] = 0;
							for (int k = j - 1; k >= 0; k--) {
								if (temp[i][k] == 0)
									break;
								temp[i][k + 1] = temp[i][k];
								temp[i][k] = 0;
							}
						}
					}
				}

				break;
			case 4:

				for (int i = 0; i < N; i++) {
					for (int j = N - 2; j >= 0; j--) {
						if (temp[j][i] > 0) {
							int t = temp[j][i];
							temp[j][i] = 0;
							while (temp[j][i] == 0) {
								j++;
								if (j >= N) {
									j--;
									break;
								}
							}
							if (temp[j][i] > 0)
								j--;
							temp[j][i] = t;
						}
					}
				}

				for (int i = 0; i < N; i++) {
					for (int j = N - 2; j >= 0; j--) {
						if (temp[j][i] == 0)
							break;
						if (temp[j][i] == temp[j + 1][i]) {
							temp[j + 1][i] *= 2;
							temp[j][i] = 0;
							for (int k = j - 1; k >= 0; k--) {
								if (temp[k][i] == 0)
									break;
								temp[k + 1][i] = temp[k][i];
								temp[k][i] = 0;
							}
						}
					}
				}

				break;
			}

		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				res = max(res, temp[i][j]);
		}

	}
	else {
		for (int i = 1; i <= 4; i++) {
			pick.push_back(i);
			bt();
			pick.pop_back();
		}
	}

}


int main()
{

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	bt();
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

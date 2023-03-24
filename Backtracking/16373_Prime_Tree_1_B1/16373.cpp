// 16373.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	for (int c = 0; c < t; c++) {

		int n;
		cin >> n;
		vector<vector<int>> tree(n - 1, vector<int>(2));
		vector<int>res(n);
		int bs = 0;
		int as = 0;

		for (int i = 0; i < n; i++) {
			res[i] = i + 1;
		}

		for (int i = 0; i < n - 1; i++) {
			cin >> tree[i][0] >> tree[i][1];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int z = 2; z <= min(tree[i][0], tree[i][1]); z++) {
				if (tree[i][0] % z == 0 && tree[i][1] % z == 0) {
					bs++;
					break;
				}
			}
		}

		while (true) {
			vector<int> scr(n + 1);
			for (int i = 1; i <= n; i++) {
				scr[i] = 0;
			}
			int max = 0;
			int num = 0;
			for (int i = 0; i < n - 1; i++) {
				for (int z = 2; z <= min(tree[i][0], tree[i][1]); z++) {
					if (tree[i][0] % z == 0 && tree[i][1] % z == 0) {
						scr[tree[i][0]]++;
						scr[tree[i][1]]++;
						break;
					}
				}
			}

			for (int i = 1; i <= n; i++) {
				if (scr[i] > max) {
					max = scr[i];
					num = i;
				}
				else if (scr[i] == max) {
					int acnt = 0;
					int bcnt = 0;
					for (int x = 0; x < n - 1; x++) {
						if (tree[x][0] == num) {
							acnt++;
						}
						else if (tree[x][0] == i) {
							bcnt++;
						}
						if (tree[x][1] == num) {
							acnt++;
						}
						else if (tree[x][1] == i) {
							bcnt++;
						}
					}
					if (bcnt > acnt) {
						max = scr[i];
						num = i;
					}
				}
			}

			vector<int> acc(n);
			int accnt = 0;
			vector<bool>chk(n + 1);
			chk[num] = true;

			for (int i = 0; i < n - 1; i++) {
				if (tree[i][0] == num) {
					chk[tree[i][1]] = true;
				}
				else if (tree[i][1] == num) {
					chk[tree[i][0]] = true;
				}
			}

			for (int i = 1; i <= n; i++) {
				if (chk[i] == false) {
					acc[accnt] = i;
					accnt++;
				}
			}

			int mtemp = 0;
			int mini = max;
			int mnum = 0;

			for (int i = 0; i < accnt; i++) {
				mtemp = 0;
				for (int z = 1; z <= n; z++) {
					if (chk[z] == true) {
						for (int x = 2; x <= min(acc[i], z); x++) {
							if (acc[i] % x == 0 && z % x == 0) {
								mtemp++;
								continue;
							}
						}
					}
				}
				if (mini > mtemp) {
					mini = mtemp;
					mnum = acc[i];
				}
			}

			if (mini >= max) {
				break;
			}
			else {
				for (int i = 0; i < n; i++) {
					if (res[i] == num) {
						res[i] = mnum;
					}
					else if (res[i] == mnum) {
						res[i] = num;
					}
				}
			}

			for (int i = 0; i < n - 1; i++) {
				if (tree[i][0] == num) {
					tree[i][0] = mnum;
				}
				else if (tree[i][0] == mnum) {
					tree[i][0] = num;
				}
				if (tree[i][1] == mnum) {
					tree[i][1] = num;
				}
				else if (tree[i][1] == num) {
					tree[i][1] = mnum;
				}

			}
			for (int i = 0; i < n - 1; i++) {
				for (int z = 2; z <= min(tree[i][0], tree[i][1]); z++) {
					if (tree[i][0] % z == 0 && tree[i][1] % z == 0) {
						as++;
						break;
					}
				}
			}

			if (as == bs) {
				break;
			}
			else {
				bs = as;
				as = 0;
			}

		}

		for (int i = 0; i < n; i++) {
			cout << res[i] << " ";
		}

		cout << "\n";

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

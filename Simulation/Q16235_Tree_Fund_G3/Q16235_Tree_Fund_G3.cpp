/*
commented by ChatGPT
This C++ code simulates a forest management scenario over a specified number of years, K.
It uses a grid to represent the forest, where each cell contains a deque of trees of different ages.
The simulation includes yearly phases of growth, reproduction, and nutrient addition.
Trees grow and reproduce based on their age and the nutrients in their cell.
The program calculates the total number of trees after K years.
이 C++ 코드는 지정된 연수 K 동안의 숲 관리 시나리오를 시뮬레이션합니다.
숲은 그리드로 표현되며, 각 셀에는 다양한 나이의 나무들이 deque에 저장됩니다.
시뮬레이션은 성장, 번식, 영양분 추가의 연간 단계를 포함합니다.
나무들은 각 셀의 영양분과 나무의 나이에 따라 성장하고 번식합니다.
프로그램은 K년 후의 총 나무 수를 계산합니다.
*/

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	int ny[] = { -1, 0, 0, 1, 0, 1, 0, 0 }; // y축 이동 벡터 (상, 하, 좌, 우, 대각선)
	int nx[] = { -1, 1, 1, -2, 2, -2, 1, 1 }; // x축 이동 벡터 (상, 하, 좌, 우, 대각선)
	int res = 0; // 최종 결과(나무의 총 수)
	int N, M, K;
	cin >> N >> M >> K;

	int land[11][11]; // 각 셀의 영양분
	int A[11][11]; // 매년 추가되는 영양분
	deque<int> list[11][11]; // 각 셀에 있는 나무의 나이를 저장하는 덱
	queue<int> temp; // 임시 저장을 위한 큐

	// 초기화 과정
	for (int i = 1; i <= N; i++) {
		fill(land[i], land[i] + N + 1, 5); // 모든 셀의 영양분을 5로 초기화
	}

	// 매년 추가되는 영양분 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	// 초기 나무 정보 입력
	for (int i = 0; i < M; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		list[x][y].push_back(k);
	}

	// K년 동안 시뮬레이션 수행
	for (int i = 0; i < K; i++) {

		// 봄: 나무가 자라고, 영양분이 부족하면 죽음
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (!list[j][k].empty()) {
					int add = 0; // 추가될 영양분
					while (!list[j][k].empty()) {
						int t = list[j][k].front();
						list[j][k].pop_front();
						if (t <= land[j][k]) {
							land[j][k] -= t;
							temp.push(t + 1);
						}
						else {
							add += t / 2; // 죽은 나무가 영양분으로 변환
						}
					}
					while (!temp.empty()) {
						list[j][k].push_back(temp.front());
						temp.pop();
					}
					land[j][k] += add;
				}
			}
		}

		// 가을: 나무 번식
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (!list[j][k].empty()) {
					while (!list[j][k].empty()) {
						int t = list[j][k].front();
						list[j][k].pop_front();
						temp.push(t);
						if (t % 5 == 0) { // 5의 배수 나이인 나무가 번식
							int ypos = j;
							int xpos = k;
							for (int m = 0; m < 8; m++) {
								ypos += ny[m];
								xpos += nx[m];
								if (ypos < 1 || ypos > N || xpos < 1 || xpos > N)
									continue;

								list[ypos][xpos].push_front(1); // 새로운 나무 추가
							}
						}
					}
					while (!temp.empty()) {
						list[j][k].push_back(temp.front());
						temp.pop();
					}
				}
			}
		}

		// 겨울: 영양분 추가
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				land[j][k] += A[j][k];
			}
		}

	}

	// 나무의 총 수 계산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res += list[i][j].size();
		}
	}

	cout << res; // 결과 출력
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

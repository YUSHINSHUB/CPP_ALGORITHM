
/*
commented by ChatGPT
This C++ code simulates a puzzle game involving mechanical gears. Each gear has a series of teeth represented as integers in a vector.
The game involves rotating these gears either clockwise or counterclockwise based on input commands.
The final score is determined based on the state of a specific tooth in each gear after all rotations are performed.
This code utilizes vectors to represent the gears and processes a series of rotation instructions to achieve the final state of the gears.
이 C++ 코드는 기계적인 톱니바퀴를 포함하는 퍼즐 게임을 시뮬레이션합니다.
각 톱니바퀴는 벡터로 표현된 일련의 톱니로 구성되어 있습니다.
이 게임은 입력된 명령에 따라 이 톱니바퀴들을 시계 방향 또는 반시계 방향으로 회전시킵니다.
최종 점수는 모든 회전이 수행된 후 각 톱니바퀴의 특정 톱니의 상태에 따라 결정됩니다.
이 코드는 톱니바퀴를 표현하기 위해 벡터를 사용하며 일련의 회전 지시사항을 처리하여 톱니바퀴의 최종 상태를 달성합니다.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> d[4]; // 각 톱니바퀴의 상태를 나타내는 벡터 배열
vector<int> v; // 회전을 처리하기 위한 임시 벡터

// 기어를 시계 방향으로 회전시키는 함수
static void clo(int gear) {
	v.push_back(d[gear][7]); // 기어의 마지막 요소를 임시 벡터에 추가
	for (int i = 0; i < 7; i++) {
		v.push_back(d[gear][i]); // 나머지 요소들을 임시 벡터에 추가
	}
	d[gear].clear(); // 기어 벡터 초기화
	for (int i = 0; i < 8; i++) {
		d[gear].push_back(v[i]); // 임시 벡터의 요소들을 기어 벡터에 복사
	}
	v.clear(); // 임시 벡터 초기화
}

// 기어를 반시계 방향으로 회전시키는 함수
static void rev(int gear) {
	for (int i = 1; i < 8; i++) {
		v.push_back(d[gear][i]); // 첫 번째 요소를 제외한 나머지 요소들을 임시 벡터에 추가
	}
	v.push_back(d[gear][0]); // 첫 번째 요소를 임시 벡터의 마지막에 추가
	d[gear].clear(); // 기어 벡터 초기화
	for (int i = 0; i < 8; i++) {
		d[gear].push_back(v[i]); // 임시 벡터의 요소들을 기어 벡터에 복사
	}
	v.clear(); // 임시 벡터 초기화
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int res = 0; // 최종 점수를 저장하는 변수
	int t1, t2, t3, t4, t5, t6, K; // 인접한 기어들의 치아 상태와 회전 횟수 저장 변수
	string in; // 입력 문자열

	// 기어 상태 입력
	for (int i = 0; i < 4; i++) {
		cin >> in;
		for (int j = 0; j < 8; j++)
			d[i].push_back(in[j] - '0');
	}

	cin >> K; // 회전 횟수 입력

	// 회전 명령 처리
	for (int cs = 0; cs < K; cs++) {
		int a, b; // 회전할 기어 번호와 방향
		cin >> a >> b;
		t1 = d[0][2]; t2 = d[1][6]; t3 = d[1][2];
		t4 = d[2][6]; t5 = d[2][2]; t6 = d[3][6];
		switch (a) {
		case 1:
			// 첫 번째 기어에 대한 로직
			if (b == 1) {
				clo(0);
				if (t1 != t2) {
					rev(1);
					if (t3 != t4) {
						clo(2);
						if (t5 != t6) rev(3);
					}
				}
			}
			else {
				rev(0);
				if (t1 != t2) {
					clo(1);
					if (t3 != t4) {
						rev(2);
						if (t5 != t6) clo(3);
					}
				}
			}
			break;
		case 2:
			// 두 번째 기어에 대한 로직
			if (b == 1) {
				clo(1);
				if (t2 != t1) {
					rev(0);
				}
				if (t3 != t4) {
					rev(2);
					if (t5 != t6) clo(3);
				}
			}
			else {
				rev(1);
				if (t2 != t1) {
					clo(0);
				}
				if (t3 != t4) {
					clo(2);
					if (t5 != t6) rev(3);
				}
			}
			break;
		case 3:
			// 세 번째 기어에 대한 로직
			if (b == 1) {
				clo(2);
				if (t4 != t3) {
					rev(1);
					if (t2 != t1) clo(0);
				}
				if (t5 != t6) rev(3);
			}
			else {
				rev(2);
				if (t4 != t3) {
					clo(1);
					if (t2 != t1) rev(0);
				}
				if (t5 != t6) clo(3);
			}
			break;
		case 4:
			// 네 번째 기어에 대한 로직
			if (b == 1) {
				clo(3);
				if (t6 != t5) {
					rev(2);
					if (t4 != t3) {
						clo(1);
						if (t2 != t1) rev(0);
					}
				}
			}
			else {
				rev(3);
				if (t6 != t5) {
					clo(2);
					if (t4 != t3) {
						rev(1);
						if (t2 != t1) clo(0);
					}
				}
			}
			break;
		}
	}

	// 최종 점수 계산
	if (d[0][0] == 1) res++;
	if (d[1][0] == 1) res += 2;
	if (d[2][0] == 1) res += 4;
	if (d[3][0] == 1) res += 8;

	cout << res; // 점수 출력
}

/*
commented by ChatGPT
This C++ code simulates a dice rolling on a 2D grid.
The dice is represented by an array with each index corresponding to a face.
The code handles the dice's orientation change as it rolls in different directions (north, south, east, west).
The grid, its size, and the dice's initial position are inputted by the user.
If the dice lands on a cell with a non-zero value, that value is moved to the bottom face of the dice, and the cell is set to zero.
Otherwise, the bottom face value of the dice is copied to the cell.
After each roll, the top face value of the dice is outputted.
이 C++ 코드는 2D 그리드 위에서 주사위가 굴러가는 것을 시뮬레이션합니다.
주사위는 각 면이 인덱스에 해당하는 배열로 표현됩니다.
코드는 북쪽, 남쪽, 동쪽, 서쪽으로 굴러갈 때 주사위의 방향 변화를 처리합니다.
그리드의 크기와 주사위의 초기 위치는 사용자에 의해 입력됩니다.
주사위가 0이 아닌 값을 가진 셀에 도착하면, 그 값은 주사위의 바닥 면으로 이동하고 셀은 0으로 설정됩니다.
그렇지 않으면 주사위의 바닥 면 값이 셀로 복사됩니다.
각 굴림 후 주사위의 윗면 값이 출력됩니다.
*/

#include <iostream>
using namespace std;

int dice[7]; // 주사위의 각 면을 나타내는 배열

// 주사위를 북쪽으로 굴릴 때 주사위 면의 변화를 처리하는 함수
void mn() {
	int d1 = dice[1];
	int d3 = dice[3];
	int d5 = dice[5];
	int d6 = dice[6];

	dice[1] = d6; // 바닥면이 상단면이 됨
	dice[3] = d1; // 상단면이 앞면이 됨
	dice[5] = d3; // 앞면이 바닥면이 됨
	dice[6] = d5; // 뒷면이 상단면이 됨
}

// 주사위를 남쪽으로 굴릴 때 주사위 면의 변화를 처리하는 함수
void ms() {
	int d1 = dice[1];
	int d3 = dice[3];
	int d5 = dice[5];
	int d6 = dice[6];

	dice[1] = d3; // 앞면이 상단면이 됨
	dice[3] = d5; // 뒷면이 앞면이 됨
	dice[5] = d6; // 바닥면이 뒷면이 됨
	dice[6] = d1; // 상단면이 바닥면이 됨
}

// 주사위를 동쪽으로 굴릴 때 주사위 면의 변화를 처리하는 함수
void me() {
	int d2 = dice[2];
	int d3 = dice[3];
	int d4 = dice[4];
	int d6 = dice[6];

	dice[2] = d3; // 앞면이 오른쪽 면이 됨
	dice[3] = d4; // 오른쪽 면이 바닥면이 됨
	dice[4] = d6; // 바닥면이 왼쪽 면이 됨
	dice[6] = d2; // 왼쪽 면이 상단면이 됨
}

// 주사위를 서쪽으로 굴릴 때 주사위 면의 변화를 처리하는 함수
void mw() {
	int d2 = dice[2];
	int d3 = dice[3];
	int d4 = dice[4];
	int d6 = dice[6];

	dice[2] = d6; // 바닥면이 오른쪽 면이 됨
	dice[3] = d2; // 왼쪽 면이 앞면이 됨
	dice[4] = d3; // 앞면이 왼쪽 면이 됨
	dice[6] = d4; // 오른쪽 면이 바닥면이 됨
}

int main()
{
	ios_base::sync_with_stdio(0); // C++ I/O 속도 향상을 위한 설정
	cin.tie(0);
	cout.tie(0);

	int N, M, y, x, K; // 그리드의 크기, 주사위의 초기 위치, 명령의 수
	fill(dice, dice + 7, 0); // 주사위 배열 초기화
	int grid[20][20]; // 그리드 배열

	// 그리드 크기와 주사위의 초기 위치, 명령의 수 입력
	cin >> N >> M >> y >> x >> K;

	// 그리드 상태 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];
	}

	// 명령 처리
	for (int cs = 0; cs < K; cs++) {
		int pos;
		cin >> pos;
		switch (pos) {
		case 1: // 동쪽으로 굴림
			if (x + 1 >= M) break; // 경계 체크
			x++;
			me();
			if (grid[y][x] == 0) {
				grid[y][x] = dice[6];
			}
			else {
				dice[6] = grid[y][x];
				grid[y][x] = 0;
			}
			cout << dice[3] << "\n";
			break;
		case 2: // 서쪽으로 굴림
			if (x - 1 < 0) break;
			x--;
			mw();
			if (grid[y][x] == 0) {
				grid[y][x] = dice[6];
			}
			else {
				dice[6] = grid[y][x];
				grid[y][x] = 0;
			}
			cout << dice[3] << "\n";
			break;
		case 3: // 북쪽으로 굴림
			if (y - 1 < 0) break;
			y--;
			mn();
			if (grid[y][x] == 0) {
				grid[y][x] = dice[6];
			}
			else {
				dice[6] = grid[y][x];
				grid[y][x] = 0;
			}
			cout << dice[3] << "\n";
			break;
		case 4: // 남쪽으로 굴림
			if (y + 1 >= N) break;
			y++;
			ms();
			if (grid[y][x] == 0) {
				grid[y][x] = dice[6];
			}
			else {
				dice[6] = grid[y][x];
				grid[y][x] = 0;
			}
			cout << dice[3] << "\n";
			break;
		}
	}
}
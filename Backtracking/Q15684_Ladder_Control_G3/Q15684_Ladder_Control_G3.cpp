/*
commented by ChatGPT
This C++ code aims to find the minimum number of additional moves needed to ensure that after traversing a series of ladders, each player ends up in their designated finishing position. 
It uses a backtracking algorithm to simulate ladder placements and checks if the goal state is achieved. 
The search for the solution is capped at adding a maximum of three ladders to maintain computational feasibility.
이 C++ 코드는 일련의 사다리를 지나갈 때 각 플레이어가 지정된 종료 위치에 도달하도록 보장하기 위해 필요한 최소한의 추가 이동 수를 찾는 것을 목표로 합니다. 
사다리 배치를 시뮬레이션하고 목표 상태가 달성되는지 확인하기 위해 백트래킹 알고리즘을 사용합니다. 
솔루션을 찾기 위한 탐색은 계산 가능성을 유지하기 위해 최대 세 개의 사다리를 추가하는 것으로 제한됩니다.
*/

#include <iostream>
using namespace std;

int ladd[31][11]; // Array to represent the ladders (사다리를 나타내는 배열)
int res = 0; // Result to store the minimum number of moves needed (필요한 최소 이동 수를 저장할 결과)
int N, M, H; // N: number of columns, M: number of existing ladders, H: number of rows (N: 열의 수, M: 기존 사다리의 수, H: 행의 수)
bool out = false; // Flag to indicate the solution was found (해결책을 찾았다는 것을 나타내는 플래그)
int cnt = 0; // Counter for number of possible places to put ladders (사다리를 놓을 수 있는 장소의 수를 세는 카운터)

// Function to recursively place ladders and check for solution (재귀적으로 사다리를 배치하고 솔루션을 확인하는 함수)
bool bt15684(int ypos, int xpos, int idx) {
	if (idx == res) { // Base case: if the number of moves equals the result (기본 사례: 이동 수가 결과와 같을 경우)
		out = true; // Assume solution is found (해결책을 찾았다고 가정)
		// Check if all columns lead to their respective row (모든 열이 각각의 행으로 이어지는지 확인)
		for (int i = 0; i < N; i++) {
			int x = i;
			for (int j = 0; j < H; j++) {
				x += ladd[j][x]; // Traverse the ladder (사다리를 탐색)
			}
			if (x != i) { // If a column doesn't lead to the correct row (열이 올바른 행으로 이어지지 않으면)
				out = false;
				break;
			}
		}
		return out; // Return whether the solution was found (해결책이 찾아졌는지 반환)
	}

	// Attempt to place a ladder at each possible position (가능한 모든 위치에 사다리를 놓으려고 시도)
	for (int i = ypos; i < H; i++) {
		if (xpos == N && i == ypos) {
			i++;
			if (i == H) break;
		}
		for (int j = 1; j < N; j++) {
			if (j == 1 && i == ypos) j = xpos;
			// Ensure it's a valid position to place a ladder (사다리를 놓을 유효한 위치인지 확인)
			if (ladd[i][j] == 0 && ladd[i][j - 1] == 0) {
				ladd[i][j] = -1; // Place ladder going left (왼쪽으로 가는 사다리 배치)
				ladd[i][j - 1] = 1; // Place ladder going right (오른쪽으로 가는 사다리 배치)
				if (bt15684(i, j + 1, idx + 1)) return true; // Recurse and check if solution is found (재귀 호출하고 솔루션을 찾았는지 확인)
				ladd[i][j] = 0; // Remove ladder (사다리 제거)
				ladd[i][j - 1] = 0; // Remove ladder (사다리 제거)
			}
		}
	}
	return false; // Return false if no solution found at this recursion level (이 재귀 레벨에서 솔루션이 없으면 false 반환)
}

// Search function to find the minimum number of moves needed (필요한 최소 이동 수를 찾기 위한 검색 함수)
static void search() {
	while (true) {
		if (bt15684(0, 1, 0)) break; // If a solution is found, exit loop (솔루션이 찾아지면 루프 탈출)
		else res++; // Increment number of moves (이동 횟수 증가)

		if (res > 3) { // If more than 3 moves needed, set result to -1 (3회 이상 이동이 필요한 경우 결과를 -1로 설정)
			res = -1;
			break;
		}
	}
}

int main() {
	cin >> N >> M >> H; // Read inputs (입력을 읽음)

	for (int i = 0; i < H; i++) {
		fill(ladd[i], ladd[i] + N, 0); // Initialize ladder array (사다리 배열 초기화)
	}

	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x; // Read existing ladders (기존 사다리 읽기)

		ladd[y - 1][x - 1] = 1; // Place existing ladder (기존 사다리 배치)
		ladd[y - 1][x] = -1; // Place existing ladder (기존 사다리 배치)
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			if (ladd[i][j] == 0) cnt++; // Count potential places for ladders (사다리를 놓을 수 있는 잠재적 장소 계산)
		}
	}
	cnt /= 2; // Adjust for double counting (이중 계산을 조정)

	search(); // Start the search for the solution (솔루션 검색 시작)

	cout << res; // Output the result (결과 출력)
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

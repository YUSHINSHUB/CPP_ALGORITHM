/*
commented by ChatGPT
This C++ code simulates a game similar to "Snakes and Ladders".
Given a board with some ladders and snakes, the code calculates the minimum number of dice rolls required to reach the 100th cell starting from the 1st cell.
If a player lands on the start of a ladder or snake, they immediately move to its end.

이 C++ 코드는 "뱀과 사다리"와 유사한 게임을 시뮬레이션합니다.
몇몇의 사다리와 뱀이 있는 보드가 주어진 경우, 코드는 1번 칸에서 시작하여 100번 칸에 도달하기 위해 필요한 주사위 굴림의 최소 횟수를 계산합니다.
플레이어가 사다리나 뱀의 시작 부분에 도착하면 즉시 그 끝으로 이동합니다.
*/

#include <iostream>
#include <map>

using namespace std;

map<int, int> hm; // 사다리와 뱀의 시작과 끝을 저장 (Stores the start and end of ladders and snakes)
int grp[101];     // 각 칸에 도달하는 데 필요한 최소 주사위 굴림 횟수 저장 (Stores the minimum dice rolls required to reach each cell)

// 게임 보드를 탐색하는 함수 (Function to search the game board)
void search(int idx) {

	for (int i = idx; i <= 100; i++) {

		// 해당 위치에 뱀이나 사다리가 없는 경우 (If there's no snake or ladder at the current position)
		if (hm.find(i) == hm.end()) {
			for (int j = i; j <= i + 6; j++) {
				if (j > 100)
					break;
				grp[j] = min(grp[i] + 1, grp[j]);
			}
		}

		// 해당 위치에 뱀이나 사다리가 있는 경우 (If there's a snake or ladder at the current position)
		else {
			int s = hm[i];
			if (grp[s] > grp[i]) {
				grp[s] = grp[i];
				search(s); // 해당 뱀이나 사다리의 끝에서부터 탐색 계속 (Continue the search from the end of the snake or ladder)
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m; // 사다리와 뱀의 개수를 입력받기 (Input the number of ladders and snakes)

	int x, y;

	fill(grp, grp + 101, 100); // 최대 값으로 초기화 (Initialize with maximum values)
	grp[1] = 0;

	// 사다리 정보 입력 (Input ladder information)
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		hm.insert(pair<int, int>(x, y));
	}

	// 뱀 정보 입력 (Input snake information)
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		hm.insert(pair<int, int>(x, y));
	}

	// 보드를 탐색하여 100번 칸까지 필요한 최소 횟수 계산 (Search the board to calculate the minimum rolls required to reach the 100th cell)
	search(1);

	// 결과 출력 (Output the result)
	cout << grp[100];
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

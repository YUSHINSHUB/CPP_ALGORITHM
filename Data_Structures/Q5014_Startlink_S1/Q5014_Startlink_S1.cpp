
/*
commented by ChatGPT
This C++ code implements a Breadth-First Search (BFS) algorithm to solve a problem of navigating a building with an elevator.
The program reads the number of floors (F), the starting floor (S),
the goal floor (G), and the number of floors the elevator can move up (U) or down (D) in one press.
The BFS algorithm is used to find the minimum number of button presses required to reach the goal floor from the starting floor.
If it is not possible to reach the goal floor, the program outputs "use the stairs".
이 C++ 코드는 엘리베이터를 사용하여 건물을 탐색하는 문제를 해결하기 위한 너비 우선 탐색(BFS) 알고리즘을 구현합니다.
프로그램은 층수(F), 시작 층(S), 목표 층(G), 그리고 엘리베이터가 한 번에 올라갈 수 있는 층수(U) 또는 내려갈 수 있는 층수(D)를 읽습니다.
BFS 알고리즘은 시작 층에서 목표 층까지 도달하는 데 필요한 최소 버튼 누름 횟수를 찾는 데 사용됩니다.
목표 층에 도달할 수 없는 경우 프로그램은 "use the stairs"를 출력합니다.
*/

#include <iostream>
#include <queue>

using namespace std;

int f[1000001] = { 0, }; // Array to keep track of the number of button presses required to reach each floor

// BFS function to calculate the number of button presses
void bfs(int F, int S, int U, int D) {

	queue<int> q; // Queue for BFS
	q.push(S); // Start from the starting floor

	while (!q.empty()) {
		int cur = q.front(); // Current floor
		q.pop();

		// If moving up is possible
		if (cur + U <= F && cur + U > 0 && U != 0) {
			int temp = cur + U; // Floor reached after moving up
			// If this floor is not visited yet
			if (f[temp] == 0) {
				f[temp] = f[cur] + 1; // Update the number of button presses
				q.push(temp); // Add this floor to the queue
			}
		}

		// If moving down is possible
		if (cur - D <= F && cur - D > 0 && D != 0) {
			int temp = cur - D; // Floor reached after moving down
			// If this floor is not visited yet
			if (f[temp] == 0) {
				f[temp] = f[cur] + 1; // Update the number of button presses
				q.push(temp); // Add this floor to the queue
			}
		}
	}
}

int main()
{
	int F, S, G, U, D; // Variables for the number of floors (F), start floor (S), goal floor (G), up (U) and down (D) steps
	// Reading input
	cin >> F >> S >> G >> U >> D;

	bfs(F, S, U, D); // Start BFS

	// Outputting the result
	if (S == G)
		cout << "0"; // If start floor is the goal floor
	else if (f[G] > 0)
		cout << f[G]; // If goal floor is reachable
	else
		cout << "use the stairs"; // If goal floor is not reachable
}
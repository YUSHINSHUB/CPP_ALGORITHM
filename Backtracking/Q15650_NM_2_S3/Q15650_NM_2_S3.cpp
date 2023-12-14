/*
commented by ChatGPT
This C++ code generates all possible combinations of m-length numbers from a given range [1, n] without repetition.
Using backtracking, the code explores combinations in increasing order.
이 C++ 코드는 주어진 범위 [1, n]에서 중복 없이 m-길이의 조합을 생성하고 출력합니다.
백트래킹을 사용하여 증가하는 순서로 조합을 탐색합니다.
*/

#include <iostream>
#include <deque>
using namespace std;

int n, m; // Declaring variables for the range and length of combinations
// 범위와 조합의 길이를 위한 변수 선언

bool visited[9] = { false, }; // Array to keep track of the visited numbers
// 방문한 숫자를 추적하기 위한 배열

deque<int> dq; // Use Deque to store the current combination
// 현재 조합을 저장하기 위해 Deque 사용

void bt(int idx) {
	// Backtracking function to generate combinations
	// 조합을 생성하기 위한 백트래킹 함수

	if (dq.size() == m) { // If the current combination has the required length
		// 현재 조합이 필요한 길이를 가지면
		for (int i = 0; i < dq.size(); i++) {
			int t = dq.front(); // Get and remove the first element from the deque
			// deque에서 첫 번째 요소를 가져와 제거
			dq.pop_front();
			cout << t << " ";
			dq.push_back(t); // Add the element back to the end
			// 요소를 다시 끝에 추가
		}
		cout << "\n";
	}
	else {
		for (int i = idx + 1; i <= n; i++) {

			if (visited[i]) // If the number is already in the combination, skip it
				// 숫자가 이미 조합에 있다면 건너뜀
				continue;

			dq.push_back(i); // Add the number to the current combination
			// 숫자를 현재 조합에 추가
			visited[i] = true; // Mark the number as visited
			// 숫자를 방문했음으로 표시
			bt(i); // Recursive call to continue building the combination
			// 조합을 계속 구축하기 위한 재귀 호출
			dq.pop_back(); // Remove the last added number to backtrack
			// 백트래킹을 위해 마지막에 추가한 숫자 제거
			visited[i] = false; // Mark the number as unvisited for the next iteration
			// 다음 반복을 위해 숫자를 방문하지 않았음으로 표시
		}
	}
}

int main() {
	cin >> n >> m;
	bt(0); // Start the backtracking process
}

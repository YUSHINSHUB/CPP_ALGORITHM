/*
commented by ChatGPT
This C++ code generates all possible combinations of m-length numbers from a given range [1, n] and prints them.
Using backtracking, the code explores every possible combination without repetition.
이 C++ 코드는 주어진 범위 [1, n]에서 가능한 모든 m-길이 조합을 생성하고 출력합니다.
백트래킹을 사용하여 중복 없이 모든 가능한 조합을 탐색합니다.
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

void bt() {
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
		for (int i = 1; i <= n; i++) {

			if (visited[i]) // If the number is already in the combination, skip it
				// 숫자가 이미 조합에 있다면 건너뜀
				continue;

			dq.push_back(i); // Add the number to the current combination
			// 숫자를 현재 조합에 추가
			visited[i] = true; // Mark the number as visited
			// 숫자를 방문했음으로 표시
			bt(); // Recursive call to continue building the combination
			// 조합을 계속 구축하기 위한 재귀 호출
			dq.pop_back(); // Remove the last added number to backtrack
			// 백트래킹을 위해 마지막에 추가한 숫자 제거
			visited[i] = false; // Mark the number as unvisited for the next iteration
			// 다음 반복을 위해 숫자를 방문하지 않았음으로 표시
		}
	}
}

int main()
{
	cin >> n >> m;
	bt(); // Start the backtracking process
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

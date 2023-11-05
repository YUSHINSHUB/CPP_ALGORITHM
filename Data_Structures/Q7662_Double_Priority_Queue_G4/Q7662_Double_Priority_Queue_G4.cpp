/*
commented by ChatGPT
This C++ code implements a dual-priority queue system using a max-heap and a min-heap to perform a series of insertions and deletions.
It keeps track of the number of occurrences of each number to handle duplicate values.
After processing all operations, it prints out the maximum and minimum values in the queue, or "EMPTY" if the queue is empty.
이 C++ 코드는 최대 힙과 최소 힙을 사용하여 일련의 삽입 및 삭제를 수행하는 이중 우선순위 큐 시스템을 구현합니다.
중복 값 처리를 위해 각 숫자의 발생 횟수를 추적합니다.
모든 연산을 처리한 후, 큐에서 최대 및 최소 값을 출력하거나 큐가 비어 있으면 "EMPTY"를 출력합니다.
*/

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T; // 테스트 케이스의 수를 입력받음

	for (int i = 0; i < T; i++) {
		int k;
		cin >> k; // 연산의 개수를 입력받음
		map<int, int> hm; // 각 숫자의 개수를 저장하는 맵
		priority_queue<int> gr; // 최대 힙
		priority_queue<int, vector<int>, greater<int>> sm; // 최소 힙

		for (int j = 0; j < k; j++) {
			// 최대 힙과 최소 힙이 비어있다면 모든 요소를 제거
			if (gr.empty()) {
				while (!sm.empty()) sm.pop();
			}
			if (sm.empty()) {
				while (!gr.empty()) gr.pop();
			}

			string s; // 연산 종류
			int temp; // 연산에 사용될 숫자
			cin >> s >> temp;

			if (s == "I") { // 삽입 연산
				sm.push(temp);
				gr.push(temp);
				hm[temp]++; // 숫자의 개수를 1 증가
			}
			else {
				if (temp == 1) { // 최대값 삭제 연산
					if (!gr.empty()) {
						while (!gr.empty() && hm[gr.top()] == 0) {
							gr.pop(); // 이미 삭제된 숫자를 제거
						}
						if (!gr.empty()) {
							int t = gr.top();
							gr.pop();
							hm[t]--; // 숫자의 개수를 1 감소
						}
					}
				}
				else { // 최소값 삭제 연산
					if (!sm.empty()) {
						while (!sm.empty() && hm[sm.top()] == 0) {
							sm.pop(); // 이미 삭제된 숫자를 제거
						}
						if (!sm.empty()) {
							int t = sm.top();
							sm.pop();
							hm[t]--; // 숫자의 개수를 1 감소
						}
					}
				}
			}
		}

		// 최종 결과 출력
		if (!sm.empty()) {
			while (!sm.empty() && hm[sm.top()] == 0) sm.pop(); // 유효하지 않은 숫자 제거
		}
		if (!gr.empty()) {
			while (!gr.empty() && hm[gr.top()] == 0) gr.pop(); // 유효하지 않은 숫자 제거
		}
		if (gr.empty() || sm.empty()) cout << "EMPTY\n"; // 비어있다면 EMPTY 출력
		else cout << gr.top() << " " << sm.top() << "\n"; // 최대값과 최소값 출력
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

/*
commented by ChatGPT
This C++ code implements a recursive approach to process a sequence of numbers representing a binary search tree (BST). It reads integers until EOF, storing them in a queue.
The recursive function 'recur' then rebuilds the BST and performs a post-order traversal, ensuring each node is within a specified range. During the traversal, it prints each node's value.
The main function initializes the process by extracting the root node from the queue and calling 'recur'.
이 C++ 코드는 이진 탐색 트리(BST)를 나타내는 일련의 숫자를 처리하기 위한 재귀적 접근법을 구현합니다. EOF까지 정수를 읽어 큐에 저장합니다.
재귀 함수 'recur'는 BST를 재구성하고 후위 순회를 수행하여 각 노드가 지정된 범위 내에 있는지 확인합니다. 순회하는 동안 각 노드의 값을 출력합니다.
메인 함수는 큐에서 루트 노드를 추출하고 'recur'를 호출하여 프로세스를 초기화합니다.
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

static queue<int> input; // 입력된 정수를 저장할 큐

// 재귀 함수 'recur' 정의
static void recur(int node, int hig, int low) {
	// 큐가 비어있는 경우, 현재 노드를 출력하고 함수 종료
	if (input.empty()) {
		cout << node << "\n";
		return;
	}

	int cur = input.front(); // 큐의 첫 번째 요소 확인
	// 현재 요소가 지정된 범위 내에 있고 node보다 작은 경우
	if (cur < hig && cur > low) {
		if (cur < node) {
			input.pop(); // 큐에서 요소 제거
			recur(cur, node, low); // 좌측 자식 노드로 재귀 호출
		}
	}

	// 큐가 비어있는 경우, 현재 노드를 출력하고 함수 종료
	if (input.empty()) {
		cout << node << "\n";
		return;
	}

	cur = input.front(); // 큐의 첫 번째 요소 재확인
	// 현재 요소가 지정된 범위 내에 있고 node보다 큰 경우
	if (cur < hig && cur > low) {
		if (cur > node) {
			input.pop(); // 큐에서 요소 제거
			recur(cur, hig, node); // 우측 자식 노드로 재귀 호출
		}
	}

	// 현재 노드를 출력
	cout << node << "\n";
}

int main() {
	string inp;

	// 입력된 모든 줄을 읽어 큐에 추가
	while (getline(cin, inp)) {
		input.push(stoi(inp));
	}

	int top = input.front(); // 큐의 첫 번째 요소(루트 노드)를 제거하고 변수에 저장
	input.pop();

	recur(top, 1000000, -1); // 재귀 함수 호출
}
/*
commented by ChatGPT
This C++ code implements a recursive function to create a story-like narrative involving a computer science student and a professor.
The story structure is built using a recursive function recur, which builds the narrative string sb by repeatedly asking and answering the question "What is a recursive function?".
The story is indented according to the recursive depth, represented by underscores, to simulate the concept of recursion.
The base case occurs when the recursion depth reaches the input value N, at which point a final answer is provided.
The program uses a global variable sb to build the story and N to determine the depth of recursion.

이 C++ 코드는 컴퓨터 공학과 학생과 교수가 등장하는 이야기 같은 내러티브를 만드는 재귀 함수를 구현합니다.
이야기 구조는 "재귀 함수가 무엇인가요?"라는 질문을 반복적으로 하고 대답하면서 재귀 함수 recur을 사용하여 내러티브 문자열 sb를 구축합니다.
이야기는 재귀의 깊이에 따라 밑줄을 사용하여 들여쓰기되어 재귀 개념을 시뮬레이션합니다.
기본 케이스는 재귀 깊이가 입력 값 N에 도달했을 때 발생하며, 이때 최종적인 대답이 제공됩니다.
프로그램은 글로벌 변수 sb를 사용하여 이야기를 구축하고 N을 사용하여 재귀의 깊이를 결정합니다.
*/

#include <iostream>

using namespace std;

string sb = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n"; // 이야기 시작
int N; // 재귀의 깊이

void recur(int idx) { // 재귀 함수 정의

	if (idx == N) { // 기본 케이스: 재귀 깊이가 N에 도달
		for (int i = 0; i < idx; i++) { // 들여쓰기
			for (int j = 0; j < 4; j++) {
				sb += "_";
			}
		}
		sb += "\"재귀함수가 뭔가요?\"\n";
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < 4; j++) {
				sb += "_";
			}
		}
		sb += "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	}
	else { // 재귀 케이스

		for (int i = 0; i < idx; i++) { // 들여쓰기
			for (int j = 0; j < 4; j++) {
				sb += "_";
			}
		}
		sb += "\"재귀함수가 뭔가요?\"\n";
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < 4; j++) {
				sb += "_";
			}
		}
		sb += "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < 4; j++) {
				sb += "_";
			}
		}
		sb += "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < 4; j++) {
				sb += "_";
			}
		}
		sb += "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

		recur(idx + 1); // 재귀 호출

	}

	for (int i = 0; i < idx; i++) { // 대화 닫는 부분
		for (int j = 0; j < 4; j++) {
			sb += "_";
		}
	}
	sb += "라고 답변하였지.\n";
}

int main() {
	cin >> N; // 재귀 깊이 입력

	recur(0); // 재귀 함수 호출

	cout << sb; // 결과 출력
}
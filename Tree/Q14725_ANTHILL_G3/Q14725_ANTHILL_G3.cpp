/*
commented by ChatGPT
This C++ program builds a hierarchical structure from input strings using a Trie data structure, similar to the Java version previously discussed.
It displays the structure in a sorted, indented format.
이 C++ 프로그램은 Trie 데이터 구조를 사용하여 입력 문자열로부터 계층적 구조를 만들고, 이를 정렬된 들여쓰기 형식으로 표시합니다.
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int K = 0; // 글로벌 변수 K는 각 입력 라인의 문자열 수를 나타냅니다.

class TrieNode {
public:
	map<string, TrieNode*> child; // 자식 노드를 저장하는 맵. 각 키는 문자열이고 값은 TrieNode 포인터입니다.

	TrieNode() {} // 기본 생성자

	// 입력 문자열 배열로 Trie 구조를 구축하는 함수
	void input(string inp[]) {
		TrieNode* node = this;
		for (int i = 0; i < K; i++) {
			if (node->child.find(inp[i]) == node->child.end())
				node->child[inp[i]] = new TrieNode(); // 현재 노드에 입력 문자열이 없으면 새 노드를 추가
			node = node->child[inp[i]]; // 다음 노드로 이동
		}
	}
};

// Trie 구조를 출력하는 함수. 각 노드의 자식을 정렬하여 출력합니다.
void output(TrieNode* node, int depth) {
	vector<string> list;
	for (auto ent : node->child) {
		list.push_back(ent.first); // 현재 노드의 자식들의 키(문자열)를 리스트에 추가
	}
	sort(list.begin(), list.end()); // 리스트를 사전순으로 정렬
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < depth; j++)
			cout << "--"; // 깊이에 따라 들여쓰기
		cout << list[i] << "\n";
		output(node->child[list[i]], depth + 1); // 재귀적으로 자식 노드 출력
	}
}

int main() {
	int N;
	cin >> N;
	string in[15]; // 입력 문자열 저장 배열
	TrieNode node; // 루트 TrieNode

	// 입력 받기 및 Trie 구축
	for (int i = 0; i < N; i++) {
		cin >> K; // 각 줄의 문자열 수 입력
		for (int j = 0; j < K; j++)
			cin >> in[j]; // 문자열 입력
		node.input(in); // Trie에 문자열 추가
	}

	output(&node, 0); // Trie 구조 출력
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

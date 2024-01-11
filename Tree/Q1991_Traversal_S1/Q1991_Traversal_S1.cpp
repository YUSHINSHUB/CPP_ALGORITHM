/*
commented by ChatGPT
This C++ code implements tree traversal algorithms (preorder, inorder, and postorder) for a binary tree.
The binary tree is represented using an array of node objects, each holding indices for its left and right children.
The tree is built based on input characters representing each node and its children.
The traversal functions (pre, ino, pos) recursively visit the nodes in the specified order and concatenate the character representation of each node to the string sb.
After the traversals, the string containing the results of each traversal is output to the console.

이 C++ 코드는 이진 트리에 대한 트리 순회 알고리즘(전위, 중위, 후위 순회)을 구현합니다.
이진 트리는 각각 왼쪽 및 오른쪽 자식 인덱스를 가진 node 객체의 배열을 사용하여 표현됩니다.
트리는 각 노드와 그 자식들을 나타내는 입력 문자를 기반으로 구축됩니다.
순회 함수(pre, ino, pos)는 지정된 순서대로 노드를 재귀적으로 방문하고 각 노드의 문자 표현을 문자열 sb에 연결합니다.
순회 후, 각 순회의 결과를 담은 문자열이 콘솔에 출력됩니다.
*/

#include <iostream>
using namespace std;

class node {
public:
	int left = -1;
	int right = -1;

	node() {
	}
};

int N; // 트리의 노드 수
string sb = ""; // 출력을 저장할 문자열
node n[26]; // 노드 배열 (알파벳의 개수만큼)

// 전위 순회 함수
void pre(int idx) {
	sb += ((char)(idx + 'A')); // 노드 방문
	if (n[idx].left >= 0) // 왼쪽 자식 존재 시 순회
		pre(n[idx].left);
	if (n[idx].right >= 0) // 오른쪽 자식 존재 시 순회
		pre(n[idx].right);
}

// 중위 순회 함수
void ino(int idx) {
	if (n[idx].left >= 0) // 왼쪽 자식 존재 시 순회
		ino(n[idx].left);
	sb += ((char)(idx + 'A')); // 노드 방문
	if (n[idx].right >= 0) // 오른쪽 자식 존재 시 순회
		ino(n[idx].right);
}

// 후위 순회 함수
void pos(int idx) {
	if (n[idx].left >= 0) // 왼쪽 자식 존재 시 순회
		pos(n[idx].left);
	if (n[idx].right >= 0) // 오른쪽 자식 존재 시 순회
		pos(n[idx].right);
	sb += ((char)(idx + 'A')); // 노드 방문
}

int main()
{
	char a, b, c;
	int in1, in2, in3;

	cin >> N; // 노드 수 입력 받기

	// 트리 구성
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		in1 = a - 'A';
		in2 = b - 'A';
		in3 = c - 'A';

		if (in2 >= 0 && in2 <= 25) {
			n[in1].left = in2; // 왼쪽 자식 설정
		}
		if (in3 >= 0 && in3 <= 25) {
			n[in1].right = in3; // 오른쪽 자식 설정
		}
	}

	// 트리 순회
	pre(0); // 전위 순회
	sb += ("\n");
	ino(0); // 중위 순회
	sb += ("\n");
	pos(0); // 후위 순회
	sb += ("\n");

	// 결과 출력
	cout << sb;
}
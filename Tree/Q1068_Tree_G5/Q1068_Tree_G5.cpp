/*
commented by ChatGPT
This C++ code implements a tree data structure to simulate the removal of a node and its children in a tree.
It constructs the tree based on parent-child relationships input by the user, then removes a specified node and all its descendants.
After the removal, it counts the remaining leaf nodes in the tree.
Each tree node is represented by a class Tree, which contains a parent identifier and a list of children.
The remove function recursively removes a node and its children by setting their parent identifier to -2.
이 C++ 코드는 트리 데이터 구조를 구현하여 트리에서 노드와 그 자식들을 제거하는 것을 시뮬레이션합니다.
사용자가 입력한 부모-자식 관계를 바탕으로 트리를 구성한 후, 지정된 노드와 그 모든 자손을 제거합니다.
제거 후에는 트리에 남아 있는 리프 노드의 수를 계산합니다. 각 트리 노드는 부모 식별자와 자식 목록을 포함하는 Tree 클래스로 표현됩니다.
remove 함수는 노드와 그 자식들의 부모 식별자를 -2로 설정하여 재귀적으로 제거합니다.
*/

#include <iostream>
#include <vector>

using namespace std;

class Tree {
public:
	int parent; // Parent of the current node (현재 노드의 부모)
	vector<int> child; // List of children of the current node (현재 노드의 자식 목록)

	Tree() { // Constructor (생성자)
	}

	void setPar(int parent) { // Set the parent of the current node (현재 노드의 부모 설정)
		this->parent = parent;
	}

	void addChild(int child) { // Add a child to the current node (현재 노드에 자식 추가)
		this->child.push_back(child);
	}

	int NumberOfChild() { // Return the number of children (자식의 수 반환)
		return this->child.size();
	}
};

int N; // Number of nodes in the tree (트리의 노드 수)
Tree tree[50]; // Array to store tree nodes (트리 노드를 저장하는 배열)

// Function to remove a node and its descendants (노드와 그 자손을 제거하는 함수)
static void remove(int idx) {
	tree[idx].parent = -2; // Mark the node as removed (노드를 제거된 것으로 표시)
	for (int i = 0; i < tree[idx].NumberOfChild(); i++) {
		remove(tree[idx].child[i]); // Recursively remove all children (모든 자식을 재귀적으로 제거)
	}
}

int main() {
	int res = 0; // Variable to count the number of leaf nodes (리프 노드의 수를 세는 변수)
	int rem, par; // Variables for removed node and parent (제거된 노드와 부모에 대한 변수)

	cin >> N; // Read the number of nodes (노드 수 읽기)

	// Initialize each tree node and set parent-child relationships (각 트리 노드 초기화 및 부모-자식 관계 설정)
	for (int i = 0; i < N; i++) {
		cin >> par; // Read the parent of the current node (현재 노드의 부모 읽기)
		tree[i].setPar(par); // Set the parent of the current node (현재 노드의 부모 설정)
		if (par >= 0)
			tree[par].addChild(i); // Add the current node as a child to its parent (현재 노드를 부모의 자식으로 추가)
	}
	cin >> rem; // Read the node to be removed (제거할 노드 읽기)
	remove(rem); // Remove the specified node and its descendants (지정된 노드와 그 자손 제거)

	// Count the remaining leaf nodes (남아 있는 리프 노드 세기)
	for (int i = 0; i < N; i++) {
		if (tree[i].parent < -1) // Skip removed nodes (제거된 노드 건너뛰기)
			continue;
		if (tree[i].child.size() == 0 || (tree[i].child.size() == 1 && tree[i].child[0] == rem))
			res++;
	}

	cout << res; // Output the number of remaining leaf nodes (남아 있는 리프 노드의 수 출력)
}
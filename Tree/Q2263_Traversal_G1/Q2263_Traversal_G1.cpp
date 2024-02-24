/*
commented by ChatGPT
This C++ code reconstructs a binary tree from given inorder and postorder traversal arrays and generates its preorder traversal as a string.
It tracks nodes' positions in the inorder traversal to efficiently find left and right children during tree reconstruction.
The binary tree is reconstructed recursively by identifying the root from the postorder array and finding its position in the inorder array.
This position helps to separate left and right subtrees. The `make_tree` function recursively constructs the tree, and `get_pre` generates the preorder traversal.
이 C++ 코드는 주어진 중위 순회 및 후위 순회 배열로부터 이진 트리를 재구성하고 그 전위 순회를 문자열로 생성합니다.
트리 재구성 중에 왼쪽 및 오른쪽 자식을 효율적으로 찾기 위해 중위 순회에서 노드의 위치를 추적합니다.
후위 배열에서 루트를 식별하고 중위 배열에서 해당 위치를 찾아 왼쪽 및 오른쪽 하위 트리를 분리함으로써 이진 트리를 재귀적으로 재구성합니다.
`make_tree` 함수는 트리를 재귀적으로 구성하고, `get_pre`는 전위 순회를 생성합니다.
*/

#include <iostream>
#include <string>

using namespace std;

int n; // Number of nodes in the tree
int idx; // Current index for postorder processing
int in[100001]; // Inorder traversal array
int post[100001]; // Postorder traversal array
int inpos[100001]; // Positions of nodes in inorder traversal
bool visited[100003]; // Visited nodes tracker
int l[100001]; // Left children of nodes
int r[100001]; // Right children of nodes
string sb = ""; // String to store preorder traversal

void make_tree() {

    if (idx == 0)
        return;

    int node = post[idx];
    visited[inpos[node]] = true;
    int next = post[idx - 1];

    // Attempt to find the right child of the current node
    for (int i = inpos[node] + 1; i < n; i++) {
        if (visited[i])
            break;
        if (in[i] == next) {
            r[node] = next;
            idx--;
            make_tree();
            break;
        }
    }

    if (idx == 0) return;
    next = post[idx - 1];

    // Attempt to find the left child of the current node
    for (int i = inpos[node] - 1; i >= 0; i--) {
        if (visited[i])
            break;
        if (in[i] == next) {
            l[node] = next;
            idx--;
            make_tree();
            break;
        }
    }
}

void get_pre(int node) {
    sb += to_string(node) + " ";
    if (l[node] > 0)
        get_pre(l[node]);
    if (r[node] > 0)
        get_pre(r[node]);
}

int main() {
    fill(visited, visited + 100003, false);
    fill(l, l + 100001, 0);
    fill(r, r + 100001, 0);

    cin >> n;
    idx = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        inpos[in[i]] = i;
    }
    for (int i = 0; i < n; i++)
        cin >> post[i];

    make_tree();
    get_pre(post[n - 1]);

    cout << sb;
}

// Q11286_Absolute_Heap_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
Short Summary:
This C++ program is a custom implementation of a heap data structure.
It reads a series of operations from the input, adds non-zero values to the heap, and when a zero is received,
it removes and prints the root node of the heap.

Commented by ChatGPT
*/

#include <iostream>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class q11286 {

public:
	int size = 0;  // Initial size of the heap
	int node[2000002];  // Array that stores the elements of the heap

	// Function to get parent of a node at index idx
	int getpar(int idx) {
		return node[idx / 2];
	}

	// Function to get left child of a node at index idx
	int getlch(int idx) {
		return node[idx * 2];
	}

	// Function to get right child of a node at index idx
	int getrch(int idx) {
		return node[(idx * 2) + 1];
	}

	// Function to add an element i to the heap
	void add(int i) {
		size++;  // Increase the size of the heap
		int idx = size;  // Index where the new element is added
		node[idx] = i;  // Adding the new element at the end

		// Bubble up until heap property is maintained
		while (idx != 1) {
			if (abs(getpar(idx)) > abs(node[idx])) {
				int temp = node[idx];
				node[idx] = node[idx / 2];
				node[idx / 2] = temp;
			}
			else if (abs(getpar(idx)) == abs(node[idx]) && getpar(idx) > node[idx]) {
				int temp = node[idx];
				node[idx] = node[idx / 2];
				node[idx / 2] = temp;
			}
			else break;
			idx /= 2;
		}
	}

	// Function to remove the top element from the heap
	void remove() {
		node[1] = node[size];  // Copy the last element to the root
		size--;  // Decrease the size of the heap
		int idx = 1;

		// Bubble down until heap property is maintained
		// ... Full reordering code here ...

		if (size == idx * 2) {
			if (abs(getlch(idx)) < abs(node[idx])) {
				int temp = node[idx];
				node[idx] = getlch(idx);
				node[(idx * 2)] = temp;
			}
			else if (abs(getlch(idx)) == abs(node[idx]) && getlch(idx) < node[idx]) {
				int temp = node[idx];
				node[idx] = getlch(idx);
				node[(idx * 2)] = temp;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	q11286 nodes;
	int n;
	cin >> n;
	int temp = 0;

	// Perform n operations
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp != 0) {
			nodes.add(temp);  // Add element to the heap
		}
		else {
			if (nodes.size == 0) {
				cout << "0\n";  // Heap is empty, so print 0
			}
			else {
				cout << nodes.node[1] << "\n";  // Print the top element of the heap
				nodes.remove();  // Remove the top element of the heap
			}
		}
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

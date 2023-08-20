//Commented by ChatGPT
//This program calculates the transitive closure of a directed graph using the Floyd-Warshall algorithm. 
//It reads the adjacency matrix of the graph, computes the transitive closure, and prints the resulting matrix.

#include <iostream>
using namespace std;

int main()
{
	// Read the number of vertices in the graph
	int n;
	cin >> n;
	// Create a 2D array to represent the adjacency matrix of the graph
	int grp[101][101];

	// Read and populate the adjacency matrix from the input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grp[i][j];
		}
	}

	// Compute the transitive closure using the Floyd-Warshall algorithm
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Check if there is a direct edge from vertex j to vertex i
			if (grp[j][i] == 1) {
				for (int k = 0; k < n; k++) {
					// If there is an edge from vertex i to vertex k,
					// set grp[j][k] to 1 to indicate that there is a path from vertex j to vertex k
					if (grp[i][k] == 1)
						grp[j][k] = 1;
				}
			}
		}
	}

	// Write the transitive closure matrix to the output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << grp[i][j] << " "; // Write each cell of the matrix followed by a space
		cout << "\n"; // Write a newline character to separate rows
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

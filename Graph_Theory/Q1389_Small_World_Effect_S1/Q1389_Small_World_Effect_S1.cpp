//Commented by ChatGPT
//Summary: This program calculates the person with the smallest total number of connections in a social network represented by a graph. 
//It updates the adjacency matrix to reflect the shortest path between any two nodes and calculates the total number of connections for each person.

#include <iostream>
#include <climits>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int n; // Number of people
	int m; // Number of connections
	cin >> n >> m;
	int res = 0; // Variable to store the person with the smallest total number of connections
	int low = INT_MAX; // Variable to store the smallest total number of connections

	// Define a 2D array kev to store connections between people
	vector<vector<int>> kev(n + 1, vector<int>(n + 1));

	// Fill the 2D array kev with -1 to indicate no known connections
	for (int i = 1; i <= n; i++)
		fill(kev[i].begin(), kev[i].end(), -1);

	int a, b;
	// Read the connections (edges) between people and update the 2D array kev
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		// Indicate a connection between people a and b in the 2D array kev
		kev[a][b] = 1;
		kev[b][a] = 1;
	}

	// Update the 2D array kev to reflect the shortest path between any two nodes
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) // Ignore self-loops
				continue;
			if (kev[j][i] > 0) {
				for (int k = 1; k <= n; k++) {
					if (k == i || k == j) // Ignore direct connections
						continue;
					if (kev[i][k] > 0 && kev[j][k] < 0) { // Update the matrix if there is an indirect connection
						kev[j][k] = kev[j][i] + kev[i][k];
						kev[k][j] = kev[j][i] + kev[i][k];
					}
					else if (kev[i][k] > 0) { // Update the matrix if a shorter path is found
						kev[j][k] = min(kev[j][k], kev[j][i] + kev[i][k]);
						kev[k][j] = min(kev[j][k], kev[k][j]);
					}
				}
			}
		}
	}

	// Calculate the total number of connections for each person
	for (int i = 1; i <= n; i++) {
		int temp = 0; // Variable to store the total number of connections for person i
		for (int j = 1; j <= n; j++) {
			temp += kev[i][j]; // Accumulate the total number of connections for person i
		}
		if (temp < low) { // Update the person with the smallest total number of connections and the value
			// of the smallest total number of connections
			low = temp;
			res = i;
		}
	}

	// Write the person with the smallest total number of connections to the output
	cout << res;
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

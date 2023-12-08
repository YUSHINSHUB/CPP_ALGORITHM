//Commented by ChatGPT
//The problem asks for the sum of submatrix elements within a given matrix. 

#include <iostream>
#include <vector>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Take the size of matrix and number of sub-matrices as input
	int n, m;
	cin >> n >> m;

	// Define the prefix sum matrix
	vector<vector<int>> ps(n + 1, vector<int>(n + 1));
	// Fill the prefix sum matrix
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> ps[i][j];
	}

	// Initialize the first row and column of prefix sum matrix to 0
	for (int i = 0; i <= n; i++) {
		ps[0][i] = 0;
		ps[i][0] = 0;
	}

	// Compute the prefix sum
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
		}
	}

	// Handle each sub-matrix query
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// Compute the sum of elements in the sub-matrix using the prefix sum
		int res = ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
		cout << res << "\n";
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

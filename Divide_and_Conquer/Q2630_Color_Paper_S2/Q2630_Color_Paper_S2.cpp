//Commented by ChatGPT
//Summary: This program performs a recursive counting or partitioning operation on a matrix based on a certain criterion. 
//It divides the matrix into smaller sub-matrices and determines if they meet the criteria for incrementing a counter.


#include <iostream>

using namespace std;

// Define 2D array pap to store the matrix, 1D array res to store the count for
	// each category, and integer n for the dimension of the matrix
static int pap[128][128];
static int n;
static int res[2];

// Recursive function to count or partition the matrix based on certain criteria
static void recur(int m) {
	bool pass = true;

	// Loop through the matrix in steps of size m
	for (int i = 0; i < n; i += m) {
		for (int j = 0; j < n; j += m) {
			if (pap[i][j] == 2)
				continue;
			int t = pap[i][j];
			pass = true;
			// Check if all elements in the sub-matrix of size m have the same value as the
			// top-left element
			for (int k = i; k < i + m; k++) {
				for (int l = j; l < j + m; l++) {
					if (pap[k][l] != t) {
						pass = false;
						break;
					}
				}
				if (!pass)
					break;
			}
			if (!pass)
				continue;

			// If all elements are equal, increment the corresponding counter in res array
			// and mark the sub-matrix elements as 2
			res[t]++;
			for (int k = i; k < i + m; k++) {
				for (int l = j; l < j + m; l++) {
					pap[k][l] = 2;
				}
			}
		}
	}

	// Check if the entire matrix has been marked as 2
	pass = true;
	for (int i = 0; i < n; i += m) {
		for (int j = 0; j < n; j += m) {
			if (pap[i][j] != 2) {
				pass = false;
				break;
			}
		}
		if (!pass)
			break;
	}

	// If the entire matrix is not marked as 2, continue the recursion with smaller
	// sub-matrix size
	if (pass)
		return;
	else
		recur(m / 2);
}


int main()
{
	// Read the dimension of the matrix
	cin >> n;
	bool pass = true;

	// Read the elements of the matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> pap[i][j];
		}
	}

	// Check if all elements of the matrix have the same value
	int t = pap[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pap[i][j] != t) {
				pass = false;
				break;
			}
		}
		if (!pass)
			break;
	}

	// If all elements are equal, write the appropriate count for each category
	if (pass) {
		if (pap[0][0] == 0)
			cout << "1\n0";
		else
			cout << "0\n1";
	}
	else {
		// If elements are not equal, start the recursive counting or partitioning
		recur(n / 2);
		cout << res[0] << "\n" << res[1];
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

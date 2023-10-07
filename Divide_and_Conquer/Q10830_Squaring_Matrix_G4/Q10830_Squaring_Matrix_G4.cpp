/*
commented by ChatGPT
이 C++ 코드는 주어진 정사각 행렬을 지정된 수만큼 제곱하는 작업을 수행합니다. 
이를 위해 이진수 표현을 활용하여 지정된 제곱 수를 분해하고, 해당 분해된 값만큼 행렬을 제곱합니다.
곱셈 결과의 각 원소는 1000으로 나눈 나머지로 저장됩니다.

This C++ code exponentiates a given square matrix by a specified number. 
It decomposes the given exponent number using its binary representation and exponentiates the matrix accordingly.
Each element of the multiplication result is stored as the modulo 1000 value.
*/

#include <iostream>
#include <math.h>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int tr10830[6][6]; // 임시 결과를 저장하는 전역 행렬 (Global matrix to store temporary results)
vector<vector<int>> res10830(6, std::vector<int>(6)); // 최종 결과를 저장하는 행렬 (Matrix to store the final result)

// 두 행렬을 곱하는 함수 (Function to multiply two matrices)
static void calc10830(vector<vector<int>> mat, vector<vector<int>> t, int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp = 0;
			for (int k = 0; k < n; k++) {
				temp += (t[i][k] * mat[k][j]) % 1000; // 행렬 원소 간의 곱셈 연산 (Multiplication operation between matrix elements)
			}
			tr10830[i][j] = temp % 1000; // 결과는 1000으로 나눈 나머지로 저장 (Store result as modulo 1000)
		}
	}
}

int main() {

	int n;
	long long b; // 제곱할 수 (Exponent number)

	cin >> n >> b;

	vector<vector<int>> mat(n, vector<int>(n)); // 입력 행렬 (Input matrix)
	vector<vector<int>> t(n, vector<int>(n));   // 임시 행렬 (Temporary matrix)
	vector<vector<int>> tt(n, vector<int>(n));  // 또 다른 임시 행렬 (Another temporary matrix)

	// 행렬 데이터 입력 (Matrix data input)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			res10830[i][j] = mat[i][j];
			t[i][j] = mat[i][j];
			tt[i][j] = mat[i][j];
		}
	}

	// b가 1일 경우 원래 행렬 출력 (If b is 1, output the original matrix)
	if (b == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << mat[i][j] % 1000 << " ";
			cout << "\n";
		}
	}
	else {
		// 이진 표현법을 사용하여 행렬을 b만큼 제곱 (Exponentiate the matrix by b using binary representation)
		int cnt = 0;

		cnt = (int)(log(b) / log(2)); // 이진 표현을 사용한 b의 분해 (Decompose b using its binary representation)
		b -= pow(2, cnt);

		for (int i = 0; i < cnt; i++) {
			calc10830(t, tt, n); // 행렬 곱하기 (Matrix multiplication)
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					t[j][k] = tr10830[j][k];
					tt[j][k] = tr10830[j][k];
				}
			}
		}

		// 임시 결과를 최종 결과 행렬에 저장 (Store the temporary result in the final result matrix)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res10830[j][k] = tr10830[j][k];
			}
		}

		// b의 나머지 값에 대한 처리 (Processing for the remainder of b)
		while (b > 1) {
			cnt = (int)(log(b) / log(2));
			b -= pow(2, cnt);

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					t[j][k] = mat[j][k];
					tt[j][k] = mat[j][k];
				}
			}

			for (int i = 0; i < cnt; i++) {
				calc10830(t, tt, n);
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						t[j][k] = tr10830[j][k];
						tt[j][k] = tr10830[j][k];
					}
				}
			}

			calc10830(t, res10830, n);

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res10830[j][k] = tr10830[j][k];
				}
			}
		}

		// b가 1로 줄어든 경우 원래 행렬과 최종 결과 행렬을 곱함 (If b has been reduced to 1, multiply the original matrix with the final result matrix)
		if (b == 1) {
			calc10830(mat, res10830, n);
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res10830[j][k] = tr10830[j][k];
			}
		}

		// 최종 결과 출력 (Output the final result)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << res10830[i][j] % 1000 << " ";
			cout << "\n";
		}

	}

	return 0;
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


/*
commented by ChatGPT
This C++ code implements the Quadtree compression algorithm for a binary image represented as a 2D grid (grid).
The algorithm recursively divides the image into four quadrants and checks if each quadrant can be represented by a single number (0 or 1).
If all cells in a quadrant are the same, the quadrant is represented by that single number.
Otherwise, it is subdivided into smaller quadrants, and the process repeats.
The recur function handles this recursive division and creates a string that represents the compressed form of the image.
This string is structured with parentheses grouping the four sub-quadrants of each divided quadrant.
The main function reads the image size (N) and the grid data, and then calls recur to compress the image and output the result.
이 C++ 코드는 2D 그리드(grid)로 표현된 이진 이미지에 대한 쿼드트리 압축 알고리즘을 구현합니다.
이 알고리즘은 이미지를 네 개의 사분면으로 재귀적으로 나누고 각 사분면이 단일 숫자(0 또는 1)로 표현될 수 있는지 확인합니다.
사분면의 모든 셀이 같은 경우, 그 사분면은 해당 숫자로 표현됩니다.
그렇지 않으면 더 작은 사분면으로 나누어지고, 이 과정이 반복됩니다.
recur 함수는 이러한 재귀적 분할을 처리하고 이미지의 압축된 형태를 나타내는 문자열을 생성합니다.
이 문자열은 각 분할된 사분면의 네 개 하위 사분면을 괄호로 묶어 구조화됩니다.
main 함수는 이미지 크기(N)와 그리드 데이터를 읽은 다음 recur를 호출하여 이미지를 압축하고 결과를 출력합니다.
*/

#include <iostream>
#include <string>
using namespace std;

int grid[64][64]; // 2D array to store the binary image (이진 이미지를 저장하는 2D 배열)

// Recursive function for Quadtree compression (쿼드트리 압축을 위한 재귀 함수)
string recur(int idx, int y, int x) {
	string res = ""; // String to store the result (결과를 저장할 문자열)
	int sym; // Variable to check if all cells in the quadrant have the same value (사분면의 모든 셀이 동일한 값을 갖는지 확인하는 변수)
	if (grid[y][x] == 0)
		sym = 0;
	else
		sym = 1;

	// Check if all cells in the quadrant have the same value (사분면의 모든 셀이 동일한 값을 갖는지 확인)
	for (int i = y; i < y + idx; i++) {
		for (int j = x; j < x + idx; j++) {
			if (grid[i][j] != sym) {
				sym = -1;
				break;
			}
		}
		if (sym < 0)
			break;
	}

	// If all cells have the same value, return the value; otherwise, divide and recurse (모든 셀이 동일한 값을 갖으면 값을 반환하고, 그렇지 않으면 나누고 재귀)
	if (sym >= 0) {
		res += to_string(sym);
	}
	else {
		idx /= 2;
		res += "(";
		res += recur(idx, y, x);
		res += recur(idx, y, x + idx);
		res += recur(idx, y + idx, x);
		res += recur(idx, y + idx, x + idx);
		res += ")";
	}

	return res; // Return the compressed string (압축된 문자열 반환)
}

int main() {
	int N; // Variable for the size of the image (이미지 크기를 위한 변수)
	string inp; // Variable to read each line of the image (이미지의 각 줄을 읽기 위한 변수)

	cin >> N; // Read the size of the image (이미지 크기 읽기)
	for (int i = 0; i < N; i++) {
		cin >> inp; // Read each line of the image (이미지의 각 줄 읽기)
		for (int j = 0; j < N; j++) {
			grid[i][j] = inp[j] - '0'; // Store the image data in the grid (그리드에 이미지 데이터 저장)
		}
	}

	cout << recur(N, 0, 0); // Output the compressed image (압축된 이미지 출력)
}
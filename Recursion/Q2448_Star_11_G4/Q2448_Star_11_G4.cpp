
/*
commented by ChatGPT
This C++ code generates a fractal pattern in the shape of a Sierpinski triangle using recursion. The pattern is created by placing stars ('') in specific positions in a 2D character array.
The base case for the recursive function is when the size of the triangle (idx) is 3, at which point it directly places stars to form the smallest triangle unit.
For larger sizes, the function divides the problem into smaller triangles and calls itself recursively for each smaller triangle.
The main function reads the size of the pattern, initializes the 2D array with spaces, calls the recursive function to populate the array with the star pattern, and then prints the pattern.
이 C++ 코드는 재귀를 사용하여 시에르핀스키 삼각형 모양의 프랙탈 패턴을 생성합니다. 별('')을 2차원 문자 배열의 특정 위치에 배치함으로써 패턴이 만들어집니다.
재귀 함수의 기본 사례는 삼각형의 크기(idx)가 3일 때로, 이때 가장 작은 삼각형 단위를 형성하기 위해 직접 별을 배치합니다.
더 큰 크기의 경우, 함수는 문제를 더 작은 삼각형으로 나누고 각 작은 삼각형에 대해 자기 자신을 재귀적으로 호출합니다.
메인 함수는 패턴의 크기를 읽고, 2차원 배열을 공백으로 초기화하며, 재귀 함수를 호출하여 배열에 별 패턴을 채우고, 그런 다음 패턴을 출력합니다.
*/

#include <iostream>
using namespace std;

static char c[3072][6144]; // 2D char array to store the star pattern (별 패턴을 저장할 2차원 문자 배열)
static int N; // The size of the pattern (패턴의 크기)

// Recursive function to create the star pattern
void recur(int y, int x, int idx) {
	if (idx == 3) { // Base case: when the triangle size is 3, place stars to form a small triangle
		c[y][x] = '*';
		c[y + 1][x - 1] = '*';
		c[y + 1][x + 1] = '*';
		c[y + 2][x - 2] = '*';
		c[y + 2][x - 1] = '*';
		c[y + 2][x] = '*';
		c[y + 2][x + 1] = '*';
		c[y + 2][x + 2] = '*';
	}
	else { // Recursive case: divide the triangle into smaller ones and call the function on each
		int nx = idx / 2;
		recur(y, x, nx); // Top triangle
		recur(y + nx, x - nx, nx); // Bottom left triangle
		recur(y + nx, x + nx, nx); // Bottom right triangle
	}
}

int main() {
	string sb = ""; // String to store the final star pattern

	cin >> N; // Read the size of the pattern

	for (int i = 0; i < N; i++) fill(c[i], c[i] + N * 2, ' '); // Fill the array with spaces

	recur(0, N - 1, N); // Start the recursive function to create the star pattern

	// Loop through the array and append each character to the string
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++)
			sb += c[i][j];
		sb.append("\n"); // Add a newline character at the end of each row
	}

	cout << sb; // Output the final star pattern
}
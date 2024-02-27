
/*
commented by ChatGPT
This C++ code calculates the nth Fibonacci number using matrix exponentiation. It leverages the fact that Fibonacci numbers can be obtained by raising a specific 2x2 matrix to the nth power.
The approach optimizes the Fibonacci sequence calculation, especially for large n, by using recursion, matrix multiplication, and modulo operation to ensure results fit within integer bounds.
이 C++ 코드는 행렬 거듭제곱을 사용하여 n번째 피보나치 수를 계산합니다. 특정 2x2 행렬을 n번 거듭제곱함으로써 피보나치 수를 얻을 수 있다는 사실을 활용합니다.
재귀, 행렬 곱셈, 그리고 모듈로 연산을 사용하여 특히 큰 n에 대한 피보나치 수열 계산을 최적화하고, 결과가 정수 범위 내에 들어가도록 합니다.
*/

#include <iostream>

using namespace std;

int init[2][2] = { { 1, 1 }, { 1, 0 } }; // Initial matrix for Fibonacci sequence generation
long long matrix[2][2] = { { 1, 1 }, { 1, 0 } }; // Matrix used for exponentiation

// Squares the matrix and applies modulo to prevent overflow
void square() {
	long long temp[2][2]; // Temporary matrix to hold the result

	// Performing matrix multiplication and applying modulo
	temp[0][0] = ((matrix[0][0] * matrix[0][0]) + (matrix[0][1] * matrix[1][0])) % 1000000007;
	temp[0][1] = ((matrix[0][0] * matrix[0][1]) + (matrix[0][1] * matrix[1][1])) % 1000000007;
	temp[1][0] = ((matrix[1][0] * matrix[0][0]) + (matrix[1][1] * matrix[1][0])) % 1000000007;
	temp[1][1] = ((matrix[1][0] * matrix[0][1]) + (matrix[1][1] * matrix[1][1])) % 1000000007;

	// Copying the results back to the matrix
	matrix[0][0] = temp[0][0];
	matrix[0][1] = temp[0][1];
	matrix[1][0] = temp[1][0];
	matrix[1][1] = temp[1][1];
}

// Multiplies the current matrix by the initial matrix for the case of odd powers
void mul() {
	long long temp[2][2]; // Temporary matrix to hold the result

	// Performing matrix multiplication and applying modulo
	temp[0][0] = ((matrix[0][0] * init[0][0]) + (matrix[0][1] * init[1][0])) % 1000000007;
	temp[0][1] = ((matrix[0][0] * init[0][1]) + (matrix[0][1] * init[1][1])) % 1000000007;
	temp[1][0] = ((matrix[1][0] * init[0][0]) + (matrix[1][1] * init[1][0])) % 1000000007;
	temp[1][1] = ((matrix[1][0] * init[0][1]) + (matrix[1][1] * init[1][1])) % 1000000007;

	// Copying the results back to the matrix
	matrix[0][0] = temp[0][0];
	matrix[0][1] = temp[0][1];
	matrix[1][0] = temp[1][0];
	matrix[1][1] = temp[1][1];
}

// Recursive function to efficiently calculate the power of the matrix
void recur(long long cur) {
	if (cur == 1) // Base case: if power is 1, no further operation needed
		return;
	if (cur % 2 == 0) {
		recur(cur / 2); // For even powers, simply square the matrix
		square();
	}
	else {
		recur(cur / 2); // For odd powers, square the matrix then multiply by the initial matrix
		square();
		mul();
	}
}

int main() {
	long long n; // Variable to store the input n
	cin >> n; // Reading the nth term to calculate

	recur(n); // Calculating the nth power of the matrix to find the nth Fibonacci number

	// Outputting the nth Fibonacci number modulo 1000000007
	cout << matrix[1][0] % 1000000007;
}
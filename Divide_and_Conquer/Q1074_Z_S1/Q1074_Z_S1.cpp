// Q1074_Z_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
Commented by ChatGPT
Summary: This C++ program recursively calculates the value of a cell in a Z-shaped matrix. The matrix is created by recursively partitioning it into four equal quadrants, following a Z-shaped pattern. The program receives three integers, n, r, and c, and calculates the value of the cell located at row r and column c of the matrix of size 2^n x 2^n.
*/

#include <iostream>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Recursive function to calculate the value of a cell in a Z-shaped matrix
int calc(int n, int r, int c, int low, int hig) {
	n--;
	int res = 0;

	int line = (int)pow(2, n - 1); // Calculate the midpoint of the matrix
	int temp = (hig - low) / 4; // Calculate the interval size for each quadrant

	if (r > line && c > line) { // Bottom-right quadrant
		low += temp * 3;
		r -= line;
		c -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (r <= line && c <= line) { // Top-left quadrant
		hig = low + temp;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (r > line) { // Bottom-left quadrant
		low += temp * 2;
		hig = low + temp;
		r -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	else if (c > line) { // Top-right quadrant
		low += temp;
		hig = low + temp;
		c -= line;
		if (line == 1) return low;
		else res = calc(n, r, c, low, hig);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	r++;
	c++;

	int hig = (int)pow(4, n); // Calculate the highest value in the matrix
	int line = (int)pow(2, n - 1); // Calculate the midpoint of the matrix

	n++;
	int res = calc(n, r, c, 0, hig); // Call the recursive function

	cout << res; // Output the result
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

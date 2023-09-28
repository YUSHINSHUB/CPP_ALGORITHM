/*
Commented by ChatGPT
Summary: This program performs operations on an array of numbers.
The program reads an array of numbers and a set of operations, then uses recursion to
calculate the highest and lowest possible outcomes using the available operations.
*/

#include <iostream>
#include <climits>
using namespace std;

static int n; // Number of elements
static int num[12]; // Array of numbers
static int op[4]; // Array to hold the count of each operation
static int hig = INT_MIN; // Maximum possible result
static int low = INT_MAX; // Minimum possible result

// Recursive function to calculate the highest and lowest possible outcomes
void bt(int cur, int idx) {
	if (idx == n) { // If all numbers have been processed
		hig = max(hig, cur);
		low = min(low, cur);
	}
	else {
		for (int i = 0; i < 4; i++) { // Loop through the operations
			if (op[i] > 0) { // If operation count is greater than 0
				op[i]--; // Decrement operation count
				switch (i) { // Perform operation based on the index
				case 0:
					bt(cur + num[idx], idx + 1); // Addition
					break;
				case 1:
					bt(cur - num[idx], idx + 1); // Subtraction
					break;
				case 2:
					bt(cur * num[idx], idx + 1); // Multiplication
					break;
				case 3:
					bt(cur / num[idx], idx + 1); // Division
					break;
				}
				op[i]++; // Increment operation count
			}
		}
	}

	return;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) // Store the numbers
		cin >> num[i];

	for (int i = 0; i < 4; i++) // Store the operation counts
		cin >> op[i];

	bt(num[0], 1); // Start the recursive function

	cout << hig << "\n" << low; // Output the highest and lowest possible results

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

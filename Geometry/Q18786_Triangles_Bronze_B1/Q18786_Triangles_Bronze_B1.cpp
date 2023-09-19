// Commented by ChatGPT
// Summary: This C++ code determines the maximum rectangle area that can be formed using a set of 2D points.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Declaration of variables to store the number of points and their x, y coordinates.
	int n;
	int x[101];
	int y[101];

	// Reading the number of points from the user.
	cin >> n;

	// Storing the x and y coordinates of each point in the respective arrays.
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	// Variable to store the maximum rectangle area found so far.
	int res = 0;

	// Loop through each pair of points to determine if they can form one of the edges of a rectangle.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = 0;

			// Check if points (i and j) have the same x-coordinate, indicating a potential vertical rectangle edge.
			if (x[i] == x[j] && y[i] != y[j]) {

				// Calculating the length of this vertical edge.
				temp = (int)abs(y[i] - y[j]);

				// For the found vertical edge, search for a horizontal edge using another loop.
				for (int k = 0; k < n; k++) {
					if (y[i] == y[k] && x[i] != x[k]) {

						// Calculate the potential rectangle area using the found vertical and horizontal edges.
						temp *= (int)abs(x[i] - x[k]);

						// If the calculated area is larger than previous maximum, update the result.
						if (temp > res)
							res = temp;

						// Reset the temp value to its original state for other potential horizontal edges.
						temp /= (int)abs(x[i] - x[k]);
					}
				}
			}
		}
	}

	// Display the maximum rectangle area to the console.
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

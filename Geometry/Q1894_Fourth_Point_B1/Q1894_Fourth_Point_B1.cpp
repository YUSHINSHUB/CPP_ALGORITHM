/*
   commented by ChatGPT
   Summary: The C++ program reads sets of 8 numbers (coordinates of 4 points) from standard input
   and determines the coordinates of a parallelogram's fourth point based on the other three points.
   The program continues to process input until no more is available.
*/

#include <iostream>
using namespace std;

int main()
{
	// Optimize IO operations
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double x1, x2, x3, x4;
	double y1, y2, y3, y4;

	// Continue reading input until none is available
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {

		// Setting the precision for the output values to 3 decimal places
		cout.precision(3);

		// Using properties of parallelograms to determine the coordinates of the fourth point
		// The parallelogram sides are parallel and equal in length
		// Based on given 3 points, we determine the fourth point's coordinates
		if (x1 == x2 && y1 == y2) {
			x3 += x4 - x1;
			y3 += y4 - y1;
			cout << fixed << x3 << " " << fixed << y3 << "\n";
		}
		else if (x1 == x3 && y1 == y3) {
			x2 += x4 - x1;
			y2 += y4 - y1;
			cout << fixed << x2 << " " << fixed << y2 << "\n";
		}
		else if (x1 == x4 && y1 == y4) {
			x3 += x2 - x1;
			y3 += y2 - y1;
			cout << fixed << x3 << " " << fixed << y3 << "\n";
		}
		else if (x2 == x3 && y2 == y3) {
			x1 += x4 - x2;
			y1 += y4 - y2;
			cout << fixed << x1 << " " << fixed << y1 << "\n";
		}
		else if (x2 == x4 && y2 == y4) {
			x1 += x3 - x2;
			y1 += y3 - y2;
			cout << fixed << x1 << " " << fixed << y1 << "\n";
		}
		else {
			x1 += x2 - x3;
			y1 += y2 - y3;
			cout << fixed << x1 << " " << fixed << y1 << "\n";
		}
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

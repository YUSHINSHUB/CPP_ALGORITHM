// Commented by ChatGPT
// Summary: This C++ program calculates the difference between the maximum and minimum possible perimeter of a parallelogram formed using three input points and a derived fourth point. 
//			It checks all possible configurations of the points, calculates the perimeter for each, and outputs the difference between the maximum and minimum perimeters.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Reading the coordinates of three points.
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	// Check if the three points are collinear.
	if ((x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1)) {
		cout << "-1";
	}

	else {
		// Variables to store start, middle, and end point coordinates.
		double sx, sy, mx, my, ex, ey, x4, y4;
		// Variables to store length of sides.
		double len1, len2;
		// Variables to store perimeters for different configurations.
		double res1, res2, res3;

		// 1st configuration of points.
		sx = x2; sy = y2; mx = x1; my = y1; ex = x3; ey = y3;
		x4 = sx + (ex - mx);
		y4 = sy + (ey - my);
		len1 = sqrt(pow(mx - sx, 2) + pow(my - sy, 2));
		len2 = sqrt(pow(sx - x4, 2) + pow(sy - y4, 2));
		res1 = 2 * len1 + 2 * len2;

		// 2nd configuration of points.
		sx = x1; sy = y1; mx = x2; my = y2; ex = x3; ey = y3;
		x4 = sx + (ex - mx);
		y4 = sy + (ey - my);
		len1 = sqrt(pow(mx - sx, 2) + pow(my - sy, 2));
		len2 = sqrt(pow(sx - x4, 2) + pow(sy - y4, 2));
		res2 = 2 * len1 + 2 * len2;

		// 3rd configuration of points.
		sx = x1; sy = y1; mx = x3; my = y3; ex = x2; ey = y2;
		x4 = sx + (ex - mx);
		y4 = sy + (ey - my);
		len1 = sqrt(pow(mx - sx, 2) + pow(my - sy, 2));
		len2 = sqrt(pow(sx - x4, 2) + pow(sy - y4, 2));
		res3 = 2 * len1 + 2 * len2;

		// Determine minimum and maximum perimeters.
		double r1 = min(res1, min(res2, res3));
		double r2 = max(res1, max(res2, res3));

		// Output the difference between maximum and minimum perimeters with precision.
		cout.precision(10);
		cout << fixed << r2 - r1;
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

// Q3053_Taxi_Geometry_B3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
	commented by ChatGPT
	Summary: The C++ program calculates the area of a circle using two different methods and outputs both results. 
	The first method uses the traditional formula (pi*r^2), and the second adopts the "taxicab" or "Manhattan" geometry formula (2*r^2).
*/

// Disables the warning about using older, potentially unsafe functions.
#define _CRT_SECURE_NO_WARNINGS
// Define macro to access mathematical constants like M_PI.
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h> // For accessing M_PI constant and other math functionalities.

using namespace std;

int main() {

	// Read the radius of the circle.
	int r;
	cin >> r;

	// Calculate the area using standard Euclidean geometry.
	double uc = (double)r * (double)r * M_PI;

	// Calculate the area using taxicab (Manhattan) geometry.
	int tx = r * r * 2;

	// Set precision for floating point output.
	cout.precision(6);

	// Output both results.
	cout << fixed << uc << endl << tx;

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

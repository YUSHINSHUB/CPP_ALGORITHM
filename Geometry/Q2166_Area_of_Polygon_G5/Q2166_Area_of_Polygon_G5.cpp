/*
commented by ChatGPT
This C++ code computes the area of a polygon given its vertices using the Shoelace formula. The area is outputted as a decimal value.
이 C++ 코드는 주어진 꼭지점을 사용하여 다각형의 면적을 신발끈 공식을 사용하여 계산합니다. 면적은 소수점 값으로 출력됩니다.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

	// Reading the number of vertices
	// 꼭지점의 수를 읽습니다.
	int n;
	cin >> n;

	// Using vectors to store x and y coordinates of the vertices
	// 꼭지점의 x와 y 좌표를 저장하기 위해 벡터를 사용합니다.
	vector<double> x(n);
	vector<double> y(n);
	double xs = 0;
	double ys = 0;

	// Reading the vertices
	// 꼭지점을 읽습니다.
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	// Applying the Shoelace formula to calculate the area
	// 신발끈 공식을 적용하여 면적을 계산합니다.
	for (int i = 0; i < n - 1; i++) {
		xs += x[i] * y[i + 1];
		ys += y[i] * x[i + 1];
	}

	xs += x[n - 1] * y[0];
	ys += y[n - 1] * x[0];

	xs = abs(xs - ys);

	// Formatting and outputting the result
	// 결과를 형식화하고 출력합니다.
	long res = (long)xs;
	if (res % 2 == 0)
		cout << res / 2 << ".0";
	else
		cout << res / 2 << ".5";
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

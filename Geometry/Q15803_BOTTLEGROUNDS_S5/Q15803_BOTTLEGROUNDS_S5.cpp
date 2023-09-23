// Commented by ChatGPT
// Summary: This C++ code checks if three given points are collinear. If they are, it prints "WHERE IS MY CHICKEN?", otherwise, it prints "WINNER WINNER CHICKEN DINNER!".

#include <iostream>
#include <algorithm>
using namespace std;

// Define a pos class to hold the x and y coordinates of points.
class pos {
public:
	int x;
	int y;

	// Setter method to set the x and y coordinates.
	void setPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main()
{
	// Flag to store if the given points are collinear or not.
	bool win = true;

	// Array of pos objects to store the coordinates.
	pos p[3];

	// Input the x and y coordinates for each of the 3 points.
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		p[i].setPos(x, y);
	}

	// Sort the array based on the x coordinate.
	sort(p, p + 3, [](pos o1, pos o2) -> bool {
		return o1.x > o2.x;
		});

	// Calculate the difference in x and y coordinates for each pair of adjacent points.
	double x1 = p[1].x - p[0].x;
	double x2 = p[2].x - p[1].x;
	double y1 = p[1].y - p[0].y;
	double y2 = p[2].y - p[1].y;

	// Normalize the differences to get the slopes.
	x1 /= y1;
	x2 /= y2;

	// If the slopes are equal, set the flag to false.
	if (x1 == x2)
		win = false;

	// Output based on the flag.
	if (win)
		cout << "WINNER WINNER CHICKEN DINNER!";
	else
		cout << "WHERE IS MY CHICKEN?";
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

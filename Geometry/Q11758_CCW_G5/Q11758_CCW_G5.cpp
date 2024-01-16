/*
	commented by ChatGPT
	요약(Summary): 프로그램은 사용자로부터 3개의 2D 점을 입력받고, 이 점들이 시계 방향, 반시계 방향, 또는 일직선 상에 있는지 판별합니다.
*/

#include <iostream>

// 표준 네임스페이스 사용 (Using standard namespace)
using namespace std;

int main()
{
	// 3개의 2D 점의 x, y 좌표를 저장할 배열들을 선언 (Declare arrays to store x, y coordinates of 3 2D points)
	int x[3];
	int y[3];

	// 사용자로부터 3개의 점의 좌표를 순서대로 입력받는다. (Receive coordinates for 3 points from the user)
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}

	// 세 점의 CCW 값을 계산합니다. 이 계산은 점들 간의 벡터 외적을 사용하여 수행됩니다. 
	// (Calculate the CCW value for the three points. This calculation is done using cross product of vectors between the points.)
	int ccw = (x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0]);

	// 계산된 CCW 값에 따라 결과를 출력합니다.
	// (Print the result based on the calculated CCW value)
	if (ccw == 0)       // 점들이 일직선 상에 있을 경우 (If points are on a straight line)
		cout << "0";
	else if (ccw > 0)  // 점들이 반시계 방향을 형성할 경우 (If points form a counter-clockwise direction)
		cout << "1";
	else               // 점들이 시계 방향을 형성할 경우 (If points form a clockwise direction)
		cout << "-1";

	return 0;
}

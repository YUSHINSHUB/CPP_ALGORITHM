/*
commented by ChatGPT
This C++ program calculates the number of planetary systems that a spaceship needs to cross when traveling between two points in space. 
Each planetary system is represented as a circle, and the program checks whether the start or end points of the journey lie inside these circles.
이 C++ 프로그램은 우주의 두 점 사이를 여행하는 우주선이 거쳐야 하는 행성계의 수를 계산합니다. 
각 행성계는 원으로 표현되며, 프로그램은 여행의 시작점 또는 끝점이 이러한 원 안에 있는지를 확인합니다.
*/

#include <iostream>
#include <cmath> // Include cmath for pow function (pow 함수를 사용하기 위해 cmath 포함)

using namespace std;

int main()
{
	// Speed up input and output
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, n; // Number of test cases (테스트 케이스 수)
	int x1, y1, x2, y2; // Coordinates of start and end points (시작점과 끝점의 좌표)
	int x, y, r; // Coordinates and radius of each planetary system (각 행성계의 좌표와 반지름)
	int pdistance, ddistance; // Squared distances from start and end points to the center of a planetary system (시작점과 끝점에서 행성계 중심까지의 제곱 거리)
	int prince = 0; // Count of crossings for the starting point (시작점의 교차 횟수)
	int dist = 0; // Count of crossings for the destination point (목적지점의 교차 횟수)

	cin >> T;

	for (int idx = 0; idx < T; idx++) {
		prince = 0;
		dist = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> r;

			// Calculate squared radius and distances
			r = pow(r, 2);
			pdistance = pow(x1 - x, 2) + pow(y1 - y, 2);
			ddistance = pow(x2 - x, 2) + pow(y2 - y, 2);

			// Check if the start or end point is inside the planetary system
			if (pdistance < r && ddistance < r)
				continue; // Both points inside, no crossing
			else if (pdistance < r) // Start point inside, one crossing
				prince++;
			else if (ddistance < r) // End point inside, one crossing
				dist++;
		}

		// Output the total count of crossings
		cout << prince + dist << "\n";
	}
}

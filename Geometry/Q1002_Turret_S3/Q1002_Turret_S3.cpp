#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			// 두 원이 일치 (접점이 무한)
			cout << "-1\n";
		}
		else {

			if (r2 > r1) {
				int temp = x1;
				x1 = x2;
				x2 = temp;

				temp = y1;
				y1 = y2;
				y2 = temp;

				temp = r1;
				r1 = r2;
				r2 = temp;
			}

			int dis = (int)(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
			// 두 좌표간의 거리는 해당 값의 제곱근을 구해야 하지만 sqrt를 사용하면 실수형의 오차가 발생할 수 있기 때문에
			// 제곱근을 구하지 않고 그대로 사용한다.

			if (dis < pow(r1 - r2, 2)) {
				// 작은 원이 큰 원 안에 들어있고 접하지 않음.
				cout << "0\n";
			}
			else if (dis == pow(r1 - r2, 2)) {
				// 두 원이 내접함.
				cout << "1\n";
			}
			else if (pow(r2 + r1, 2) > dis) {
				// 두 원이 겹침
				cout << "2\n";
			}
			else if (pow(r2 + r1, 2) < dis) {
				// 두 원이 따로 떨어져있음
				cout << "0\n";
			}
			else {
				// 두 원이 외접함
				cout << "1\n";
			}
		}

	}
}
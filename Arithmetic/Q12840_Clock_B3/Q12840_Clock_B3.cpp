
/*
commented by ChatGPT
This C++ code simulates a digital clock with a 24-hour format and processes a series of time manipulation queries.
It begins by converting the initial time (hours, minutes, and seconds) into seconds.
The program then processes a series of queries, each altering or reporting the current time.
The time is always kept within a 24-hour period (0 to 86399 seconds).
The queries include adding or subtracting seconds from the current time and outputting the current time in the hh:mm:ss format.
Any time alterations that result in the time exceeding 24 hours or becoming negative are adjusted to remain within the 24-hour limit.

이 C++ 코드는 24시간 형식의 디지털 시계를 시뮬레이션하고 시간 조작 쿼리의 일련을 처리합니다.
이 코드는 초기 시간(시, 분, 초)을 초로 변환하는 것으로 시작합니다.
프로그램은 이후에 일련의 쿼리를 처리하는데, 각 쿼리는 현재 시간을 변경하거나 보고합니다.
시간은 항상 24시간 기간(0초에서 86399초) 내에 유지됩니다.
쿼리에는 현재 시간에 초를 더하거나 빼는 것과 현재 시간을 hh:mm:ss 형식으로 출력하는 것이 포함됩니다.
시간 변경으로 인해 시간이 24시간을 초과하거나 음수가 되는 경우는 24시간 한계 내에 유지되도록 조정됩니다.
*/

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int h, m, s;
	int time;
	int q, T, c;

	// 시간을 초 단위로 초기화
	cin >> h >> m >> s;
	time = s + (m * 60) + (h * 3600);
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> T;
		switch (T) {
		case 1: // 초를 더하는 쿼리 처리
			cin >> c;
			time += c;
			time %= 86400; // 하루의 범위를 넘어가지 않도록 조정
			break;
		case 2: // 초를 빼는 쿼리 처리
			cin >> c;
			time -= c;
			while (time < 0)
				time += 86400; // 음수가 되지 않도록 조정
			break;
		case 3: // 현재 시간 표시 쿼리 처리
			cout << (time / 3600) << " " << (time % 3600 / 60) << " " << (time % 3600 % 60) << "\n";
			break;
		}
	}
}
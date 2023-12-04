/*
commented by ChatGPT
This C++ program calculates the number of days between two given dates.
It includes a special case for a 1000-year difference, outputting "gg" in such scenarios.
The program also accounts for leap years when calculating the difference.
이 C++ 프로그램은 주어진 두 날짜 사이의 일수를 계산합니다.
1000년의 차이에 대한 특별한 경우를 포함하여, 그러한 시나리오에서 "gg"를 출력합니다.
프로그램은 일수 차이를 계산할 때 윤년을 고려합니다.
*/

#include <iostream>

using namespace std;

int main()
{
	int y1, m1, d1, y2, m2, d2; // Variables to store the two dates (두 날짜를 저장하기 위한 변수)
	int res = 0; // Result variable to count the number of days (일수를 계산하기 위한 결과 변수)
	int mon[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Array containing the number of days in each month (각 월의 일수가 들어있는 배열)

	// Input for the two dates
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

	// Checking for the special case where the difference in years is 1000 or more
	if (y2 > y1 + 1000 || (y2 == y1 + 1000 && (m2 > m1 || (m2 == m1 && d2 >= d1)))) {
		cout << "gg";
	}
	else {
		// Counting the number of days between the two dates
		while (true) {
			res += mon[m1]; // Add days of the current month (현재 월의 일수를 더함)
			// Checking for leap year in February (2월의 윤년 확인)
			if (m1 == 2 && (y1 % 400 == 0 || (y1 % 100 != 0 && y1 % 4 == 0))) {
				res++; // Add an extra day for leap years (윤년에 추가 일수)
			}
			m1++; // Increment the month (월 증가)
			if (m1 == 13) { // Reset month and increment year at the end of the year (연말에 월 초기화 및 연도 증가)
				m1 = 1;
				y1++;
			}
			if (y1 == y2 && m1 == m2) // Break the loop when reaching the second date (두 번째 날짜에 도달하면 루프 중단)
				break;
		}
		res += d2 - d1; // Add the difference in days of the two dates (두 날짜의 일 차이를 더함)
		cout << "D-" << res; // Output the result (결과 출력)
	}
}

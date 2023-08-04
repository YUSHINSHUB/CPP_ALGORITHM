// Q1931_Meeting_Room_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
Commented by ChatGPT
Summary: This C++ program maximizes the number of non-conflicting reservations by sorting them by end time. In case of a tie, the reservations are sorted by start time.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct reser { // struct to store the start and end time of a reservation.
	int s; // start time
	int e; // end time
};

int main() {
	int n;
	cin >> n;

	vector<reser>ca(n); // vector of reservations

	// reading the start and end times of the reservations
	for (int i = 0; i < n; i++) {
		cin >> ca[i].s >> ca[i].e;
	}

	// sorting the reservations first by end time, then by start time
	sort(ca.begin(), ca.end(), [](reser o1, reser o2) -> bool {
		if (o1.e == o2.e) {
			return o1.s < o2.s;
		}
		else {
			return o1.e < o2.e;
		}
		});

	int cnt = 1; // count of non-conflicting reservations
	int stime = ca[0].e; // end time of the first (earliest ending) reservation

	// Loop to go through the sorted list of reservations.
	for (int i = 1; i < n; i++) {
		// If the start time of the current reservation is after the end time of the last non-conflicting reservation.
		if (ca[i].s >= stime) {
			stime = ca[i].e; // update the end time to the current reservation's end time.
			cnt++; // increment the count of non-conflicting reservations
		}
	}

	cout << cnt; // print the maximum number of non-conflicting reservations.

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

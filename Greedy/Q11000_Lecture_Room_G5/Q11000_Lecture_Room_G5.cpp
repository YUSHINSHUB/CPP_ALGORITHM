/*
	commented by ChatGPT
	Summary:
	This program calculates the minimum number of rooms required for a set of events
	based on their start and end times. Events are sorted by start times, and the
	program determines how many rooms are required without any time conflicts. The
	end time of each event in the rooms is kept in a priority queue.
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// Priority queue (min heap) to store end times of events.
	// This helps in finding the room that gets free the earliest.
	priority_queue<int, vector<int>, greater<int>> pq;

	int n;  // Number of events.
	cin >> n;

	vector<pair<int, int>> list;  // List of events represented as pairs (start time, end time).

	// Reading each event's start and end times and storing them in the list.
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		list.push_back(make_pair(s, t));
	}

	// Sorting the events based on their start time.
	sort(list.begin(), list.end());

	// Adding the end time of the first event to the priority queue.
	pq.push(list[0].second);

	// For each subsequent event in the sorted list.
	for (int i = 1; i < n; i++) {
		// If the event can start after the room that gets free the earliest, we remove that room's end time.
		if (pq.top() <= list[i].first) {
			pq.pop();
		}
		// We add the end time of the current event to the priority queue.
		pq.push(list[i].second);
	}

	// Displaying the total number of rooms required.
	cout << pq.size();

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

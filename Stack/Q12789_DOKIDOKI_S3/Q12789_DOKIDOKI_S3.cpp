// Q12789_DOKIDOKI_S3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	// Read the number of people in the line
	int n;
	cin >> n;
	int idx = 1; // Index variable to track the desired order

	// Create the main queue (line) and an alternate queue (alt) to temporarily
	// store people
	deque<int> line;
	deque<int> alt;

	// Populate the main queue 'line' with the given input
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		line.push_back(temp);
	}

	// Dequeue from the main queue as long as the order is correct
	while (!line.empty() && line.front() == idx) {
		line.pop_front();
		idx++;
	}

	// This string will store our final result - "Nice" if the intended order is
	// achievable, "Sad" otherwise
	string res = "Nice";

	// Try to achieve the correct order by rearranging between the main and
	// alternate queues
	while (idx <= n) {

		if (!line.empty()) {
			if (alt.empty()) {
				// Move people from main queue to alternate queue until we find the person we're
				// looking for
				while (!line.empty() && line.front() != idx) {
					alt.push_front(line.front());
					line.pop_front();
				}
			}
			else {
				// If alt is not empty, move people around while searching for the right order
				while (!line.empty() && line.front() != idx && alt.front() != idx) {
					alt.push_front(line.front());
					line.pop_front();
				}
			}
		}

		// If the desired person is not in the front of either queues, then the order
		// isn't achievable
		if (line.empty() && (alt.empty() || alt.front() != idx)) {
			res = "Sad";
			break;
		}
		else if (!alt.empty() && alt.front() == idx) {
			// If the desired person is in front of the alternate queue, dequeue from there
			alt.pop_front();
			idx++;
		}
		else {
			// If the desired person is in front of the main queue, dequeue from there
			line.pop_front();
			idx++;
		}
	}

	// Write the result to the output
	cout << res;
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

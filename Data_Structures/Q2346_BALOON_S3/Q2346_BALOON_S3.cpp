// Commented by ChatGPT
// Summary: It reads a series of commands that manipulate a deque by shifting the elements either to the left or right. The shifting continues until the deque is empty.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq; // Initialize a deque to store numbers
	int n;
	cin >> n;
	vector<int> cod(n); // Vector to store the commands

	// Populate the deque with initial sequence
	for (int i = 0; i < n; i++) {
		cin >> cod[i];
		dq.push_back(i + 1);
	}

	// Position and index variables for deque manipulation
	int idx = 0;
	int pos = 0;

	// Main loop to process commands and manipulate deque
	while (true) {

		pos = dq.front(); // Remove and get the first element
		dq.pop_front();
		cout << pos << " "; // Output to console
		idx = cod[pos - 1]; // Get the corresponding command

		if (dq.empty())
			break; // If deque is empty, end the process
		else {
			if (idx > 0) { // If command is positive, rotate to right
				for (int i = 0; i < idx - 1; i++) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
			}
			else { // If command is negative, rotate to left
				idx *= (-1);
				for (int i = 0; i < idx; i++) {
					dq.push_front(dq.back());
					dq.pop_back();
				}
			}
		}
	}
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

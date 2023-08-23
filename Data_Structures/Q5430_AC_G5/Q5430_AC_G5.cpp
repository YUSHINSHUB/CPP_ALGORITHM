#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	// Speed up I/O operations
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;
	int n, p; // 'n' is the number of test cases, 'p' is the length of the array for each test
	cin >> n;

	string ac, inp;
	bool err;  // To keep track of errors
	bool rev;  // To keep track of whether the deque should be reversed or not

	for (int i = 0; i < n; i++) {
		rev = false; // Resetting it to false for each test
		cin >> ac >> p;  // Reading command string and number of integers
		cin >> inp;

		// Removing square brackets from the input string
		inp = inp.substr(1, inp.length() - 2);

		// Using stringstream to parse the numbers from the string
		stringstream ss(inp);
		string temp;
		vector<int> nums(p);

		for (int j = 0; j < p; j++) {
			getline(ss, temp, ',');  // Splitting string on comma
			nums[j] = stoi(temp);    // Parsing integer and storing in the vector
		}

		if (inp != "") {
			for (int j = 0; j < p; j++) {
				dq.push_back(nums[j]); // Pushing numbers to the deque
			}
		}

		err = false;

		for (int j = 0; j < ac.length(); j++) {
			if (ac[j] == 'R') {
				// Toggle reverse flag if command is 'R'
				rev = !rev;
			}
			else {
				// If deque is empty on 'D' command, set error flag
				if (dq.empty()) {
					err = true;
					break;
				}
				else if (rev) dq.pop_back(); // Remove from back if reversed
				else dq.pop_front();         // Remove from front otherwise
			}
		}

		// Outputting based on the final state of the deque
		if (err) {
			cout << "error\n";
		}
		else if (!rev) {
			cout << "[";
			if (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
			}
			while (!dq.empty()) {
				cout << "," << dq.front();
				dq.pop_front();
			}
			cout << "]\n";
		}
		else {
			cout << "[";
			if (!dq.empty()) {
				cout << dq.back();
				dq.pop_back();
			}
			while (!dq.empty()) {
				cout << "," << dq.back();
				dq.pop_back();
			}
			cout << "]\n";
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

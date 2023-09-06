// commented by ChatGPT
// Summary: This C++ program calculates the minimum number of operations required to reach a desired channel on a TV remote with potentially broken buttons. 
// The program takes into account direct input, increment, and decrement operations.

#include <iostream>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;  // Read desired channel 'n' and number of broken buttons 'm'

	// Use a map 'hm' to track the status of buttons (0-9). 
	// 1 if it's working, 0 if it's broken.
	map<int, int> hm;

	// Initially set all buttons (0 to 9) as working
	for (int i = 0; i <= 9; i++) {
		hm.insert(pair<int, int>(i, 1));
	}

	// Read the list of broken buttons and update their status in 'hm'
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		hm[t] = 0;  // Mark button as broken
	}

	// Start with the result as the difference between the current channel (100) and the desired channel 'n'
	int res;
	if (n > 100)
		res = n - 100;
	else
		res = 100 - n;

	// Check every possible channel (up to 1000000) to see if it can be input using the working buttons
	string nu = "";
	for (int i = 0; i <= 1000000; i++) {
		string t = to_string(i);  // Convert channel number to string for easier manipulation
		for (int j = 0; j < t.length(); j++) {
			// If the current digit corresponds to a broken button, break out of the loop
			if (hm[stoi(nu + t[j])] != 1) {
				break;
			}
			// If all digits of the channel can be input using working buttons
			if (j == t.length() - 1) {
				// Update 'res' to the minimum between the current result and the sum of the number of button presses and the difference between the desired and current channel
				res = min(res, (int)t.length() + (int)abs(n - i));
			}
		}
	}

	// Print the final result
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

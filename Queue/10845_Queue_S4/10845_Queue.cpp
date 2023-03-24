// 10845_Queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> commands(n * 2);

	queue<int> q;

	for (int i = 0; i < n; i++) {
		cin >> commands[i];
		if (commands[i].compare("push") == 0) {
			n++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (commands[i].compare("push") == 0) {
			q.push(stoi(commands[i + 1]));
			i++;
		}
		else if (commands[i].compare("pop") == 0) {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (commands[i].compare("front") == 0) {

			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
			}

		}
		else if (commands[i].compare("back") == 0) {

			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.back() << endl;
			}

		}
		else if (commands[i].compare("size") == 0) {
			cout << q.size() << endl;
		}
		else if (commands[i].compare("empty") == 0) {
			if (q.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
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

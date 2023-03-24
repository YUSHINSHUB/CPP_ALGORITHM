﻿// 5430_AC.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<int> dq;

	int n, p;
	cin >> n;

	string ac, inp;
	char c;
	bool err = false;
	bool rev = false;

	for (int i = 0; i < n; i++) {
		rev = false;
		cin >> ac >> p;
		cin >> inp;
		inp = inp.substr(1, inp.length() - 2);
		stringstream ss(inp);
		//stringstream은 string을 저장하는 버퍼의 역할을 한다.
		string temp;
		vector<int> nums(p);

		for (int j = 0; j < p; j++) {
			getline(ss, temp, ',');
			//ss를 ,를 delimiter삼아 split 한 후 한조각씩 temp에 넣어준다.
			nums[j] = stoi(temp);
		}



		if (inp != "") {
			for (int j = 0; j < p; j++) {
				dq.push_back(nums[j]);
			}
		}
		err = false;

		for (int j = 0; j < ac.length(); j++) {
			if (ac[j] == 'R') {
				if (rev) rev = false;
				else rev = true;
			}
			else {
				if (dq.empty()) {
					err = true;
					break;
				}
				else if (rev) dq.pop_back();
				else dq.pop_front();
			}
		}

		if (err) cout << "error\n";
		else if (!rev) {
			cout << "[";
			if (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
			}while (!dq.empty()) {
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
			}while (!dq.empty()) {
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

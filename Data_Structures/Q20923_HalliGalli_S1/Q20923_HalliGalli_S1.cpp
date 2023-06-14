// Q20923_HalliGalli_S1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>

using namespace std;

int main()
{

	int n, m;
	cin >> n >> m;
	string res = "";

	deque<int> d; //도도의 덱
	deque<int> s; //수연이의 덱
	deque<int> dg; //도도의 그라운드
	deque<int> sg; //수연이의 그라운드

	int dt, st;
	for (int i = 0; i < n; i++) {
		//카드더미를 앞면이 위로가도록 내려놓았을 때 위쪽을 Front, 아래쪽을 Back으로 본다.
		cin >> dt >> st;
		d.push_back(dt);
		s.push_back(st);
	}

	for (int i = 0; i < m; i++) {

		if (i % 2 == 0) {
			dg.push_front(d.back());
			d.pop_back();

			if (d.empty()) {
				res = "su";
				break;
			}

			if (!sg.empty()) {
				if (dg.front() + sg.front() == 5) {
					while (!dg.empty()) {
						s.push_front(dg.back());
						dg.pop_back();
					}
					while (!sg.empty()) {
						s.push_front(sg.back());
						sg.pop_back();
					}
				}
			}
			if (!dg.empty()) {
				if (dg.front() == 5) {
					while (!sg.empty()) {
						d.push_front(sg.back());
						sg.pop_back();
					}
					while (!dg.empty()) {
						d.push_front(dg.back());
						dg.pop_back();
					}
				}
			}
		}
		else {
			sg.push_front(s.back());
			s.pop_back();
			if (d.empty()) {
				res = "su";
				break;
			}
			if (!dg.empty()) {
				if (dg.front() + sg.front() == 5) {
					while (!dg.empty()) {
						s.push_front(dg.back());
						dg.pop_back();
					}
					while (!sg.empty()) {
						s.push_front(sg.back());
						sg.pop_back();
					}
				}
			}
			if (!sg.empty()) {
				if (sg.front() == 5) {
					while (!sg.empty()) {
						d.push_front(sg.back());
						sg.pop_back();
					}
					while (!dg.empty()) {
						d.push_front(dg.back());
						dg.pop_back();
					}
				}
			}
		}

		if (d.empty() && s.empty()) {
			res = "dosu";
			break;
		}
		else if (d.empty()) {
			res = "su";
			break;
		}
		else if (s.empty()) {
			res = "do";
			break;
		}

	}

	if (res == "") {
		//게임 M번을 중도 종료 없이 모두 진행하였을떄의 승자를 가린다.
		if (d.size() > s.size())
			res = "do";
		else if (d.size() < s.size())
			res = "su";
		else
			res = "dosu";
	}

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

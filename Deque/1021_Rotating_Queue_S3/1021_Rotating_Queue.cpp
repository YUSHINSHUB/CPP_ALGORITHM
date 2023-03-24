// 1021_Rotating_Queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {

	deque<int> d;
	queue<int> q;

	int n, m;
	cin >> n >> m;

	map<int, int> hm;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
		hm.insert(pair<int, int>(i, i));
	}

	int res = 0;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (hm[temp] <= (d.size() - hm[temp] + 1)) {
			while (d.front() != temp) {
				int t = d.front();
				d.pop_front();
				d.push_back(t);
				res++;
			}
			d.pop_front();
		}
		else {
			while (d.front() != temp) {
				int t = d.back();
				d.pop_back();
				d.push_front(t);
				res++;
			}
			d.pop_front();
		}
		for (int i = 1; i <= d.size(); i++) {
			int t = d.front();
			d.pop_front();
			d.push_back(t);
			hm[t] = i;
			//C++에서는 배열의 값을 바꾸듯이 맵의 값도 간편하게 대입연산자로 수정할 수 있다.
		}

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

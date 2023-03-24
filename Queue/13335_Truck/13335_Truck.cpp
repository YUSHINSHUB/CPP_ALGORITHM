// 13335_Truck.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

int main() {

	int n, w, l;
	cin >> n >> w >> l;
	int time = 0;
	queue<int> q; //지나가야 할 트럭
	queue<int> brg; //다리위의 상황

	int temp = 0;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		q.push(temp);
	}
	for (int i = 0; i < w; i++) brg.push(0); //트럭이 존재하는 부분은 트럭의 무게로, 그렇지 않은 부분은 0으로 넣는다.
												 //처음에는 다리가 비어있기 떄문에 모두 0이다.

	int wei = 0;

	while (!brg.empty()) {
		time++;
		wei -= brg.front();
		brg.pop();
		if (!q.empty()) {
			if (wei + q.front() <= l) {
				wei += q.front();
				brg.push(q.front());
				q.pop();
			}
			else {
				brg.push(0);
			}
			//시간이 지날때마다 최대하중을 초과하지 않는다면 새로운 트럭을 다리에 올리고
		}	// 그렇지 않다면 빈공간이 되기 떄문에 0을 올린다.
	}

	cout << time;
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

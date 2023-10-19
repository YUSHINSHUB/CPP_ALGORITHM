// Q3190_SNAKE_G4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int b[101][101];
	int cy = 1;
	int cx = 1;
	int vec = 1;
	int res = 0;
	bool pass = true;
	queue<int> yq;
	queue<int> xq;

	yq.push(1);
	xq.push(1);

	for (int i = 1; i <= n; i++)
		fill(b[i], b[i] + n, 0);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		b[y][x] = 1;
	}

	b[1][1] = 2;

	int l;
	cin >> l;

	for (int i = 0; i < l; i++) {
		int x;
		string c;
		cin >> x >> c;
		switch (vec) {
		case 1:
			for (int j = res; j < x; j++) {
				cx++;
				res++;
				if (cx > n) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 2:
			for (int j = res; j < x; j++) {
				cy++;
				res++;
				if (cy > n) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 3:
			for (int j = res; j < x; j++) {
				cx--;
				res++;
				if (cx < 1) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 4:
			for (int j = res; j < x; j++) {
				cy--;
				res++;
				if (cy < 1) {
					pass = false;
					break;
				}
				else if (b[cy][cx] == 2) {
					pass = false;
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		}
		if (!pass)
			break;

		if (c == "D") {
			vec++;
			if (vec == 5)
				vec = 1;
		}
		else {
			vec--;
			if (vec == 0)
				vec = 4;
		}

	}

	if (pass) {
		switch (vec) {
		case 1:
			while (true) {
				cx++;
				res++;
				if (cx > n) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 2:
			while (true) {
				cy++;
				res++;
				if (cy > n) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 3:
			while (true) {
				cx--;
				res++;
				if (cx < 1) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
		case 4:
			while (true) {
				cy--;
				res++;
				if (cy < 1) {
					break;
				}
				else if (b[cy][cx] == 2) {
					break;
				}

				if (b[cy][cx] == 1) {
					b[cy][cx] = 2;
				}
				else {
					b[cy][cx] = 2;
					b[yq.front()][xq.front()] = 0;
					yq.pop();
					xq.pop();
				}
				yq.push(cy);
				xq.push(cx);
			}
			break;
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

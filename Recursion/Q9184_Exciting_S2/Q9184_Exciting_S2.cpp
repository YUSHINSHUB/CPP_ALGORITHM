// Q9184_Exciting_S2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

static int mem[21][21][21];

static int w(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20) {
		if (mem[20][20][20] < 0)
			mem[20][20][20] = w(20, 20, 20);
		return mem[20][20][20];
	}
	else if (a < b && b < c) {
		int res = 0;
		if (mem[a][b][c - 1] < 0)
			mem[a][b][c - 1] = w(a, b, c - 1);
		res = mem[a][b][c - 1];
		if (mem[a][b - 1][c - 1] < 0)
			mem[a][b - 1][c - 1] = w(a, b - 1, c - 1);
		res += mem[a][b - 1][c - 1];
		if (mem[a][b - 1][c] < 0)
			mem[a][b - 1][c] = w(a, b - 1, c);
		res -= mem[a][b - 1][c];
		return res;
	}
	else {
		int res = 0;
		if (mem[a - 1][b][c] < 0)
			mem[a - 1][b][c] = w(a - 1, b, c);
		res = mem[a - 1][b][c];
		if (mem[a - 1][b - 1][c] < 0)
			mem[a - 1][b - 1][c] = w(a - 1, b - 1, c);
		res += mem[a - 1][b - 1][c];
		if (mem[a - 1][b][c - 1] < 0)
			mem[a - 1][b][c - 1] = w(a - 1, b, c - 1);
		res += mem[a - 1][b][c - 1];
		if (mem[a - 1][b - 1][c - 1] < 0)
			mem[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
		res -= mem[a - 1][b - 1][c - 1];
		return res;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			fill(mem[i][j], mem[i][j] + 21, -1);
		}
	}

	while (true) {

		cin >> a >> b >> c;

		if (a == b && b == c && a == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
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

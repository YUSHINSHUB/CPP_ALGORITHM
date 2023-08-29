/*
commented by ChatGPT
Summary: This program performs union-find operations on disjoint sets using path compression.
It can either unite two sets or check if two elements belong to the same set.
*/


#include <iostream>
#include <map>
using namespace std;

int parent[1000001];

// Recursive function to find the representative of a set.
static int findparent(int n) {
	// If n is not its own parent, update its parent to the representative of the
	// set.
	if (parent[n] != n) {
		parent[n] = findparent(parent[n]);
	}
	return parent[n];
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	// Initially, every element is its own parent.
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	// Processing each operation.
	for (int i = 0; i < m; i++) {
		int comm; // Command type: 0 (union) or 1 (find)
		int a; // First element
		int b; // Second element
		cin >> comm >> a >> b;

		a = findparent(a);
		b = findparent(b);

		if (comm == 0) {
			// If command type is 0, attempt to unite the sets containing 'a' and 'b'.
			if (a != b ) {
				parent[b] = a;
			}
		}
		else {
			// If command type is 1, check if 'a' and 'b' belong to the same set.
			if (a == b)
				cout << "YES\n";
			else
				cout << "NO\n";
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

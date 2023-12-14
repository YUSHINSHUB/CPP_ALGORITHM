#include <iostream>
using namespace std;

int visited[101];
int cnt;
int conn[101][101];

void dfs(int s, int c) {

	visited[s] = 1;
	cnt++;

	for (int i = 0; i < c; i++) {
		if (conn[s][i] == 1 && visited[i] != 1) dfs(i, c);
		//연결되어 있는 s번 노드에 연결되어 있는 노드가 아직 탐색되지 않았을 경우 dfs를 재귀호출하여 탐색하고 cnt (결과값)을 증가시킨다.
	}


}

int main()
{
	cnt = 0;

	int c, n;
	cin >> c >> n;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			conn[i][j] = 0;
		}
	}

	int a, b;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		conn[a - 1][b - 1] = 1;
		conn[b - 1][a - 1] = 1;
	}

	dfs(0, c);

	cout << cnt - 1;
}
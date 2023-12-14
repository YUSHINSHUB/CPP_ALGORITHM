#include <iostream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

static bool pos[50][50];
static bool visited[50][50];
static int xpos[] = { 1, -1, 0, 0 };
static int ypos[] = { 0, 0, 1, -1 };
static int m, n;

static void dfs(int y, int x) {
	int xp, yp;
	for (int i = 0; i < 4; i++) {
		xp = x + xpos[i];
		yp = y + ypos[i];
		if (xp >= 0 && xp < m && yp >= 0 && yp < n) {
			if (pos[yp][xp] && !visited[yp][xp]) {
				visited[yp][xp] = true;
				dfs(yp, xp);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;
	int k;
	int x, y, res;

	for (int i = 0; i < t; i++) {
		res = 0;
		cin >> m >> n >> k;
		memset(pos, false, sizeof(pos));
		memset(visited, false, sizeof(visited));

		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			pos[y][x] = true;
		}

		for (int j = 0; j < n; j++) {
			for (int l = 0; l < m; l++) {
				if (pos[j][l] && !visited[j][l]) {
					visited[j][l] = true;
					dfs(j, l);
					res++;
				}
			}
		}

		cout << res << "\n";
	}
}
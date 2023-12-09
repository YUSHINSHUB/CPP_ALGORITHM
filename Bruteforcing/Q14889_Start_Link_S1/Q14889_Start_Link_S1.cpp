#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

static int n;
static int res = INT_MAX;
static int par[20][20];
static bool visited[20];

static void bt(int idx, int cnt) {
	if (cnt == n / 2) {
		int s = 0, l = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i] && visited[j])
					s += par[j][i];
				else if (!visited[i] && !visited[j])
					l += par[j][i];
			}
		}
		res = min(res, abs(s - l));
	}
	else {
		for (int i = idx; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				bt(i + 1, cnt + 1);
				visited[i] = false;
			}
		}
	}
}


int main()
{

	cin >> n;
	fill(visited, visited + n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> par[i][j];
	}

	bt(0, 0);
	cout << res;

}
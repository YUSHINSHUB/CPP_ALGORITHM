#include <iostream>

using namespace std;

static int n, s;
static int len = 1;
static int res = 0;
static int seq[20];
static bool visited[20];

static void bt(int idx, int cnt, int sum) {
	if (cnt == len) {
		if (sum == s)
			res++;
	}
	else {
		for (int i = idx; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				bt(i + 1, cnt + 1, sum + seq[i]);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> seq[i];

	while (len <= n) {
		bt(0, 0, 0);
		len++;
	}

	cout << res;
}
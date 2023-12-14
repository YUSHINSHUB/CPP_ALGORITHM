﻿#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));

	check[start] = true;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		printf("%d ", v);

		for (int i = 0; i < a[v].size(); i++) {
			int next = a[v][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {

	int n, m, start;

	scanf("%d %d %d ", &n, &m, &start);

	for (int i = 0; i < m; i++) {
		int u, v;

		scanf("%d %d ", &u, &v);

		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(start);
	puts("");
	bfs(start);
	puts("");

	return 0;
}
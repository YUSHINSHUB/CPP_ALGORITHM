#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int n, k;
	cin >> n >> k;

	int cnt = 1;

	for (int i = 1; i <= n; i++) q.push(i);

	cout << "<";
	while (!q.empty()) {
		if (cnt == k) {
			cnt = 1;
			cout << q.front();
			q.pop();
			if (!q.empty()) cout << ", ";
		}
		else {
			q.push(q.front());
			q.pop();
			cnt++;
		}
	}
	cout << ">";

}
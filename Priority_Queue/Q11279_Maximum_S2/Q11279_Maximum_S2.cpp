#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int in = 0;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in != 0) {
			pq.push(in);
		}
		else if (pq.empty()) {
			cout << "0\n";
		}
		else {
			cout << pq.top() << "\n";
			pq.pop();
		}
	}

}
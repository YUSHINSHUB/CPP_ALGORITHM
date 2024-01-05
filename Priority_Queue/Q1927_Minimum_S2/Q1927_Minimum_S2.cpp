#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int> > pq;

	int n;
	cin >> n;
	int temp = 0;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 0 && !pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else if (temp == 0 && pq.empty()) {
			cout << "0\n";
		}
		else {
			pq.push(temp);
		}

	}



}
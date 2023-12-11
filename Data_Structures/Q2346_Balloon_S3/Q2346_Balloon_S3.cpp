#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	int n;
	cin >> n;
	vector<int> cod(n);

	for (int i = 0; i < n; i++) {
		cin >> cod[i];
		dq.push_back(i + 1);
	}

	int idx = 0;
	int pos = 0;

	while (true) {

		pos = dq.front();
		dq.pop_front();
		cout << pos << " ";
		idx = cod[pos - 1];

		if (dq.empty())
			break;
		else {
			if (idx > 0) {
				for (int i = 0; i < idx - 1; i++) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
			}
			else {
				idx *= (-1);
				for (int i = 0; i < idx; i++) {
					dq.push_front(dq.back());
					dq.pop_back();
				}
			}
		}
	}
}
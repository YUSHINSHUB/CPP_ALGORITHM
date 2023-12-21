#include <iostream>
#include <queue>
using namespace std;

int main()
{
	long a, b;
	cin >> a >> b;
	int cnt = 1;
	bool pass = false;

	queue<long long> stk;
	stk.push(a);

	while (true) {

		if (stk.empty())
			break;

		int s = stk.size();
		for (int i = 0; i < s; i++) {
			long temp = stk.front();
			stk.pop();
			if (temp == b) {
				pass = true;
				break;
			}
			if (temp * 2 <= b) {
				stk.push(temp * 2);
			}
			if ((temp * 10) + 1 <= b) {
				stk.push((temp * 10) + 1);
			}
		}
		if (pass)
			break;
		cnt++;
	}

	if (pass)
		cout << cnt;
	else
		cout << "-1";

}
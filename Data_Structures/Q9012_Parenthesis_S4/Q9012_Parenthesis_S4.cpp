#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (; 0 < n; n--) {
		string str;
		cin >> str;

		queue<string> q;
		bool bl = true;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				q.push("(");
			}
			else {
				if (q.empty()) {
					bl = false;
					break;
				}
				else {
					q.pop();
				}
			}
		}
		if (!q.empty()) {
			bl = false;
		}
		if (bl) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}
}
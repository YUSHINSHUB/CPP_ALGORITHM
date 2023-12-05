#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int res = 0;
	int cnt = 0;
	string str = "";

	for (int i = 0; i <= n; i++) {
		str = to_string(i);
		cnt = i;
		for (int i = 0; i < str.length(); i++) {
			cnt += str[i] - 48;
		}
		if (cnt == n) {
			res = i;
			break;
		}
	}

	cout << res;

}
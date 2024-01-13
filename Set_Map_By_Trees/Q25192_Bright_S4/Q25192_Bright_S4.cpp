#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	set<string> hs;
	string in;
	int res = 0;

	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in != "ENTER") {
			hs.insert(in);
		}
		else {
			res += hs.size();
			hs.clear();
		}
	}

	res += hs.size();
	cout << res;
}
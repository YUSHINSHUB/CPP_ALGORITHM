#include <iostream>
#include <map>
#include <climits>

using namespace std;

int main()
{

	int n;
	cin >> n;

	map<long long, int> hm;

	int hig = 0;
	long long res = LLONG_MAX;

	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		if (hm.count(temp) == 0) {
			hm.insert(pair<long long, int>(temp, 1));
		}
		else {
			hm[temp]++;
		}

		if (hm[temp] > hig) {
			hig = hm[temp];
			res = temp;
		}
		else if (hm[temp] == hig && res > temp) {
			res = temp;
		}
	}

	cout << res;

}
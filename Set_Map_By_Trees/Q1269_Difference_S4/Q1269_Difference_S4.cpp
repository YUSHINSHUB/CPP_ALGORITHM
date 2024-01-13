#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int res = 0;
	map<int, int> hm;
	vector<int> arr(n + m);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (hm.find(arr[i]) != hm.end()) hm[arr[i]]++;
		else hm.insert(pair<int, int>(arr[i], 1));
	}

	for (int i = 0; i < m; i++) {
		cin >> arr[n + i];
		if (hm.find(arr[n + i]) != hm.end()) hm[arr[n + i]]++;
		else hm.insert(pair<int, int>(arr[n + i], 1));
	}

	for (int i = 0; i < n + m; i++) {
		if (hm[arr[i]] == 1)
			res++;
	}

	cout << res;
}
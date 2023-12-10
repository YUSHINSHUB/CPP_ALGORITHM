#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int idx = 0;
	int sum = 0;
	int res = 0;

	for (int i = 0; i < n; i++) {
		sum += num[i];
		if (sum == m)
			res++;
		else if (sum > m) {
			while (sum > m) {
				sum -= num[idx];
				idx++;
			}
			if (sum == m)
				res++;
		}
	}

	cout << res;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	int n;
	cin >> n;

	if (n == 0) cout << 0;
	else {
		vector<int> diff(n);
		int start, end;
		int del = ((n * 15) + 50) / 100;
		start = del;
		end = n - del;
		int sum = 0;

		for (int i = 0; i < n; i++)
			cin >> diff[i];

		sort(diff.begin(), diff.end());

		for (int i = start; i < end; i++)
			sum += diff[i];

		n -= del * 2;
		sum *= 100;

		cout << ((sum / n) + 50) / 100 << "";
	}
}
#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int hi = INT_MIN;
	int lo = INT_MAX;
	int n;
	int in;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> in;
		hi = max(hi, in);
		lo = min(lo, in);
	}

	cout << lo << " " << hi;
}
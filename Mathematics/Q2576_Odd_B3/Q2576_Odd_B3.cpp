#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int sum = 0;
	int min = INT_MAX;

	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 == 1) {
			if (min > n) min = n;
			sum += n;
		}
	}

	if (sum == 0) cout << "-1";
	else cout << sum << "\n" << min;

}
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{

	int n;
	cin >> n;

	vector<long long> prc(n);
	vector<long long> dis(n - 1);

	int cheap = INT_MAX;

	for (int i = 0; i < n - 1; i++) {
		cin >> dis[i];
	}

	long res = 0;

	for (int i = 0; i < n - 1; i++) {
		cin >> prc[i];
		if (prc[i] > cheap)
			prc[i] = cheap;
		else
			cheap = prc[i];

		res += dis[i] * prc[i];
	}

	cout << res;


}

#include <iostream>
#include <math.h>
#include <climits>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int sf = INT_MAX;
	int of = INT_MAX;
	int s, o;

	for (int i = 0; i < m; i++) {
		cin >> s >> o;
		sf = min(s, sf);
		of = min(o, of);
	}
	int res;

	if (sf < of) {
		res = (n / 6) * sf;
		if (n % 6 != 0) {
			res += sf;
		}
	}
	else if (sf > of * 6) {
		res = of * n;
	}
	else {
		res = (n / 6) * sf;
		res += min(sf, (n % 6) * of);
	}

	cout << res;

}

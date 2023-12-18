#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct reser {
	int s;
	int e;
};

int main() {



	int n;

	cin >> n;

	vector<reser>ca(n);

	for (int i = 0; i < n; i++) {
		cin >> ca[i].s >> ca[i].e;
	}

	sort(ca.begin(), ca.end(), [](reser o1, reser o2) -> bool {

		if (o1.e == o2.e) {
			return o1.s < o2.s;
		}
		else {
			return o1.e < o2.e;
		}

		});

	int cnt = 1;
	int stime = ca[0].e;

	for (int i = 1; i < n; i++) {
		if (ca[i].s >= stime) {
			stime = ca[i].e;
			cnt++;
		}
	}

	cout << cnt;

}
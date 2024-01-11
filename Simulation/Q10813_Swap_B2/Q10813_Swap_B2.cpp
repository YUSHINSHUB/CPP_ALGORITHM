#include <iostream>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, m;
	cin >> n >> m;

	vector<int> ball(n);

	for (int i = 0; i < n; i++) {
		ball[i] = i + 1;
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		int temp = ball[a - 1];
		ball[a - 1] = ball[b - 1];
		ball[b - 1] = temp;
	}

	for (int i = 0; i < n; i++) cout << ball[i] << " ";

}
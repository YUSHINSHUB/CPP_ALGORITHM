#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cards[20000001] = { 0, };

	int n;
	cin >> n;

	int temp = 0;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		cards[temp + 10000000]++;
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		cout << cards[temp + 10000000] << " ";
	}

}
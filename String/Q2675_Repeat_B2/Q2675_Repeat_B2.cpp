#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> it(n);
	vector<string> st(n);

	for (int i = 0; i < n; i++) {
		cin >> it[i] >> st[i];
	}

	for (int i = 0; i < n; i++) {
		for (int z = 0; z < st[i].length(); z++) {
			for (int x = 0; x < it[i]; x++) {
				cout << st[i][z];
			}
		}
		cout << endl;
	}

}
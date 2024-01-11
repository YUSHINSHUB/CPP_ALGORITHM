#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
using namespace std;


int main() {

	int n, v;
	cin >> n;
	int t;
	map<int, int> map;

	for (int i = 0; i < n; i++) {
		cin >> t;
		map[t]++;
	}

	cin >> v;
	cout << map[v];

}
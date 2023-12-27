#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	int cnt = 0;

	map<int, bool> hmap;

	int temp;

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		hmap.insert(pair<int, bool>(temp, true));
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		if (hmap[temp] == true) printf("1\n");
		else printf("0\n");
	}
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct pos {
	int x;
	int y;
};

int main() {

	int t;
	cin >> t;

	vector<pos> ca(t);

	for (int i = 0; i < t; i++) {
		cin >> ca[i].x >> ca[i].y;
	}

	stable_sort(ca.begin(), ca.end(), [](pos o1, pos o2) -> bool {
		if (o1.y == o2.y) {
			return o1.x < o2.x;
		}
		else {
			return o1.y < o2.y;
		}
		});

	for (int i = 0; i < t; i++) {
		printf("%d %d\n", ca[i].x, ca[i].y);
	}

}
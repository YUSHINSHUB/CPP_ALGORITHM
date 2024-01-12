#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class pos {
public:
	int x;
	int y;

	void setpos(int x, int y) {
		this->x = x;
		this->y = y;
	}

};

int main() {

	pos p[3];

	int x, y;

	for (int i = 0; i < 3; i++) {
		int tempx, tempy;
		cin >> tempx >> tempy;
		p[i].setpos(tempx, tempy);
	}

	if (p[1].x == p[0].x) {
		x = p[2].x;
	}
	else if (p[2].x == p[0].x) {
		x = p[1].x;
	}
	else {
		x = p[0].x;
	}

	if (p[1].y == p[0].y) {
		y = p[2].y;
	}
	else if (p[2].y == p[0].y) {
		y = p[1].y;
	}
	else {
		y = p[0].y;
	}

	cout << x << " " << y;

}
#include <iostream>

using namespace std;

int main() {

	int dice[3];

	int dmax = 0;

	int prize = 0;

	cin >> dice[0] >> dice[1] >> dice[2];

	if (dice[0] == dice[1] && dice[0] == dice[2]) {
		prize = 10000 + (dice[0] * 1000);
	}
	else if (dice[0] == dice[1] || dice[0] == dice[2]) {
		prize = 1000 + (dice[0] * 100);
	}
	else if (dice[1] == dice[2]) {
		prize = 1000 + (dice[1] * 100);
	}
	else {
		for (int i = 0; i < 3; i++) {
			dmax = max(dice[i], dmax);
		}
		prize = 100 * dmax;
	}

	cout << prize;

}
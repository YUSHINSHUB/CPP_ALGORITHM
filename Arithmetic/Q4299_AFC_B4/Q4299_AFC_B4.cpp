#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

bool wheint(double win, double los) {
	if (win != (int)win || win < 0) {
		return false;
	}
	else if (los != (int)los || los < 0) {
		return false;
	}

	return true;
}

int main() {

	double sum, gap;
	cin >> sum >> gap;

	double win = (sum / 2) + (gap / 2);
	double los = (sum / 2) - (gap / 2);

	if (wheint(win, los) == true) {
		cout << (int)win << " " << (int)los;
	}
	else {
		cout << -1;
	}

}
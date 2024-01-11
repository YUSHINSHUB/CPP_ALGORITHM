#include <iostream>

using namespace std;

int main() {

	int hours;
	int minutes;
	int spent;

	cin >> hours >> minutes;
	cin >> spent;

	minutes += spent;

	while (minutes >= 60) {
		minutes -= 60;
		hours++;
	}

	while (hours >= 24) {
		hours -= 24;
	}

	cout << hours << " " << minutes;


}
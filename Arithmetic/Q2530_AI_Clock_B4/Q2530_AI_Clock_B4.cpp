#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {


	int hours, minutes, seconds;
	int spent;

	cin >> hours >> minutes >> seconds;
	cin >> spent;

	seconds += spent;

	while (seconds >= 60) {
		seconds -= 60;
		minutes++;
	}

	while (minutes >= 60) {
		minutes -= 60;
		hours++;
	}

	while (hours >= 24) {
		hours -= 24;
	}

	cout << hours << " " << minutes << " " << seconds;


}
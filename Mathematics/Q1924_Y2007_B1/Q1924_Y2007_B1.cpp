#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int m, d;
	cin >> m >> d;

	switch (m) {
	case 1:
		break;
	case 2:
		d += 31;
		break;
	case 3:
		d += 59;
		break;
	case 4:
		d += 90;
		break;
	case 5:
		d += 120;
		break;
	case 6:
		d += 151;
		break;
	case 7:
		d += 181;
		break;
	case 8:
		d += 212;
		break;
	case 9:
		d += 243;
		break;
	case 10:
		d += 273;
		break;
	case 11:
		d += 304;
		break;
	case 12:
		d += 334;
		break;
	}

	int wd = d % 7;

	switch (wd) {
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
		break;
	}


}
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int r;
	cin >> r;

	double uc = (double)r * (double)r * M_PI;

	int tx = r * r * 2;

	cout.precision(6);

	cout << fixed << uc << endl << tx;


}
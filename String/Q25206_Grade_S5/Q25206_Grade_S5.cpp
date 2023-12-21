#include <iostream>
using namespace std;

int main()
{
	double sum = 0;
	double per = 0;
	double temp;
	string grd;
	string s;
	int idx = 20;

	for (int i = 0; i < 20; i++) {

		cin >> s >> temp >> grd;

		if (grd != "P")
			per += temp;

		if (grd == "A0") {
			temp /= 4.5;
			temp *= 4;
		}
		else if (grd == "B+") {
			temp /= 4.5;
			temp *= 3.5;
		}
		else if (grd == "B0") {
			temp /= 4.5;
			temp *= 3;
		}
		else if (grd == "C+") {
			temp /= 4.5;
			temp *= 2.5;
		}
		else if (grd == "C0") {
			temp /= 4.5;
			temp *= 2;
		}
		else if (grd == "D+") {
			temp /= 4.5;
			temp *= 1.5;
		}
		else if (grd == "D0") {
			temp /= 4.5;
			temp *= 1;
		}
		else if (grd == "F" || grd == "P") {
			temp = 0;
		}

		sum += temp;

	}

	per = 4.5 / per;
	per *= sum;
	cout << per;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {

	int    angle[3];
	string triangle;

	cin >> angle[0] >> angle[1] >> angle[2];

	if (angle[0] + angle[1] + angle[2] == 180) {
		if (angle[0] == 60 && angle[1] == 60 && angle[2] == 60) {
			triangle = "Equilateral";
		}
		else if (angle[0] == angle[1] || angle[0] == angle[2] || angle[1] == angle[2]) {
			triangle = "Isosceles";
		}
		else {
			triangle = "Scalene";
		}
	}
	else {
		triangle = "Error";
	}

	cout << triangle;



}
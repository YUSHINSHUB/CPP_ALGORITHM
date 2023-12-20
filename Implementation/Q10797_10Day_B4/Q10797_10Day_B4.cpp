#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main() {


	char day1[2];
	char* day2 = &day1[0];
	char cnums1[1001];
	char* cnums2;

	cin.getline(day1, 2);

	int viol = 0;

	cin.getline(cnums1, 1000);

	cnums2 = strtok(cnums1, " ");

	while (cnums2 != NULL) {
		if (cnums2[0] == day2[0]) {
			viol++;
		}
		cnums2 = strtok(NULL, " ");
	}



	cout << viol;

}
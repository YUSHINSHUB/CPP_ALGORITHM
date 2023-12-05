/*
Commented by ChatGPT
Summary: This C++ program takes three integers as input and prints the second largest number.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// Initialize an array to hold the three numbers
	int n[3];

	// Read the numbers
	cin >> n[0] >> n[1] >> n[2];

	// Use the 'sort' function from the standard library to sort the numbers
	sort(n, n + 3);

	// Print the second number (which is now the second largest due to sorting)
	cout << n[1];

}

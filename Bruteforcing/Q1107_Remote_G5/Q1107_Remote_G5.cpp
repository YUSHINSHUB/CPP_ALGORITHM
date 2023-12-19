// commented by ChatGPT
// Summary: This C++ program calculates the minimum number of operations required to reach a desired channel on a TV remote with potentially broken buttons. 
// The program takes into account direct input, increment, and decrement operations.

#include <iostream>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;  // Read desired channel 'n' and number of broken buttons 'm'

	// Use a map 'hm' to track the status of buttons (0-9). 
	// 1 if it's working, 0 if it's broken.
	map<int, int> hm;

	// Initially set all buttons (0 to 9) as working
	for (int i = 0; i <= 9; i++) {
		hm.insert(pair<int, int>(i, 1));
	}

	// Read the list of broken buttons and update their status in 'hm'
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		hm[t] = 0;  // Mark button as broken
	}

	// Start with the result as the difference between the current channel (100) and the desired channel 'n'
	int res;
	if (n > 100)
		res = n - 100;
	else
		res = 100 - n;

	// Check every possible channel (up to 1000000) to see if it can be input using the working buttons
	string nu = "";
	for (int i = 0; i <= 1000000; i++) {
		string t = to_string(i);  // Convert channel number to string for easier manipulation
		for (int j = 0; j < t.length(); j++) {
			// If the current digit corresponds to a broken button, break out of the loop
			if (hm[stoi(nu + t[j])] != 1) {
				break;
			}
			// If all digits of the channel can be input using working buttons
			if (j == t.length() - 1) {
				// Update 'res' to the minimum between the current result and the sum of the number of button presses and the difference between the desired and current channel
				res = min(res, (int)t.length() + (int)abs(n - i));
			}
		}
	}

	// Print the final result
	cout << res;
}
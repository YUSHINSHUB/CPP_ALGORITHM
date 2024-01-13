//Commented by ChatGPT
//Summary: This program reads an input of key-value pairs, stores them in a HashMap, and then looks up and outputs the values for a specified set of keys.

#include <iostream>
#include <map>
using namespace std;

int main()
{s
	int n; // Number of key-value pairs
	int m; // Number of keys to look up

	// Read the input for the number of key-value pairs (n) and the number of keys
		// to look up (m)
	cin >> n >> m;

	// Initialize a HashMap to store the key-value pairs
	map<string, string> hm;

	// Read the key-value pairs and store them in the HashMap
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		hm.insert(pair<string, string>(a, b)); // Store the key-value pair in the HashMap
	}

	// Look up the values for the specified keys and write them to the output
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << hm[a] << "\n"; // Look up the value for the key and write it to the output
	}
}
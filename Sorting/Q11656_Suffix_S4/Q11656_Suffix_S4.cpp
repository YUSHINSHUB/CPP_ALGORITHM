
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string in;
	cin >> in;

	vector<string> sr(in.length());

	for (int i = 0; i < in.length(); i++) {
		sr[i] = "";
		for (int z = i; z < in.length(); z++) {
			sr[i] += in[z];
		}
	}
	stable_sort(sr.begin(), sr.end(), [](string o1, string o2) -> bool {
		return o1 < o2;
		});

	for (int i = 0; i < sr.size(); i++) {
		cout << sr[i] << "\n";
	}

}
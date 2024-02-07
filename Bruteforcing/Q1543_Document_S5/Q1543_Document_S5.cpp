#include <iostream>
#include <string>
using namespace std;

int main()
{
	string d1, d2;
	getline(cin, d1);
	getline(cin, d2);
	int len = d2.length();
	int gap = d1.length() - d2.length();
	char f = d2[0];
	int res = 0;

	for (int i = 0; i <= gap; i++) {
		if (d1[i] == f) {
			if (d1.substr(i, len) == d2) {
				res++;
				i += len - 1;
			}
		}
	}

	cout << res;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "";
	string change = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string sb = "";

	while (getline(cin, s)) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				sb += ' ';
			}
			else {
				for (int j = 1; j < change.length(); j++) {
					if (s[i] == change[j]) {
						sb += change[j - 1];
						break;
					}
				}
			}
		}
		sb += '\n';
	}

	cout << sb;
}

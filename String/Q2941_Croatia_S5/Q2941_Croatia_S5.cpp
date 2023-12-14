#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {

	string in;
	cin >> in;
	int cnt = 0;

	for (int i = 0; i < in.length(); i++) {
		if (in[i] == 'c' && i < in.length() - 1) {
			if (in[i + 1] == '=') {
				i++;
				cnt++;
			}
			else if (in[i] == '-') {
				i++;
				cnt++;
			}
			else cnt++;
		}
		else if (in[i] == 'd' && i < in.length() - 2) {
			if (in[i + 1] == 'z' && in[i + 2] == '=') {
				i += 2;
				cnt++;
			}
			else if (in[i + 1] == '-') {
				i++;
				cnt++;
			}
			else cnt++;
		}
		else if (in[i] == 'd' && i < in.length() - 1) {
			if (in[i + 1] == '-') {
				i++;
				cnt++;
			}
			else cnt++;
		}
		else if (in[i] == 'l' && i < in.length() - 1) {
			if (in[i + 1] == 'j') {
				i++;
				cnt++;
			}
			else cnt++;
		}
		else if (in[i] == 'n' && i < in.length() - 1) {
			if (in[i + 1] == 'j') {
				i++;
				cnt++;
			}
			else cnt++;
		}
		else if (in[i] == 's' && i < in.length() - 1) {
			if (in[i + 1] == '=') {
				i++;
				cnt++;
			}
			else cnt++;
		}
		else if (in[i] == 'z' && i < in.length() - 1) {
			if (in[i + 1] == '=') {
				i++;
				cnt++;
			}
			else cnt++;
		}
		else if (in[i] >= 97 && in[i] <= 122) cnt++;
	}

	cout << cnt;

}
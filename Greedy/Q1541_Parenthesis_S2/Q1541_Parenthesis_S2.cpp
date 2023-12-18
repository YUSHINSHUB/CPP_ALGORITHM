#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {

	string in;
	cin >> in;
	int pos = 0;
	queue<int> q;
	int temp = 0;
	string t = "";
	int st = 0;


	while (pos < in.length()) {
		if (in[pos] == '-') break;
		if (in[pos] == '+') {
			st += stoi(t);
			t = "";
		}
		else {
			t += in[pos];
		}
		pos++;
	}

	if (pos == in.length()) cout << st + stoi(t);
	else {
		if (in[pos] == '-') {
			st += stoi(t);
			t = "";
		}
		pos++;

		for (int i = pos; i < in.length(); i++) {
			if (in[i] == '+') {
				temp += stoi(t);
				t = "";
			}
			else if (in[i] == '-') {
				temp += stoi(t);
				t = "";
				q.push(temp);
				temp = 0;
			}
			else {
				t += in[i];
			}
		}
		if (t != "") temp += stoi(t);
		q.push(temp);

		while (!q.empty()) {
			st -= q.front();
			q.pop();
		}

		cout << st;
	}

}
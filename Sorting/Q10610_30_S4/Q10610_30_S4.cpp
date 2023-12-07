#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string str;
	cin >> str;

	sort(str.begin(), str.end(), greater<>());

	int cnt = 0;
	int t = 0;
	string temp = "";

	while (cnt + 6 < str.length()) {
		temp += str.substr(cnt, 6);
		t = stoi(temp);
		t %= 30;
		if (t == 0) temp = "";
		else temp = to_string(t);
		cnt += 6;
	}

	temp += str.substr(cnt);
	t = stoi(temp);
	t %= 30;

	if (t == 0) cout << str;
	else cout << "-1";
}

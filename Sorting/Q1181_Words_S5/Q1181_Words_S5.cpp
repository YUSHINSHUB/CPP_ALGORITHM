#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main() {

	int n;
	cin >> n;
	vector<string> in(n);

	for (int i = 0; i < n; i++) cin >> in[i];

	set<string> temp(begin(in), end(in));

	in.assign(begin(temp), end(temp));

	sort(begin(in), end(in), [](string o1, string o2) -> bool {
		if (o1.length() == o2.length()) {
			for (int i = 0; i < o1.length(); i++) {
				if (o1[i] != o2[i]) return o1 < o2;
			}
		}
		return o1.length() < o2.length();
		});

	for (int i = 0; i < in.size(); i++) {
		cout << in[i] << "\n";
	}


}
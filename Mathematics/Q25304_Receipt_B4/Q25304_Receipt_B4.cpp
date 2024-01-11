#include <iostream>

using namespace std;
int main() {

	int n;
	int fee;

	cin >> fee >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		res += a * b;
	}
	if (res == fee) cout << "Yes";
	else cout << "No";

}
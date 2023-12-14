#include <iostream>

using namespace std;


int main() {

	int n;
	cin >> n;

	int fl, ro, cl;
	int res = 0;

	for (int i = 0; i < n; i++) {
		cin >> fl >> ro >> cl;

		if (cl % fl == 0) res = fl * 100 + (cl / fl);
		else res = (cl % fl) * 100 + (cl / fl) + 1;


		cout << res << "\n";
	}

}
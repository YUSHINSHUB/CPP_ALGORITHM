#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t, n, m;
	cin >> t;
	string inp;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cin.ignore();
		for (int j = 0; j < m; j++)
			getline(cin, inp);
		cout << (n - 1) << "\n";
	}
}
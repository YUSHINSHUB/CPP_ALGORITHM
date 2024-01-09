#include <iostream>
using namespace std;

int main()
{
	int n;
	int out = 0;
	string in;
	cin >> n >> in;

	for (int i = 0; i < n; i++) {
		out += in[i] - '0';
	}

	cout << out;

}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a;
	cin >> b;
	cin >> c;

	int res = a * b * c;

	string str = to_string(res);
	int arr[10] = {};


	for (char ch : str) {
		++arr[ch - '0'];
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

}
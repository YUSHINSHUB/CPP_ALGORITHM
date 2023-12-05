#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main()
{
	int temp;
	for (int i = 0; i < 3; i++) {
		int res = 0;
		for (int j = 0; j < 4; j++) {
			cin >> temp;
			res += temp;
		}
		switch (res) {
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
	}
}
#include <iostream>

using namespace std;

int main()
{
	int rig[6] = { 1, 1, 2, 2, 2, 8 };

	int inp[6];

	for (int i = 0; i < 6; i++) {
		cin >> inp[i];
		cout << rig[i] - inp[i] << " ";
	}


}
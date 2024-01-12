#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	while (true) {

		int len[3];
		cin >> len[0] >> len[1] >> len[2];

		if (len[0] == len[1] && len[0] == len[2] && len[0] == 0)
			break;

		sort(len, len + 3);

		if (len[0] + len[1] <= len[2])
			cout << "Invalid\n";
		else if (len[0] == len[1] && len[0] == len[2])
			cout << "Equilateral\n";
		else if (len[0] == len[1] || len[0] == len[2] || len[1] == len[2])
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}
}
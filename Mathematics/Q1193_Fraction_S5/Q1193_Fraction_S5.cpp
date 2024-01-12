#include <iostream>

using namespace std;
int main()
{

	int goal;
	cin >> goal;
	int cnt = 0;
	int idx = 1;

	int a, b;
	bool end = false;

	while (1) {

		idx++;


		for (int i = 1; i < idx; i++) {
			b = i;
			a = idx - i;
			cnt++;
			if (cnt == goal) {
				end = true;
				break;
			}
		}


		if (end) break;

		idx++;
		a = 1;
		b = idx - 1;
		for (int i = 1; i < idx; i++) {
			a = i;
			b = idx - i;
			cnt++;
			if (cnt == goal) {
				end = true;
				break;
			}
		}

		if (end) break;

	}

	cout << a << "/" << b;


}

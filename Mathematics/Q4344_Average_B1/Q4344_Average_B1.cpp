#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int c;
	double n;
	cin >> c;
	double sum;
	double sco[1000];

	for (int i = 0; i < c; i++) {
		sum = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> sco[j];
			sum += sco[j];
		}
		sum /= n;
		double cnt = 0;
		for (int j = 0; j < n; j++) {
			if (sum < sco[j]) cnt++;
		}

		cout.precision(3);
		cout << fixed << round(((double)100 / n * cnt) * 1000) / 1000 << "%\n";
	}
}
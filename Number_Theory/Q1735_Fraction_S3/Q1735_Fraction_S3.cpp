
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int fden, ffra, sden, sfra;

	cin >> fden >> ffra >> sden >> sfra;

	int hi = max(ffra, sfra);
	int lo = min(ffra, sfra);

	if (hi == ffra) {
		while (hi % ffra != 0 || hi % sfra != 0) hi += ffra;
	}
	else {
		while (hi % ffra != 0 || hi % sfra != 0) hi += sfra;
	}

	fden *= hi / ffra;
	sden *= hi / sfra;

	fden += sden;

	for (int i = 2; i <= min(fden, hi); i++) {
		if (fden % i == 0 && hi % i == 0) {
			fden /= i;
			hi /= i;
			i = 1;
		}
	}

	cout << fden << " " << hi;

}
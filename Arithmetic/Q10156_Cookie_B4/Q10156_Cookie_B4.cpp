#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {


	int price, entity, balance;
	int mtoget;

	cin >> price >> entity >> balance;

	mtoget = (price * entity) - balance;

	if (mtoget >= 0) {
		cout << mtoget;
	}
	else {
		cout << 0;
	}


}
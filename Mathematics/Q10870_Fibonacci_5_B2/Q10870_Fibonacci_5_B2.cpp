#include <iostream>

using namespace std;


int main() {

	int fib[21];
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= 20; i++) fib[i] = fib[i - 1] + fib[i - 2];

	int n;
	cin >> n;

	cout << fib[n];

}
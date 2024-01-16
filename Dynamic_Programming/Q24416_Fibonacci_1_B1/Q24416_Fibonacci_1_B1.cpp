#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 0;
int cnt2 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt1++;
		return 1;  // 코드1
	}
	else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	vector<int>f(n + 1);
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		cnt2++;
		f[i] = f[i - 1] + f[i - 2];  // 코드2
	}
	return f[n];
}

int main() {

	int n;
	cin >> n;
	fib(n);
	fibonacci(n);

	cout << cnt1 << " " << cnt2;
}
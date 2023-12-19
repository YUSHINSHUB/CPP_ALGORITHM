#include <iostream>
using namespace std;

static int fac[1001];

static int getFac(int n) {

	if (fac[n] < 0) {
		if (fac[n - 1] < 0)
			fac[n] = (getFac(n - 1) * n) % 10007;
		else
			fac[n] = (fac[n - 1] * n) % 10007;
	}

	return fac[n];
}

int main()
{
	int n, k;
	cin >> n >> k;

	fill(fac, fac + 1001, -1);
	fac[0] = 1;

	// 페르마의 소정리에 의해 P가 소수라는 전제 하에 (A/B) % P = ( (A%P) * (B^(P-2)%P) ) % P 가 성립한다.
	// nCk % 10007 = ( n! / ( n-k )! * k! ) % 10007
	// = ( (n! % 10007) * ( ( n-k )! * k! )^10005 % 10007 ) ) % 10007와 같다.
	int fa = (getFac(n));
	int fb = (getFac(n - k) * getFac(k)) % 10007;

	int idx = 10005;
	int cur = 2;
	int kfac[10006];
	fill(kfac, kfac + 10006, -1);
	kfac[1] = fb % 10007;
	int div = 1;

	// 모듈로 연산의 분배법칙을 활용하여 거듭제곱의 나머지는 빠르게 구할 수 있다.
	// https://ko.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation
	// 참고

	while (idx > 0) {

		if (cur > idx) {
			cur /= 2;
			idx -= cur;
			div = (div * kfac[cur]) % 10007;
			cur = 1;
		}

		if (kfac[cur] < 0)
			kfac[cur] = (kfac[cur / 2] * kfac[cur / 2]) % 10007;

		cur *= 2;
	}

	int res = (fa * div) % 10007;

	cout << res;
}

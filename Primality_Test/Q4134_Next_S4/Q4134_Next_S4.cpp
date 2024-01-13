#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	// 소수가 아닌 수는 소수의 배수이다. 또한 n의 소수여부를 확인하기 위해 하나하나 나누어 보는 방식을 행할 때에는
	// n-1까지 모두 나눠볼 필요 없이 2부터 소숫점을 버린 n의 제곱근 까지만 나누어 보아도 된다.
	// 최댓값인 40억의 제곱근이 63245.553...임을 이용해서 배열에 63246 이하의 모든 소수를 저장해서 이용한다.
	vector<int> prime;
	int pri[63247];
	fill(pri, pri + 63247, 0);
	pri[1] = 1;
	prime.push_back(2);
	for (int i = 4; i < 63247; i += 2) {
		pri[i] = 1;
	}

	for (int i = 3; i < 63247; i += 2) {
		if (pri[i] == 0) {
			prime.push_back(i);
			for (int j = i * 2; j < 63247; j += i)
				pri[i] = 1;
		}
	}

	for (int i = 0; i < t; i++) {
		long long n;
		cin >> n;
		if (n < 2)
			n = 2;
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] > sqrt(n))
				break;
			if (n % prime[j] == 0) {
				j = -1;
				n++;
			}
		}
		cout << n << "\n";
	}
}
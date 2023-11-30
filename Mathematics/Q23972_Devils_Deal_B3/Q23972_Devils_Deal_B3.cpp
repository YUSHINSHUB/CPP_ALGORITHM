/*
commented by ChatGPT
This C++ code calculates the smallest integer res for given N and K values where res * (K - 1) is greater than or equal to N * K.
If K is equal to 1, the code outputs -1, indicating that it is not possible to find a valid res.
The code ensures res is the smallest possible value meeting the condition.
It checks if (N * K) % (K - 1) is zero; if not, res is computed as ((N * K) / (K - 1)) + 1, else it is (N * K) / (K - 1).
This approach finds the minimum number of elements needed to achieve a sum equal to or greater than N * K.

이 C++ 코드는 주어진 N과 K 값에 대해 res * (K - 1)이 N * K보다 크거나 같은 가장 작은 정수 res를 계산합니다. K가 1과 같으면, 유효한 res를 찾을 수 없으므로 코드는 -1을 출력합니다.
코드는 res가 조건을 만족하는 가능한 가장 작은 값이 되도록 합니다.
(N * K) % (K - 1)이 0이 아닌 경우, res는 ((N * K) / (K - 1)) + 1로 계산되며, 0인 경우 res는 (N * K) / (K - 1)로 계산됩니다.
이 방법은 N * K와 같거나 큰 합을 달성하기 위해 필요한 최소 원소 수를 찾습니다.
*/

#include <iostream>

using namespace std;

int main() {
	long long N, K; // N과 K 변수 선언
	long long res; // 결과값을 저장할 변수

	cin >> N >> K; // 입력값을 받아 N과 K에 할당

	// K가 1인 경우, 유효한 res 값을 찾을 수 없으므로 -1 출력
	if (K == 1) {
		cout << "-1";
	}
	else {
		// res 값을 계산
		if ((N * K) % (K - 1) != 0) // N * K가 K - 1로 나누어 떨어지지 않으면 1을 더해줌
			res = ((N * K) / (K - 1)) + 1;
		else // 나누어 떨어지면 그대로 계산
			res = (N * K) / (K - 1);

		cout << res; // 결과값 출력
	}
}
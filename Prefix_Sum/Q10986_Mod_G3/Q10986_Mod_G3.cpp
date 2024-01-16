/*
commented by ChatGPT
This C++ code calculates the number of subarrays in an array that sum to a multiple of M. It takes N (the size of the array) and M as inputs, and then it reads the array elements. The main logic involves tracking the cumulative sum modulo M and utilizing a combination function to count the number of valid subarrays where the sum is divisible by M.
이 C++ 코드는 배열 내에서 합이 M의 배수인 서브 배열의 수를 계산합니다. 배열의 크기인 N과 M을 입력으로 받은 후, 배열의 요소를 읽습니다. 주요 로직은 누적 합을 M으로 나눈 나머지를 추적하고 조합 함수를 사용하여 합이 M으로 나누어 떨어지는 유효한 서브 배열의 수를 계산하는 것입니다.
*/

#include <iostream>

typedef long long ll; // Use long long for larger numbers (큰 숫자에 대해서는 long long 사용)
using namespace std;

// Function to calculate nCr (조합을 계산하는 함수)
ll combination(int n, int r) {
	ll out = 1;
	// Calculate n! / (n-r)! part (n! / (n-r)! 부분을 계산)
	for (int i = n - r + 1; i <= n; i++) {
		out *= i;
	}
	// Divide by r! (r!로 나누기)
	for (int i = 2; i <= r; i++) {
		out /= i;
	}
	return out;
}

int main() {
	int N, M;
	cin >> N >> M; // Read the values for N and M (N과 M의 값을 읽기)

	int sum = 0; // Sum of elements modulo M (요소들의 합의 모듈로 M)
	long res = 0; // Number of subarrays with sum divisible by M (합이 M으로 나누어 떨어지는 서브 배열의 수)

	// Array to keep track of modulo counts (모듈로 카운트를 추적하는 배열)
	int cnt[1000];
	fill(cnt, cnt + M, 0); // Initialize counts to 0 (카운트를 0으로 초기화)

	// Read array elements (배열 요소 읽기)
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp; // Read each element (각 요소 읽기)
		sum = (sum + temp) % M; // Update sum modulo M (합 모듈로 M 업데이트)
		cnt[sum]++; // Increment count for this sum (이 합에 대한 카운트 증가)
	}

	// Add the number of subarrays starting at the beginning (시작점에서 서브 배열의 수 추가)
	res += cnt[0];
	for (int i = 0; i < M; i++) {
		if (cnt[i] > 1) {
			res += combination(cnt[i], 2); // Add combinations of counts (카운트의 조합 추가)
		}
	}

	cout << res; // Output the result (결과 출력)
}


/*
commented by ChatGPT
This C++ code implements a binary search algorithm to find the kth smallest number in an N×N multiplication table. The algorithm starts with the low set to 1 and hig set to k.
The mid value is initially set to the average of low and hig. The code enters a loop, where it calculates the count of numbers in the multiplication table less than or equal to mid.
This count is compared with k. If the count is less than k, low is set to mid + 1, narrowing the search to higher numbers.
If the count is greater than or equal to k, res is updated with mid, and hig is set to mid - 1, narrowing the search to lower numbers.
The loop continues until low is greater than hig, at which point res contains the kth smallest number in the multiplication table.
이 C++ 코드는 N×N 곱셈 테이블에서 k번째로 작은 숫자를 찾기 위한 이진 탐색 알고리즘을 구현합니다. 알고리즘은 low를 1로, hig를 k로 설정하여 시작합니다.
mid 값은 처음에 low와 hig의 평균으로 설정됩니다. 코드는 곱셈 테이블에서 mid 이하의 숫자 개수를 계산하는 루프에 진입합니다. 이 개수는 k와 비교됩니다.
개수가 k보다 작으면 low는 mid + 1로 설정되어, 더 높은 숫자에 대한 검색 범위를 좁힙니다.
개수가 k 이상이면 res는 mid로 업데이트되고, hig는 mid - 1로 설정되어, 더 낮은 숫자에 대한 검색 범위를 좁힙니다.
low가 hig보다 커질 때까지 루프가 계속되며, 이 시점에서 res는 곱셈 테이블에서 k번째로 작은 숫자를 포함합니다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N, k; // N: 곱셈 테이블의 크기, k: 찾고자 하는 숫자의 순서
	int low, mid, hig; // 이진 탐색을 위한 변수: low, mid, hig
	int res = 0; // 결과값을 저장할 변수

	cin >> N >> k; // N과 k 입력 받기

	low = 1;
	hig = k;
	mid = (low + hig) / 2;

	while (true) {
		if (low > hig)
			break;
		mid = (low + hig) / 2;

		int temp = 0; // mid 이하의 숫자 개수를 저장할 변수
		for (int i = 1; i <= N; i++) {
			temp += min(mid / i, N);
			if (temp > k)
				break;
		}

		// 이진 탐색 범위 조정
		if (temp < k) {
			low = mid + 1;
		}
		else {
			res = mid;
			hig = mid - 1;
		}
	}

	cout << res; // 결과 출력
}
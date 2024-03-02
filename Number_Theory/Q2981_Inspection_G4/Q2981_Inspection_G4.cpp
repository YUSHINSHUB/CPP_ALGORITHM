/*
commented by ChatGPT
이 C++ 코드는 상근이가 경찰의 검문을 받을 때 시간을 때우기 위해 했던 게임의 해결법을 구현한 것입니다.
상근이는 N개의 숫자들 중에서 특정한 규칙을 만족하는 수 M을 찾고자 합니다.
N개의 숫자들을 M으로 나누었을 때 나머지가 모두 같게 되는 M을 찾아야 합니다. M은 1보다 커야 합니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int>cards(n);
	vector<int> nums(n - 1);

	// N개의 숫자를 입력 받는다.
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	// 숫자들을 정렬한다.
	sort(cards.begin(), cards.end());

	// 연속된 숫자들 사이의 차이를 계산한다.
	for (int i = 1; i < n; i++) {
		nums[i - 1] = cards[i] - cards[i - 1];
	}

	sort(nums.begin(), nums.end());

	bool out = true;

	int gdc = 0;

	// 가능한 M의 값들 중 최대공약수를 찾는다.
	for (int j = nums[0]; j >= 0; j--) {
		out = true;
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] % j != 0) {
				out = false;
				break;
			}
		}
		if (out) {
			gdc = j;
			break;
		}
	}

	// 최대공약수의 약수들을 찾아 출력한다. (단, sqrt(gdc) 미만의 값들)
	for (int i = 2; i < sqrt(gdc); i++) {
		if (gdc % i == 0) cout << i << " ";
	}

	// sqrt(gdc) 이상의 최대공약수의 약수들을 찾아 출력한다.
	for (int i = (int)sqrt(gdc); i >= 1; i--) {
		if (gdc % i == 0) cout << gdc / i << " ";
	}

	// 최대공약수의 약수를 찾는 효율적인 방법을 사용한다.
}
